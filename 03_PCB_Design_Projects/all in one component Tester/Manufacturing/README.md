# Manufacturing

This folder contains the production-ready files required to fabricate the All-in-One Component Tester PCB.

## 📦 Fabrication Files
* **[gerbers.zip](gerbers.zip)**: The compressed archive containing the Gerber files (RS-274X format) and Drill files, configured for a **double-layer** fabrication process.
* **[bom.csv](bom.csv)**: The Bill of Materials. This list includes all required components, specifically the ATmega328P, crystal, reference resistors, and the test socket components.

## 🛠 Fabrication Instructions
1. **Upload**: Upload `gerbers.zip` to your preferred PCB manufacturer.
2. **Parameters**:
   - **Layers**: 2 Layers
   - **Material**: FR-4, 1.6mm thickness
   - **Surface Finish**: HASL or ENIG (ENIG is recommended for better contact with the test socket pins).
3. **Assembly**: Use the `bom.csv` to order components. Refer to the **Schematic.pdf** in the `/Documentation` folder for the correct component values and layout orientation.

## 📋 Quality Assurance
* **Status**: Production Ready.
* **Design Note**: The layout includes a dedicated ground plane to minimize noise interference during sensitive analog measurements. Please ensure that the board is clean and free of flux residue after soldering to prevent leakage currents between the test pins.

---
*Developed by Mostapha Droubi | 2026*
