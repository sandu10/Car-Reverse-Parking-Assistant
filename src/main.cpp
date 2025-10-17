#include <Arduino.h>

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Initialize LCD (address 0x27, 16x2)
LiquidCrystal_I2C lcd(0x27, 16, 2);

#define TRIG_PIN 9
#define ECHO_PIN 10
#define YELLOW_LED 6
#define RED_LED 7
#define BUZZER 8

long duration;
int distance;

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Reverse Assist");
  delay(1500);
  lcd.clear();
}

void loop() {
  // Send ultrasonic pulse
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Measure the echo time
  duration = pulseIn(ECHO_PIN, HIGH);
  distance = duration * 0.034 / 2; // Convert to cm

  // Display distance
  lcd.setCursor(0, 0);
  lcd.print("Distance: ");
  lcd.print(distance);
  lcd.print(" cm   ");

  // Check distance range
  if (distance > 20) {
    // Safe
    lcd.setCursor(0, 1);
    lcd.print("Status: SAFE     ");
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(RED_LED, LOW);
    tone(BUZZER, LOW);
  } 
  else if (distance > 10 && distance <= 20) {
    // Nearby
    lcd.setCursor(0, 1);
    lcd.print("Status: NEARBY   ");
    digitalWrite(YELLOW_LED, HIGH);
    digitalWrite(RED_LED, LOW);
    tone(BUZZER, LOW);
  } 
  else if (distance <= 10) {
    // Very Close
    lcd.setCursor(0, 1);
    lcd.print("Status: CLOSE!!! ");
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(RED_LED, HIGH);
    tone(BUZZER, 1000);
  }

  delay(200); // small delay for stability
}

