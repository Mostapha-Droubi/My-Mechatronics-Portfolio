1# Master Node Controller (Arduino Nano)

## Overview
This module acts as the **Master Controller** for the Driver Calling IoT System. Its primary responsibility is to manage the physical passenger interface, process local requests via tactile inputs, and signal the Gateway node (ESP8266) via hardwired GPIO communication.

## Functionality
- **Input Handling**: Monitors tactile push-button inputs with software debouncing to ensure signal reliability.
- **User Feedback**: Manages a 16x2 I2C LCD to display real-time service status (e.g., "Ready", "Request Sent", "Driver Arrived").
- **State Signaling**: Communicates the current system state to the ESP8266 Gateway through dedicated digital output pins:
    - `requestPin` (D10): Set HIGH when a pickup is requested.
    - `confirmedPin` (D11): Set HIGH when the driver's arrival is confirmed.

## Pinout Configuration
| Pin | Function | Direction | Description |
| :--- | :--- | :--- | :--- |
| D2 | Push Button | Input | Passenger Request Trigger |
| D3 | Ready LED | Output | System Status Indicator |
| D4 | Progress LED | Output | Driver En-route Indicator |
| D10 | Request Signal | Output | Communication Link to ESP8266 |
| D11 | Confirmed Signal | Output | Communication Link to ESP8266 |
| A4/A5 | I2C LCD | Interface | Status Display |

## Engineering Note
A **Common Ground (GND)** connection must be maintained between the Arduino Nano and the ESP8266 NodeMCU to ensure signal integrity across the GPIO links.

## Dependencies
- `LiquidCrystal_I2C` (by Frank de Brabander)

2# Gateway Node (ESP8266 NodeMCU)

## Overview
The Gateway Node acts as the IoT bridge for the system. It monitors the state of the Master Node (Arduino Nano) and synchronizes the service lifecycle with the Blynk IoT Cloud platform.

## Functionality
- **Signal Monitoring**: Continuously polls the `requestPin` and `confirmedPin` from the Nano.
- **IoT Integration**: Uses the Blynk library to push event updates to the driver's mobile dashboard.
- **Connectivity**: Manages Wi-Fi reconnection logic to ensure the system remains online.

## Pinout Configuration
| Pin | Function | Direction | Description |
| :--- | :--- | :--- | :--- |
| D1 | Request Pin | Input | Receives "Pickup Requested" signal from Nano |
| D2 | Confirmed Pin | Input | Receives "Driver Arrived" signal from Nano |

## Configuration
Before building, you must update the `config.h` file in this directory with your specific credentials:
- `ssid`: Your Wi-Fi network name.
- `pass`: Your Wi-Fi password.
- `BLYNK_AUTH_TOKEN`: Your project-specific authentication token from the Blynk app.

## Communication Logic
The ESP8266 operates in an interrupt-safe polling mode. When a high signal is detected from the Nano, it executes a `Blynk.virtualWrite` to update the user interface on the driver's side.

**Warning**: The ESP8266 operates at 3.3V logic. Ensure that the signals coming from the Arduino Nano (5V) are safe for the ESP8266 pins.
