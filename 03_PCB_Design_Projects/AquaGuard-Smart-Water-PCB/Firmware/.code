# AquaGuard System Firmware

This directory contains the source code for the AquaGuard Smart Water Management System. The system utilizes a master/slave architecture for IoT connectivity and sensor data processing.

## Firmware Architecture
* **Main Controller**: Arduino Uno R3 (Handles sensors, relay control, and local LCD display).
* **IoT Module**: ESP8266 (Manages Wi-Fi connectivity and communication with the Blynk IoT platform).

## Requirements
* **IDE**: Arduino IDE 2.x or higher.
* **Libraries**: 
    * `BlynkSimpleEsp8266.h`
    * `LiquidCrystal_I2C.h`
    * `NewPing.h` (for ultrasonic sensors)
* **Board Settings**: 
    * For ESP8266: Select "Generic ESP8266 Module".
    * For Arduino: Select "Arduino Uno".

## Installation Steps
1. Open the `.ino` file in the Arduino IDE.
2. Install all required dependencies from the Library Manager.
3. Update the `BLYNK_AUTH_TOKEN`, `WIFI_SSID`, and `WIFI_PASS` in the configuration section of the code.
4. Compile and upload the code to the respective microcontrollers.

## Communication Protocol
The Arduino and ESP8266 communicate via SoftwareSerial, exchanging system status data to ensure the Blynk dashboard reflects real-time water levels and leak alerts.
