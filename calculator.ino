#include <Keypad.h>
#include <LiquidCrystal.h>

// --- Keypad Configuration ---
const byte ROWS = 4; // Four rows
const byte COLS = 4; // Four columns

// Define the keypad layout (matches a standard calculator)
char keys[ROWS][COLS] = {
  {'7', '8', '9', '/'},
  {'4', '5', '6', '*'},
  {'1', '2', '3', '-'},
  {'C', '0', '=', '+'}
};

// Connect keypad row pins to Arduino pins (matches your schematic)
byte rowPins[ROWS] = {0, 1, 2, 3};
// Connect keypad column pins to Arduino pins (matches your schematic)
byte colPins[COLS] = {4, 5, 6, 7};

// Initialize the keypad object
Keypad kpd = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// --- LCD Configuration (matches your schematic) ---
// LiquidCrystal(rs, en, d4, d5, d6, d7)
LiquidCrystal lcd(8, 9, 10, 11, 12, 13);

// --- Calculator Logic Variables ---
String num1, num2;    // To store the first and second numbers
char action;          // To store the operator (+, -, *, /)
boolean isFirstNumber = true; // Flag to check if we are inputting the first number
boolean isResultShown = false; // Flag to check if a result is on the screen

// --- Function to clear all data and reset the calculator ---
void clearData() {
  num1 = "";
  num2 = "";
  isFirstNumber = true;
  isResultShown = false;
  lcd.clear();
}

void setup() {
  lcd.begin(16, 2); // Initialize the 16x2 LCD
  lcd.print("Arduino Calc");
  lcd.setCursor(0, 1);
  lcd.print("Ready...");
  delay(1500);
  lcd.clear();
}

void loop() {
  char key = kpd.getKey(); // Read the pressed key

  if (key) { // If a key is pressed
    // If a result is already shown, any key press will clear for a new calculation
    if (isResultShown) {
      clearData();
    }

    // --- Handle Number Keys ('0' through '9') ---
    if (key >= '0' && key <= '9') {
      if (isFirstNumber) {
        num1 += key; // Append digit to the first number
      } else {
        num2 += key; // Append digit to the second number
      }
      lcd.print(key); // Display the pressed digit
    }

    // --- Handle Operator Keys ('/', '*', '-', '+') ---
    else if (key == '/' || key == '*' || key == '-' || key == '+') {
      if (num1.length() > 0) { // Only accept an operator after the first number
        action = key;
        isFirstNumber = false; // Switch to inputting the second number
        lcd.print(key);
      }
    }

    // --- Handle Equals Key ('=') ---
    else if (key == '=') {
      if (num1.length() > 0 && num2.length() > 0) {
        float number1 = num1.toFloat();
        float number2 = num2.toFloat();
        float result = 0;

        switch (action) {
          case '+': result = number1 + number2; break;
          case '-': result = number1 - number2; break;
          case '*': result = number1 * number2; break;
          case '/': result = number1 / number2; break;
        }

        lcd.setCursor(0, 1); // Move to the second line for the result
        lcd.print("= ");
        lcd.print(result);
        isResultShown = true;
      }
    }

    // --- Handle Clear Key ('C') ---
    else if (key == 'C') {
      clearData();
    }
  }
}