# Manufacturing

This folder contains the production-ready files required to fabricate the standalone ATmega328P board.

## 📦 Fabrication Files
* **[gerbers.zip](gerbers.zip)**: The compressed archive containing the Gerber files (RS-274X format) and Drill files, configured for a **double-layer** manufacturing process.
* **[bom.csv](bom.csv)**: The complete Bill of Materials, including the ATmega328P, 16MHz crystal, voltage regulator, and all passive components required for the assembly.

## 🛠 Fabrication Instructions
1. **Upload**: Upload `gerbers.zip` to your preferred PCB manufacturer.
2. **Parameters**: 
   - **Layers**: 2 Layers
   - **Material**: FR-4, 1.6mm thickness
   - **Surface Finish**: HASL or ENIG
3. **Assembly**: Use the `bom.csv` to source your components. Refer to the **Schematic.pdf** in the `/Documentation` folder for the precise placement of decoupling capacitors (100nF) and the 10kΩ reset pull-up resistor.

## 📋 Quality Assurance
* **Status**: Production Ready.
* **Design Note**: The design utilizes a double-layer layout to optimize ground plane distribution, which is critical for the stability of the ATmega328P's sensitive analog and digital power pins.

---
*Developed by Mostapha Droubi | 2026*
