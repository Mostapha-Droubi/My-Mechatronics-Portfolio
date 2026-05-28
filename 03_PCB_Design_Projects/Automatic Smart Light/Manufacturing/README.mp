# Manufacturing

This folder contains the production-ready files required to fabricate the Automatic Smart Light PCB.

## 📦 Fabrication Files
* **[gerbers.zip](gerbers.zip)**: The compressed archive containing the Gerber files (RS-274X format) and Drill files. These are ready to be uploaded to any standard PCB fabrication house (e.g., JLCPCB, PCBWay).
* **[bom.csv](bom.csv)**: The Bill of Materials. This list includes all required components, their designators (e.g., R1, Q1), and supplier part numbers for easy procurement.

## 🛠 Fabrication Instructions
1. **Upload**: Upload `gerbers.zip` to your preferred PCB manufacturer's online quoting tool.
2. **Parameters**: The board is designed for standard **FR-4 material, 1.6mm thickness**.
3. **Assembly**: Use the `bom.csv` to order components. Refer to the schematic in the `/Documentation` folder for component placement and orientation.

## 📋 Quality Assurance
* **Status**: Production Ready.
* **Compatibility**: Design verified for standard surface-mount (SMD) and through-hole component assembly.

---
*Developed by Mostapha Droubi | 2026*
