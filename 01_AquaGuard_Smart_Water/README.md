# AquaGuard: Smart Water Management System

> An automated, IoT-enabled water management solution utilizing dual-tank automation and ESP8266-based monitoring[cite: 1].

## 🛠 Technical Specifications
| Category | Details |
| :--- | :--- |
| **Primary Controllers** | Arduino Uno R3, ESP8266 NodeMCU |
| **IoT Platform** | Blynk Cloud & Mobile Application |
| **Core Languages** | C++ (Arduino Framework) |
| **Key Protocols** | I2C, Wi-Fi, MQTT (via Node-RED) |
| **PCB Design** | EasyEDA (Custom Layout) |

## 🏗 System Architecture
* **Firmware Design**: Non-blocking control logic for real-time level monitoring and sensor processing.
* **Automation Control**: Automated pump control using 1-channel relay logic based on ultrasonic feedback.
* **IoT Integration**: Remote monitoring and system control managed via the **Blynk mobile application**.
* **Hardware Implementation**: PCB architecture focused on decoupling capacitor placement and signal integrity for low-voltage sensor inputs.

## 🧪 Calibration & Logic
The system maintains precision through calibrated formulas implemented in the firmware:
* **pH Monitoring**: $pH = -5.5019 \times Voltage + 21.311$.
* **Water Level**: $(Maximum Depth - Measured Depth) / Maximum Depth \times 100\%$.

## 📁 Repository Contents
* **[Firmware](./firmware/)**: Source code, calibration scripts, and master-slave communication protocols.
* **[Schematics](./schematics/)**: Hardware design files, PCB layout diagrams, and component sourcing documentation.
* **[Technical Report](./docs/)**: Comprehensive documentation detailing system requirements, performance analysis, and design methodology.

---
*Developed through rigorous mechatronics design principles for automated fluid management.*
