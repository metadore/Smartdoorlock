#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#include "LedControl.h"

// Hardware Pins
const int TRIG_PIN = 4, ECHO_PIN = 5, BUZZER_PIN = 8, SERVO_PIN = 9;
const int DIN_PIN = 12, CS_PIN = 10, CLK_PIN = 13;

LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo myServo;
LedControl lc = LedControl(DIN_PIN, CLK_PIN, CS_PIN, 1);

// Security Settings
String secretPin = "1234"; 
int wrongAttempts = 0;
const int MAX_ATTEMPTS = 3;

// Matrix Patterns
byte faceHappy[8] = {0x3C,0x42,0xA5,0x81,0xA5,0x99,0x42,0x3C};
byte faceLocked[8] = {0x3C,0x42,0x81,0x81,0x81,0x81,0x42,0x3C};
byte faceAngry[8]  = {0x81,0x42,0x24,0x18,0x18,0x24,0x42,0x81}; // "X" Pattern

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  myServo.attach(SERVO_PIN);
  myServo.write(0); // Start Locked
  
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  
  lc.shutdown(0, false);
  lc.setIntensity(0, 5);
  
  lcd.print("SECURE BOOT...");
  delay(1500);
  showLockedScreen();
}

void loop() {
  // 1. OUTSIDE ACCESS (Serial Monitor PIN)
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    input.trim();
    
    if (input == secretPin) {
      wrongAttempts = 0; // Reset counter on success
      accessGranted("PIN ACCEPTED");
    } else {
      wrongAttempts++;
      playBadTone();
      if (wrongAttempts >= MAX_ATTEMPTS) {
        triggerLockout();
      } else {
        lcd.clear();
        lcd.print("WRONG PIN!");
        lcd.setCursor(0,1);
        lcd.print("ATTEMPT: "); lcd.print(wrongAttempts);
        delay(2000);
        showLockedScreen();
      }
    }
  }

  // 2. INSIDE ACCESS (Ultrasonic Wave)
  if (getDistance() > 2 && getDistance() < 15) {
    accessGranted("EXIT WAVE");
  }
}

long getDistance() {
  digitalWrite(TRIG_PIN, LOW); delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH); delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  return (pulseIn(ECHO_PIN, HIGH) / 2) / 29.1;
}

void accessGranted(String msg) {
  lcd.clear();
  lcd.print("ACCESS GRANTED");
  lcd.setCursor(0,1);
  lcd.print(msg);
  
  for(int i=0; i<8; i++) lc.setRow(0, i, faceHappy[i]); // Smiley
  playSuccessMusic();
  
  myServo.write(90); // Move Servo to Unlock
  delay(5000);       // Wait 5 seconds
  
  myServo.write(0);  // Relock
  showLockedScreen();
}

void triggerLockout() {
  lcd.clear();
  lcd.print("SYSTEM LOCKED!");
  lcd.setCursor(0,1);
  lcd.print("WAIT 30 SECONDS");
  
  for(int i=0; i<8; i++) lc.setRow(0, i, faceAngry[i]); // Show X
  
  for(int i=0; i<10; i++) { // Alarm sound
    tone(BUZZER_PIN, 200, 200); delay(300);
    tone(BUZZER_PIN, 150, 200); delay(300);
  }
  
  delay(20000); // Remaining lockout time
  wrongAttempts = 0;
  showLockedScreen();
}

void showLockedScreen() {
  lcd.clear();
  lcd.print("ENTER PIN:");
  lcd.setCursor(0,1);
  lcd.print("OR WAVE TO EXIT");
  for(int i=0; i<8; i++) lc.setRow(0, i, faceLocked[i]);
}

void playSuccessMusic() {
  int melody[] = {440, 523, 659, 880}; 
  for (int i = 0; i < 4; i++) {
    tone(BUZZER_PIN, melody[i], 100);
    delay(150);
  }
}

void playBadTone() {
  tone(BUZZER_PIN, 100, 500); // Low, long buzzing sound
}