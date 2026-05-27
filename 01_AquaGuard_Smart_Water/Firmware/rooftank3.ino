#include <Wire.h>
#include <RTClib.h>
#include <LiquidCrystal_I2C.h>

RTC_DS3231 rtc;
// Set the LCD address to 0x27 (common) and size 16x2
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  Wire.begin();

  // Initialize LCD
  lcd.init();
  lcd.backlight();

  if (!rtc.begin()) {
    Serial.println("⚠️ RTC not found!");
    lcd.setCursor(0,0);
    lcd.print("RTC not found!");
    while (1);
  }

  // ---- Set RTC time once ----
  // Uncomment the line below ONLY the first time you upload
  // rtc.adjust(DateTime(2025, 10, 30, 8, 38, 0));

  Serial.println("✅ RTC Ready!");
  lcd.setCursor(0,0);
  lcd.print("RTC Ready!");
}

void loop() {
  printTime();  // Call the function to print the current time
  delay(1000);
}

// Function to print time and date
void printTime() {
  DateTime now = rtc.now();

  // 12-hour format
  int hour = now.hour();
  char ampm[] = "AM";
  if (hour >= 12) {
    strcpy(ampm, "PM");
    if (hour > 12) hour -= 12;
  }
  if (hour == 0) hour = 12;

  // Format string
  char buffer[50];
  sprintf(buffer, "Time:%02d:%02d:%02d %s", hour, now.minute(), now.second(), ampm);

  char dateBuf[20];
  sprintf(dateBuf, "Date:%04d/%02d/%02d", now.year(), now.month(), now.day());

  // Print to Serial
  Serial.println(buffer);
  Serial.println(dateBuf);

  // Print to LCD
  lcd.setCursor(0,0);
  lcd.print(buffer);
  lcd.setCursor(0,1);
  lcd.print(dateBuf);
}
