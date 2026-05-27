# Driver Calling IOT System (IoT)

## 1. Project Summary
The Waiter Calling System is a low-latency, IoT-enabled service request platform. It utilizes a Master-Slave hardware architecture to decouple physical user interactions from network connectivity, ensuring robust performance in busy restaurant environments. The Master node manages local hardware states, while the Gateway node handles asynchronous cloud synchronization.

## 2. Technical Architecture
* **Master Node (Arduino Nano)**: Executes real-time state machine logic, manages input debouncing, and drives the local User Interface (LCD/LEDs).
* **Gateway Node (ESP8266 NodeMCU)**: Functions as a non-blocking bridge to the Blynk IoT Cloud, facilitating real-time notifications to staff mobile devices.



## 3. Hardware Interfacing & Pinout
| Module | Pin | Function | Logic Type |
| :--- | :--- | :--- | :--- |
| **Master** | D2 | Patron Request Input | Active-Low (Internal Pull-up) |
| **Master** | D10/D11 | Status Signaling | 5V Digital Output |
| **Gateway**| D1/D2 | Interrupt Handling | 3.3V Digital Input |
| **System** | GND | Common Ground | Required for Signal Integrity |

> **Critical Note:** The ESP8266 logic inputs are 3.3V tolerant only. A voltage divider or logic-level shifter is required to safely interface with the Nano’s 5V outputs.

## 4. Operational State Machine
1. **IDLE**: System active; waiting for user interaction.
2. **REQUESTED**: Input verified; local request LED triggered; signal sent to Gateway.
3. **CONFIRMED**: Acknowledgment received from cloud; status displayed on LCD for the patron.

## 5. Security & Connectivity
* **Credential Management**: Network credentials (SSID/Password/Auth Token) are abstracted into a `config.h` header file to ensure security.
* **Resilience**: The Gateway node includes automatic reconnection logic to maintain uptime in unstable Wi-Fi environments.

## 6. Project Dependencies
* `LiquidCrystal_I2C` (by Frank de Brabander)
* `Blynk` (by Volodymyr Shymanskyy)

## 7. Future Scalability
* **Multi-Table Deployment**: The current GPIO-based architecture supports expansion to an I2C or SPI-based protocol for multi-node arrays.
* **Power Optimization**: Implementation of `DeepSleep` modes on the ESP8266 can support long-term battery-operated configurations.
