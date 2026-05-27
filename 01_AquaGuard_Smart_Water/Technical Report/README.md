# AquaGuard: Technical Report

This directory contains the formal technical documentation for the AquaGuard system, documenting the research, design, and implementation phases of the Bachelor’s Technology Degree Thesis.

## Project Overview
The AquaGuard System (AGS) is an IoT-enabled water management solution designed to optimize residential and commercial water usage. It integrates real-time monitoring of water levels, quality (turbidity/pH), and flow to enable automated control and leak detection.

## Document Contents
* **[AquaGuard_Technical_Report.pdf](./AquaGuard_Technical_Report.pdf)**: The comprehensive thesis covering:
    * **System Architecture**: Detailed integration of Arduino Uno R3 and ESP8266 platforms.
    * **Calibration Logic**: Mathematical methodology for pH, turbidity, and ultrasonic sensor precision.
    * **Hardware & PCB Design**: Documentation of custom-built PCB control circuits and mechanical assembly.
    * **Performance Analysis**: Data-driven results comparing automated efficiency against manual management.

## Technical Specifications Summary
| Component | Function |
| :--- | :--- |
| **Microcontrollers** | Arduino Uno R3, ESP8266 NodeMCU |
| **IoT Platform** | Blynk Cloud & Mobile Application |
| **PCB Tools** | EasyEDA |
| **Communication** | Serial (Arduino-to-ESP8266), I2C, Wi-Fi/MQTT |

---
*Authored by: Mostapha Mohammad Droubi*
*Supervised by: Eng. Abdelrahman M. Hachem*
*Spring 2025 | MUC University, Faculty of Technology*
