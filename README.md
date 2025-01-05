<p align="center">
  <img src="logo.png" alt="Project Logo" width="200"/>
</p>

<h1 align="center">PhantomSense: A Ghost Hunting Device</h1>

This repository contains the code and documentation for a custom-built **PhantomSense** device designed to detect paranormal activity. The device uses a combination of **DHT22 sensors** and a **TTP223B Capacitive Touch Sensor** to confirm the presence of spirits based on changes in temperature and touch interaction.

## Table of Contents
- [Features](#features)
- [Hardware](#hardware)
- [Software](#software)
- [Setup and Installation](#setup-and-installation)
- [Usage](#usage)
- [License](#license)

---

## Features

### Multi-Sensor Detection
1. **DHT22 Sensors**:
   - Two sensors located near the front of the device.
   - One sensor at the back of the device to monitor ambient environmental temperature.
2. **TTP223B Capacitive Touch Sensor**:
   - Positioned between the two front DHT22 sensors to detect physical interaction.

### Dual Confirmation Mechanism
The device confirms the presence of a spirit through two simultaneous criteria:
1. **Touch Detection**:
   - The TTP223B Capacitive Touch Sensor detects physical contact.
2. **Temperature Anomaly**:
   - The two front DHT22 sensors register a temperature colder than the environmental temperature recorded by the back DHT22 sensor.

This dual confirmation system helps minimize false positives and ensures reliable detection.

---

## Hardware Components
- **DHT22 Sensors** (x3): For temperature and humidity readings.
  - 2 sensors near the front for localized temperature measurement.
  - 1 sensor at the back for baseline environmental temperature.
- **TTP223B Capacitive Touch Sensor**: To detect interaction with the device.
- **Microcontroller**: Compatible with the provided code (e.g., Arduino, ESP32, Raspberry Pi).
- **Power Source**: Depending on the microcontroller used.

---

## How It Works
1. The **TTP223B Capacitive Touch Sensor** detects physical interaction, suggesting potential spirit contact.
2. The device compares temperature readings from the two front DHT22 sensors against the back DHT22 sensor:
   - If the front sensors both register a temperature colder than the environment (detected by the back sensor), it confirms the anomaly.
3. When both conditions (touch and temperature anomaly) are met, the device signals detection (e.g., via LED, buzzer, or serial output).

---

## Setup and Installation

### Hardware Assembly
1. Place the **TTP223B Capacitive Touch Sensor** between the two front DHT22 sensors.
2. Position the third DHT22 sensor at the back of the device to capture ambient temperature.
3. Connect the sensors and touch module to your microcontroller.
4. Power the device.

### Software Installation
1. Clone this repository:
   ```bash
   git clone https://github.com/yourusername/ghost-hunting-phantomsense.git
   ```
2. Install required libraries for your microcontroller (e.g., DHT sensor and touch sensor libraries).
3. Upload the code to your microcontroller using your preferred IDE (e.g., Arduino IDE).

---

## Usage
1. Power on the device.
2. Monitor output signals from the device to identify detections.
   - Example: LED blinking, buzzer sound, or serial console messages.
3. Observe the environment and validate detection events.

---

## Contributing
Contributions are welcome! If you have ideas for improvement or additional features, feel free to open an issue or submit a pull request.

---

## License
This project is licensed under the [MIT License](LICENSE).

---

## Disclaimer
This device is built for entertainment and experimental purposes only. The detection of spirits or paranormal activity has no scientific basis and should be approached with curiosity and skepticism.
