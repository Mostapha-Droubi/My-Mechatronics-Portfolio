#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
int buttonValue;
#define BUTTON_PIN 2  // The ESP8266 pin D7 connected to button

#define readyLed 3
#define progressLed 4

#define requestPin 10
#define confirmedPin 11

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(readyLed, OUTPUT);
  pinMode(progressLed, OUTPUT);
  digitalWrite(readyLed, HIGH);
  digitalWrite(progressLed, LOW);

  lcd.init();
  lcd.backlight();
  Serial.begin(9600);

  pinMode(requestPin, OUTPUT);
  pinMode(confirmedPin, OUTPUT);

  digitalWrite(requestPin, LOW);
  digitalWrite(confirmedPin, LOW);
}

void loop() {
   digitalWrite(requestPin, LOW);
  digitalWrite(confirmedPin, LOW);
  screenPage(1);
  digitalWrite(readyLed, HIGH);
  digitalWrite(progressLed, LOW);
  buttonFunction();
  ///////////////////////////////send we need a driver
  digitalWrite(requestPin, HIGH);
  digitalWrite(confirmedPin, LOW);


  digitalWrite(readyLed, LOW);
  digitalWrite(progressLed, HIGH);
  screenPage(2);
  buttonFunction();
  screenPage(3);
  buttonFunction();
  ///////////////////////////////////send confirmed with buzzer
  digitalWrite(requestPin, LOW);
  digitalWrite(confirmedPin, HIGH);

  digitalWrite(readyLed, HIGH);
  digitalWrite(progressLed, LOW);

 
  screenPage(4);
  delay(2000);
}

void buttonFunction() {
  buttonValue = digitalRead(BUTTON_PIN);
  while (buttonValue == HIGH) {
    buttonValue = digitalRead(BUTTON_PIN);
    if (buttonValue == LOW) {
      while (digitalRead(BUTTON_PIN) == LOW) {}
    }
    delay(2);
  }
}

void screenPage(int stage) {

  lcd.clear();
  if (stage == 1) {
    lcd.setCursor(0, 0);
    lcd.print(" Press btn ");
    lcd.setCursor(0, 1);
    lcd.print("to call driver");
  } else if (stage == 2) {
    lcd.setCursor(0, 0);
    lcd.print("Driver on his way");
    lcd.setCursor(0, 1);
    lcd.print("press once arrive");
  } else if (stage == 3) {
    lcd.setCursor(0, 0);
    lcd.print("press to comfirm");
    lcd.setCursor(0, 1);
    lcd.print("that he arrived");
  } else if (stage == 4) {
    lcd.setCursor(0, 0);
    lcd.print("thank you for the");
    lcd.setCursor(0, 1);
    lcd.print("test in DTDS");
  }
}