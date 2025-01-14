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

### Dual Confirmation Mechanism
The device confirms the presence of a spirit through two simultaneous criteria:
1. **Touch Detection**:
   - The TTP223B Capacitive Touch Sensor detects physical contact.
2. **Temperature Anomaly**:
   - The two front DHT22 sensors register a temperature colder than the environmental temperature recorded by the back DHT22 sensor.

This dual confirmation system helps minimize false positives and ensures reliable detection.

---

## Hardware

### Parts List
- 3x DHT22 Sensors
- 1x 9V Battery
- 1x 9V Bateery Case
- 1x TTP223B Capacitive Touch Sensor
- 1x Arduino Nano
- 2x Green LEDs
- 2x 220 Ohm Resistors

### Hardware Setup
![alt text](https://github.com/MBarc/Ghost-Hunting-PhantomSense/blob/main/PhantomSenseDiagram.png)
---

## How It Works
1. The **TTP223B Capacitive Touch Sensor** detects physical interaction, suggesting potential spirit contact.
2. The device compares temperature readings from the two front DHT22 sensors against the back DHT22 sensor:
   - If the front sensors both register a temperature colder than the environment (detected by the back sensor), it confirms the anomaly.
3. When both conditions (touch and temperature anomaly) are met, the device signals detection via LED.

---

## Usage
1. Power on the device.
2. Monitor output signals from the device to identify detections.
   - Example: LED blinking, buzzer sound, or serial console messages.
3. Observe the environment and validate detection events.

---

## License
This project is licensed under the [MIT License](LICENSE).

---

## Disclaimer
This device is built for entertainment and experimental purposes only. The detection of spirits or paranormal activity has no scientific basis and should be approached with curiosity and skepticism.
