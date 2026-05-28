# Documentation

This folder contains technical documentation and design notes for the ATmega328P standalone microcontroller board.

## 📄 Technical Documents
* **[Schematic.pdf](Schematic.pdf)**: Full circuit diagram for the 12V-to-5V power stage, ATmega328P core, and interface headers.

## 📝 Design Notes
As per the assignment requirements, here are the technical explanations:

1. **Why ICSP is required**: ICSP (In-Circuit Serial Programming) is essential for programming the ATmega328P's internal flash memory, such as burning the bootloader or uploading raw firmware directly to the chip[cite: 1].
2. **Difference between ICSP and UART**: ICSP uses the SPI interface for low-level programming and configuration, while UART is a serial communication protocol used for data exchange between the MCU and other devices (like a PC or sensors)[cite: 1].
3. **Role of decoupling capacitors**: These 100nF capacitors are placed near the VCC pins to filter high-frequency noise and provide a local charge reservoir, ensuring the microcontroller receives stable voltage during switching operations[cite: 1].
4. **Difference between LDO and Buck Converter**: An LDO (Linear Regulator) is simple and low-noise but dissipates excess power as heat, whereas a Buck Converter is a switching regulator that offers much higher efficiency, especially when stepping down high voltages (like 12V) to 5V[cite: 1].

## 📸 Visual References
* **[PCB_Render.png](PCB_Render.png)**: 3D render of the double-layer PCB layout.

---
*Developed by Mostapha Droubi | 2026*
