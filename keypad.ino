#include <Keypad.h>

const byte ROWS = 4; // Four rows
const byte COLS = 3; // Three columns

// Defines the symbols on the buttons of the keypad
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

// Connect to the row pinouts of the keypad
byte rowPins[ROWS] = {9, 8, 7, 6};

// Connect to the column pinouts of the keypad
byte colPins[COLS] = {12, 11, 10};

// Initialize an instance of the Keypad class
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup() {
  // Start serial communication for viewing output
  Serial.begin(9600);
}

void loop() {
  // Get the key that is currently pressed
  char customKey = customKeypad.getKey();

  // If a key is pressed, print it to the Serial Monitor
  if (customKey) {
    Serial.println(customKey);
  }
}