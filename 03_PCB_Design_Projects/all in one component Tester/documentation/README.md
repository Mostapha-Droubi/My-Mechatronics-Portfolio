# Documentation: Component Tester

This folder contains the technical documentation, circuit theory, and measurement principles for the All-in-One Component Tester.

## 📄 Technical Documents
* **[Schematic.pdf](SCH_Schematic1_2026-05-29.pdf)**: The complete circuit diagram detailing the ATmega328P connections, power regulation, and test pin configuration.

## 💡 Measurement Theory
The component tester operates by systematically probing components connected to the test socket:

* **Resistance Measurement**: The microcontroller forms a voltage divider with the unknown resistor and a known internal reference resistor. By measuring the voltage at the node using an ADC pin, the MCU calculates the resistance.
* **Capacitance Measurement**: The tester measures the time constant ($\tau = R \times C$) by charging the capacitor through a known resistor and measuring the time taken to reach a specific voltage threshold.
* **Semiconductor Identification**: The MCU cycles through various polarity configurations on the test pins. By observing which pins allow current flow and measuring the forward voltage ($V_f$), it identifies the device type (NPN/PNP transistor, MOSFET, or Diode) and pinout.



## 📸 Visual References
* **[2D_PCB_View.png](2D.png)**: 2D representation of the PCB layout.
* **[3D_PCB_Render.jpg](3D.jpg)**: 3D visualization showing component placement and socket orientation.

## 🛠 Design Notes
* **Precision**: Accurate measurements rely on the precision of the onboard reference resistors and the stability of the 5V supply.
* **Safety Warning**: Always discharge capacitors before inserting them into the test socket to prevent high-voltage discharge from damaging the ATmega328P ADC pins.

---
*Developed by Mostapha Droubi | 2026*
