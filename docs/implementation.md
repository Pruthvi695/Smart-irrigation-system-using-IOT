# 🛠️ Project Implementation

## Overview

The Smart Irrigation System is implemented using an ESP32 microcontroller, environmental sensors, a relay-controlled water pump, and a cloud-based monitoring platform. The system continuously monitors soil moisture, temperature, and humidity, then automatically controls irrigation based on predefined moisture thresholds.

The implementation is divided into four main phases:

1. Hardware Setup
2. Firmware Development
3. Cloud Integration
4. Testing and Validation

---

# Phase 1: Hardware Setup

The hardware components are assembled on a breadboard before being deployed on the final prototype.

## Components Used

| Component | Function |
|-----------|----------|
| ESP32 Development Board | Main controller |
| Capacitive Soil Moisture Sensor | Measures soil moisture |
| DHT11 Sensor | Measures temperature and humidity |
| Relay Module | Switches the water pump |
| 12V DC Water Pump | Irrigation |
| Power Supply | Powers the system |
| Jumper Wires | Electrical connections |

---

# Hardware Connections

## Soil Moisture Sensor

| Sensor Pin | ESP32 Pin |
|------------|-----------|
| VCC | 3.3V |
| GND | GND |
| AO | GPIO34 |

---

## DHT11 Sensor

| Sensor Pin | ESP32 Pin |
|------------|-----------|
| VCC | 3.3V |
| GND | GND |
| DATA | GPIO4 |

---

## Relay Module

| Relay Pin | ESP32 Pin |
|------------|-----------|
| VCC | 5V |
| GND | GND |
| IN | GPIO26 |

---

## Water Pump

The pump is connected through the relay module using an external 12V power supply.

**Important:** Never power the pump directly from the ESP32.

---

# Phase 2: Firmware Development

The firmware is written in C++ using the Arduino IDE.

The firmware performs the following tasks:

- Initialize sensors
- Connect to Wi-Fi
- Connect to Firebase
- Read sensor values
- Compare moisture with threshold
- Control relay
- Upload sensor data
- Repeat continuously

---

# Program Logic

```text
Start

↓

Initialize ESP32

↓

Initialize Sensors

↓

Connect Wi-Fi

↓

Connect Firebase

↓

Read Sensors

↓

Upload Data

↓

Compare Moisture

↓

Dry?

↓

YES → Pump ON

↓

Wet?

↓

YES → Pump OFF

↓

Repeat
```

---

# Moisture Threshold

A moisture threshold is defined in the firmware.

Example:

```cpp
const int moistureThreshold = 35;
```

Decision:

- Moisture < 35 → Pump ON
- Moisture ≥ 35 → Pump OFF

The threshold can be adjusted depending on the crop and soil type.

---

# Cloud Integration

Firebase Realtime Database is used for cloud storage.

The ESP32 uploads:

- Soil Moisture
- Temperature
- Humidity
- Pump Status
- Timestamp

Example database structure:

```text
SmartIrrigation

├── moisture
├── temperature
├── humidity
├── pumpStatus
└── timestamp
```

---

# Dashboard

The dashboard displays:

- Live soil moisture
- Live temperature
- Live humidity
- Pump status
- Last update time

Optional controls:

- Manual Pump ON
- Manual Pump OFF

---

# Automatic Irrigation Process

1. Read moisture sensor.
2. Compare with threshold.
3. If soil is dry:
   - Relay ON
   - Pump ON
4. Continue monitoring.
5. Once moisture reaches the threshold:
   - Relay OFF
   - Pump OFF
6. Upload updated status to Firebase.

---

# Error Handling

The firmware includes basic fault handling.

## Wi-Fi Failure

- Retry connection automatically.
- Continue retrying until connected.

## Firebase Failure

- Buffer readings locally.
- Upload once the connection is restored.

## Sensor Failure

- Skip invalid readings.
- Display an error message on the serial monitor.

---

# Testing

The system was tested under three conditions.

## Test 1: Dry Soil

Expected:
- Pump turns ON.

Observed:
- Pump activated successfully.

Status:
✅ Pass

---

## Test 2: Wet Soil

Expected:
- Pump remains OFF.

Observed:
- Pump stayed OFF.

Status:
✅ Pass

---

## Test 3: Cloud Upload

Expected:
- Sensor values visible on dashboard.

Observed:
- Data synchronized successfully.

Status:
✅ Pass

---

# Deployment

After successful testing:

- Mount the sensors near the plant roots.
- Place the ESP32 in a waterproof enclosure.
- Connect the water pump to the irrigation pipe.
- Supply stable power to both the ESP32 and the pump.
- Verify cloud connectivity before regular operation.

---

# Implementation Challenges

- Sensor calibration for different soil types.
- Maintaining stable Wi-Fi connectivity.
- Protecting electronics from moisture and dust.
- Preventing relay switching noise from affecting the ESP32.
- Ensuring reliable power delivery to the pump.

---

# Best Practices

- Use a capacitive soil moisture sensor to reduce corrosion.
- Keep Wi-Fi credentials in a separate `config.h` file.
- Use separate power supplies for the ESP32 and pump.
- Calibrate the moisture sensor before deployment.
- Add a flyback diode or opto-isolated relay if using higher-power pumps.

---

# Conclusion

The Smart Irrigation System implementation demonstrates how embedded hardware, sensor networks, cloud services, and automation can be integrated into a practical IoT application. The modular design allows future expansion with additional sensors, weather data integration, and AI-based irrigation scheduling.
