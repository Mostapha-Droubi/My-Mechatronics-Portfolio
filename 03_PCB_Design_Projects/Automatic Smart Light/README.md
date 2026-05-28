# Automatic Smart Light Controller

An automated lighting system designed to turn a lamp ON in dark environments and OFF when sufficient ambient light is present. 



## 📋 Project Summary
[cite_start]This project demonstrates the design of a low-cost, automated light switch using a light-dependent resistor (LDR) to sense ambient light levels and a relay to control the lamp. [cite: 2, 13]

## 🛠 Engineering Principles
* [cite_start]**Light Sensing**: The circuit uses a voltage divider consisting of an LDR, a fixed 10KΩ resistor, and a 10KΩ potentiometer to calibrate sensitivity thresholds. [cite: 3, 11, 14]
* [cite_start]**Switching Logic**: A 2N2222A NPN transistor acts as an electronic switch, amplifying the small signal from the LDR divider to drive the 5V relay coil. [cite: 10, 76]
* [cite_start]**Protection**: A 1N4007 diode is included as a flyback diode to prevent back EMF from damaging the transistor when the relay switches off. [cite: 12]

## 📂 Repository Structure
* [/Hardware](Hardware/): Contains the native `.epcb` project file for EasyEDA Pro.
* [/Manufacturing](Manufacturing/): Contains fabrication files (`gerbers.zip`) and the Bill of Materials (`bom.csv`).
* [/Documentation](Documentation/): Contains the circuit schematic (PDF), PCB renders, and simulation references.

## 🚀 Key Specifications
| Component | Function |
| :--- | :--- |
| **LDR (GL5528)** | [cite_start]Senses ambient light levels [cite: 3, 19] |
| **Transistor (2N2222A)** | [cite_start]Acts as an electronic switch [cite: 3, 10] |
| **Relay (SRD-05VDC-SL-C)** | [cite_start]Switches the high-current lamp load [cite: 3, 12] |
| **Diode (1N4007)** | [cite_start]Flyback protection for the relay [cite: 3, 12] |

---
*Developed by Mostapha Droubi | 2026*
