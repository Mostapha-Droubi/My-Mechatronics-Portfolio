# AquaGuard: Smart Water Management System

The AquaGuard Smart Water System is an IoT-enabled solution designed to automate water level monitoring, pump control, and leak detection. This repository contains the complete hardware design, manufacturing files, documentation, and firmware source code.


## 📁 Repository Structure
* **/Hardware**: EasyEDA project files, schematic data, and PCB layout sources.
* **/Documentation**: Project reports, high-resolution renders, and technical documentation.
* **/Manufacturing**: Production-ready Gerber files (`gerbers.zip`) and Bill of Materials (`bom.csv`).
* **/Firmware**: Source code for ESP8266 and Arduino integration.

##  Key Specifications
* **Controller**: ATmega328P / Arduino Uno R3.
* **Connectivity**: ESP8266 Wi-Fi module (Blynk IoT integration).
* **PCB Design**: 2-layer FR-4 board, optimized for noise reduction and high-current relay switching.
* **Project Status**: Completed / Fabrication Ready.

## 🛠 Usage
1.  **Hardware Fabrication**: Use the files in `/Manufacturing` to order the PCB from your preferred fabrication house.
2.  **Assembly**: Refer to the `/Hardware` schematics for component placement.
3.  **Firmware Deployment**: Open the `.ino` files in the `/Firmware` folder using the Arduino IDE and configure your network credentials.

## 📝 License
This project is licensed under the **CERN Open Hardware Licence Version 2 - Permissive**.

---
*Developed by [Mostapha Droubi]*
