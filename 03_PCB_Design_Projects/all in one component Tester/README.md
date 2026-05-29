# All-in-One Component Tester

An advanced, standalone diagnostic tool for identifying and measuring electronic components. Designed around the ATmega328P microcontroller, this device provides precise measurements for resistors, capacitors, diodes, and transistors.



## 📋 Project Overview
This project is an automated testing platform capable of identifying component types, pinouts, and values. It features a robust power management stage and an optimized analog sensing circuit to ensure measurement accuracy.

## 🛠 Engineering Features
* **Component Identification**: Automatically detects BJT transistors, MOSFETs, diodes, resistors, and capacitors.
* **Precise Measurement**: Utilizes the ATmega328P's ADC (Analog-to-Digital Converter) coupled with a stable 5V reference.
* **Double-Layer PCB**: Engineered with a dedicated ground plane to minimize electromagnetic interference and parasitic resistance during low-current measurements.
* **Self-Contained Power**: 12V DC input with reverse polarity protection and efficient linear regulation.

## 📂 Repository Structure
* [/Hardware](Hardware/): Contains the native project file (`.epcb`) for EasyEDA Pro.
* [/Manufacturing](Manufacturing/): Contains fabrication-ready Gerber files (`gerbers.zip`) and the Bill of Materials (`bom.csv`).
* [/Documentation](Documentation/): Contains the circuit schematic (PDF), visual 3D renders, and technical theory behind component measurement.

## 🚀 Key Specifications
| Feature | Specification |
| :--- | :--- |
| **Microcontroller** | ATmega328P |
| **Input Voltage** | 12V DC |
| **Measurement Mode** | Automated ADC polling |
| **PCB Construction** | Double-Layer, FR-4 |
| **Programming** | ICSP Header |

---
*Developed by Mostapha Droubi | 2026*
