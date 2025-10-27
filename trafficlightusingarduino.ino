#include <LiquidCrystal.h>

// --- Pin Definitions for LEDs (Corrected to match the schematic) ---
const int greenLedPin = 4;
const int yellowLedPin = 3;
const int redLedPin = 2;

// --- Pin Definitions for LCD (Matches your code and schematic) ---
// LiquidCrystal(rs, en, d4, d5, d6, d7)
LiquidCrystal lcd(9, 8, 13, 12, 11, 10);

void setup() {
  // Set all LED pins as outputs
  pinMode(greenLedPin, OUTPUT);
  pinMode(yellowLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);

  // Initialize the LCD with 16 columns and 2 rows
  lcd.begin(16, 2);

  // Display a startup message
  lcd.print("Traffic Light");
  lcd.setCursor(0, 1);
  lcd.print("System Starting");
  delay(2000);
}

void loop() {
  // --- STATE 1: GREEN LIGHT ---
  digitalWrite(greenLedPin, HIGH);
  digitalWrite(yellowLedPin, LOW);
  digitalWrite(redLedPin, LOW);

  lcd.clear();
  lcd.setCursor(0, 0); // Go to first line
  lcd.print("GO");
  lcd.setCursor(0, 1); // Go to second line
  lcd.print("Green Light ON");
  delay(5000); // Green light on for 5 seconds

  // --- STATE 2: YELLOW LIGHT ---
  digitalWrite(greenLedPin, LOW);
  digitalWrite(yellowLedPin, HIGH);
  digitalWrite(redLedPin, LOW);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("SLOW DOWN");
  lcd.setCursor(0, 1);
  lcd.print("Yellow Light ON");
  delay(2000); // Yellow light on for 2 seconds

  // --- STATE 3: RED LIGHT ---
  digitalWrite(greenLedPin, LOW);
  digitalWrite(yellowLedPin, LOW);
  digitalWrite(redLedPin, HIGH);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("STOP");
  lcd.setCursor(0, 1);
  lcd.print("Red Light ON");
  delay(5000); // Red light on for 5 seconds
}