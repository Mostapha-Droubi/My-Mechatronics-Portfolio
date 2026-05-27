# Master Node Controller (Arduino Nano)

## Overview
This module acts as the **Master Controller** for the Driver Calling IoT System. Its primary responsibility is to manage the physical passenger interface, process local requests, and signal the Gateway node (ESP8266) via hardwired GPIO communication.

## Functionality
- **Input Handling**: Monitors tactile push-button inputs with software debouncing.
- **User Feedback**: Manages the I2C LCD (16x2) to display real-time service status (e.g., "Ready", "Driver on the way").
- **State Signaling**: Communicates system state to the ESP8266 Gateway through dedicated digital output pins:
    - `requestPin`: High when a pickup is requested.
    - `confirmedPin`: High when the driver's arrival is confirmed.

## Pinout Configuration
| Pin | Function | Direction |
| :--- | :--- | :--- |
| D2 | Push Button | Input (Internal Pull-up) |
| D3 | Ready LED | Output |
| D4 | Progress LED | Output |
| D10 | Request Signal | Output (to ESP8266 D1) |
| D11 | Confirmation Signal | Output (to ESP8266 D2) |
| A4/A5 | I2C LCD | Interface |

## Communication Logic
The Nano operates on a non-blocking state machine. When the user interacts with the system, the Nano updates the local display and toggles the corresponding `request` or `confirmed` pins, which are read by the ESP8266.

**Important**: Ensure the Nano and ESP8266 share a **Common Ground (GND)** connection for reliable signaling.

## Requirements
- `LiquidCrystal_I2C` library must be installed in the Arduino IDE.
