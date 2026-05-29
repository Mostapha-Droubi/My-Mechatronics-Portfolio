# Hardware Design: All-in-One Component Tester

This folder contains the native source files for the All-in-One Component Tester, a precision diagnostic tool built around the ATmega328P microcontroller.

## 📁 Files
* **Component_Tester.epcb**: The primary project source file for EasyEDA Pro, containing the schematic and PCB layout for the tester.

## 🛠 Design Strategy (Double-Layer)
This project is engineered as a **double-layer PCB** to provide the high signal integrity required for analog measurements.
* **Analog Precision**: The layout prioritizes short trace lengths between the test terminals and the ATmega328P ADC (Analog-to-Digital Converter) pins to minimize parasitic resistance and capacitance.
* **Ground Plane**: A dedicated bottom-layer ground plane is used to reduce electrical noise, ensuring that component measurements (like ESR or capacitance) remain consistent and accurate.
* **Decoupling**: Multiple 100nF ceramic capacitors are placed as close as possible to the VCC and AVCC pins to stabilize the power supply during active measurement cycles.

## ⚙️ Technical Blocks
1. **Power Stage**: 12V input with reverse polarity protection, regulated to 5V.
2. **Measurement Core**: ATmega328P utilizing ADC channels to probe component characteristics.
3. **System Clock**: 16 MHz crystal oscillator for precise timing during reactive component (capacitor/inductor) testing.
4. **Interface**: Test socket for quick component insertion and headers for firmware flashing.



## 🚀 Usage
* **Assembly**: Solder components according to the `bom.csv` located in the `/Manufacturing` folder. Ensure the crystal oscillator and decoupling capacitors are placed precisely as indicated in the schematic.
* **Calibration**: After assembly, perform a self-calibration using a known high-precision reference capacitor/resistor to compensate for any trace resistance.

---
*Developed by Mostapha Droubi | 2026*
