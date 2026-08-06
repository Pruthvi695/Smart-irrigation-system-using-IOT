# 💻 Firmware Documentation

## Overview

The firmware is the core software running on the ESP32 Development Board. It is responsible for:

- Reading sensor data
- Connecting to Wi-Fi
- Uploading data to Firebase
- Controlling the relay module
- Automating irrigation
- Handling communication with the cloud dashboard

The firmware is developed using **Arduino IDE** and programmed in **C++**.

---

# Firmware Structure

```text
firmware/
│
├── README.md
├── smart_irrigation.ino
└── config.h
```

---

# File Description

## smart_irrigation.ino

Main application source code.

Responsibilities:

- Initialize ESP32
- Read sensors
- Connect Wi-Fi
- Connect Firebase
- Upload sensor data
- Control relay
- Execute irrigation logic

---

## config.h

Contains project configuration.

Example:

- Wi-Fi SSID
- Wi-Fi Password
- Firebase Host
- Firebase API Key
- Firebase Database URL

**Never upload this file to GitHub if it contains real credentials.**

---

# Development Environment

## IDE

Arduino IDE 2.x

Download:

https://www.arduino.cc/en/software

---

# ESP32 Board Package

Install through

Tools

↓

Board Manager

↓

Search

```
esp32
```

Install the latest package by Espressif Systems.

---

# Required Libraries

Install the following libraries from Arduino Library Manager.

| Library | Purpose |
|---------|---------|
| WiFi | Wi-Fi communication |
| Firebase ESP Client | Firebase integration |
| DHT Sensor Library | Read DHT11 |
| Adafruit Unified Sensor | DHT dependency |
| ArduinoJson | JSON processing |

---

# Firmware Workflow

```text
Power ON

↓

Initialize ESP32

↓

Initialize Sensors

↓

Connect Wi-Fi

↓

Connect Firebase

↓

Read Soil Moisture

↓

Read Temperature

↓

Read Humidity

↓

Upload Data

↓

Compare Moisture

↓

Pump ON/OFF

↓

Repeat Forever
```

---

# Sensor Reading Cycle

Every cycle the firmware performs:

1. Read soil moisture.
2. Read temperature.
3. Read humidity.
4. Upload data.
5. Update dashboard.
6. Check threshold.
7. Switch relay.
8. Delay.
9. Repeat.

---

# Moisture Threshold

Example

```cpp
const int moistureThreshold = 35;
```

Logic

```
Moisture < Threshold

↓

Pump ON
```

Otherwise

```
Pump OFF
```

---

# Pin Configuration

| GPIO | Component |
|------|-----------|
| GPIO34 | Soil Moisture Sensor |
| GPIO4 | DHT11 |
| GPIO26 | Relay |

---

# Compilation

Open

```
smart_irrigation.ino
```

Select

```
Board

↓

ESP32 Dev Module
```

Choose the correct COM Port.

Click

```
Verify
```

Fix any compilation errors.

---

# Uploading Firmware

1. Connect ESP32 using USB.
2. Open Arduino IDE.
3. Select Board.
4. Select Port.
5. Click Upload.
6. Wait for upload to finish.
7. Open Serial Monitor.

---

# Serial Monitor

Recommended baud rate

```
115200
```

Typical output

```
Connecting to Wi-Fi...

Connected.

Reading Sensors...

Moisture: 42%

Temperature: 28°C

Humidity: 64%

Pump OFF

Uploading to Firebase...
```

---

# Troubleshooting

## ESP32 Not Detected

- Install USB drivers.
- Try another USB cable.
- Select correct COM port.

---

## Wi-Fi Connection Failed

- Check SSID.
- Check password.
- Ensure 2.4 GHz Wi-Fi.

---

## Firebase Error

- Verify API key.
- Verify database URL.
- Check internet connection.

---

## Sensor Not Responding

- Check wiring.
- Verify GPIO assignments.
- Test the sensor independently.

---

## Relay Not Working

- Verify GPIO26.
- Check relay power.
- Test with a simple blink sketch.

---

# Best Practices

- Store credentials in `config.h`.
- Keep libraries updated.
- Comment the code clearly.
- Use meaningful variable names.
- Calibrate the soil moisture sensor before deployment.
- Test each module independently before full integration.

---

# Future Improvements

- OTA (Over-the-Air) firmware updates
- MQTT communication
- Secure HTTPS requests
- Multiple irrigation zones
- Deep sleep mode for lower power consumption
- Weather API integration
- AI-based irrigation scheduling

---

# Firmware Summary

The firmware provides the intelligence of the Smart Irrigation System. It integrates sensor data acquisition, Wi-Fi communication, cloud synchronization, and automatic pump control into a reliable application running on the ESP32, enabling efficient and automated irrigation.
