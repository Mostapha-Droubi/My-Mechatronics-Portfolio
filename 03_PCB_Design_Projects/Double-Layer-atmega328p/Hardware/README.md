# Hardware Design: Standalone ATmega328P Board

This folder contains the native source files for the ATmega328P standalone microcontroller board, designed using **EasyEDA Pro**.

## 📁 Files
* **ATmega328P_Board.epcb**: The primary project source file. This file contains the schematic, PCB layout, and design settings.

## 🛠 Design Strategy (Double-Layer)
This project is designed as a **double-layer PCB** to optimize signal integrity and component density.
* **Top Layer**: Primarily used for component placement and high-priority signal traces.
* **Bottom Layer**: Utilized for ground plane flooding and secondary routing, reducing trace length and complexity.
* **Via Stitching**: Vias are strategically placed to connect the top and bottom layers, ensuring a low-impedance path for ground and power distribution.

## ⚙️ Technical Blocks
1. **Power Stage**: 12V input with reverse polarity protection (1N4007 diode).
2. **Regulation**: 12V to 5V conversion via 7805 Linear Regulator.
3. **Core**: ATmega328P with 16MHz crystal and necessary decoupling capacitors (100nF).
4. **Interfaces**:
    * **ICSP Header**: 6-pin interface for programming.
    * **UART Header**: 4-pin interface for communication.

## 🚀 Usage
* **Editing**: Open the `.epcb` file within the EasyEDA Pro environment.
* **Documentation**: For universal viewing, refer to the schematics and BOM in the `/Documentation` and `/Manufacturing` folders.

---
*Developed by Mostapha Droubi | 2026*
