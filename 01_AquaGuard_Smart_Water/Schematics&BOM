# Hardware Schematics & Design

This directory contains the hardware documentation for the AquaGuard system.

## Overview
The schematic design was developed using Fritzing, focusing on robust connections between the master controller (Arduino) and the IoT gateway (ESP8266).

## Included Files
* **[AquaGuard_Schematic.pdf](./AquaGuard_Schematic.pdf)**: Comprehensive wiring diagram showing sensor integration, relay control, and power distribution.
* **[BOM.txt](./BOM.txt)**: Bill of Materials featuring part specifications and LCSC sourcing references.

## Design Notes
* **Voltage Regulation**: Ensure the 5V/2A power supply is stable to prevent reset loops in the ESP8266.
* **Signal Integrity**: Decoupling capacitors are placed close to the sensors to minimize noise in the pH and turbidity readings[cite: 1].
* **Communication**: Master-slave communication is established via serial link with logic level shifting between the Arduino (5V) and ESP8266 (3.3V).
