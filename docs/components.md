# 🔧 Hardware Components

## Overview

The Smart Irrigation System is built using affordable and widely available IoT components. Each component plays a specific role in sensing environmental conditions, processing data, communicating with the cloud, or controlling irrigation.

---

# 1. ESP32 Development Board

## Description

The ESP32 is a low-power, high-performance microcontroller developed by Espressif Systems. It comes with built-in Wi-Fi and Bluetooth, making it ideal for IoT applications.

## Specifications

| Property | Value |
|----------|-------|
| Operating Voltage | 3.3V |
| Input Voltage | 5V (USB) |
| CPU | Dual-Core Xtensa LX6 |
| Clock Speed | Up to 240 MHz |
| SRAM | 520 KB |
| Flash Memory | 4 MB |
| Wi-Fi | IEEE 802.11 b/g/n |
| Bluetooth | BLE + Classic |

## Why ESP32?

- Built-in Wi-Fi
- High processing power
- Low power consumption
- Multiple GPIO pins
- Easy programming with Arduino IDE
- Large community support

## Role in the Project

- Reads sensor values
- Connects to Wi-Fi
- Uploads data to Firebase
- Controls the relay module
- Executes irrigation logic

---

# 2. Capacitive Soil Moisture Sensor

## Description

The capacitive soil moisture sensor measures the water content in the soil by detecting changes in capacitance. Unlike resistive sensors, it is corrosion-resistant and provides more stable readings over time.

## Specifications

| Property | Value |
|----------|-------|
| Operating Voltage | 3.3V – 5V |
| Output | Analog |
| Measurement | Soil Moisture |
| Corrosion Resistant | Yes |

## Why Capacitive Sensor?

- Longer lifespan
- More accurate readings
- Resistant to rust and corrosion
- Suitable for long-term deployment

## Role in the Project

- Measures soil moisture continuously
- Sends analog data to the ESP32
- Determines whether irrigation is required

---

# 3. DHT11 Temperature and Humidity Sensor

## Description

The DHT11 is a digital sensor used to measure ambient temperature and relative humidity. It provides calibrated digital output through a single data pin.

## Specifications

| Property | Value |
|----------|-------|
| Operating Voltage | 3.3V – 5V |
| Temperature Range | 0°C to 50°C |
| Humidity Range | 20%–90% RH |
| Communication | Digital |

## Why DHT11?

- Easy to interface
- Low cost
- Suitable for basic environmental monitoring
- Widely supported by Arduino libraries

## Role in the Project

- Monitors environmental conditions
- Provides temperature and humidity data for display and future analysis

---

# 4. Relay Module

## Description

The relay module acts as an electrically controlled switch, allowing the ESP32 to safely control the high-power water pump.

## Specifications

| Property | Value |
|----------|-------|
| Operating Voltage | 5V |
| Channels | 1 |
| Trigger Type | Digital |
| Load Type | AC/DC |

## Why Relay Module?

- Provides electrical isolation
- Allows low-voltage control of high-voltage devices
- Reliable switching

## Role in the Project

- Receives ON/OFF signals from the ESP32
- Controls power supplied to the water pump

---

# 5. 12V DC Water Pump

## Description

The water pump supplies water from a storage tank to the irrigation line. It operates only when activated through the relay module.

## Specifications

| Property | Value |
|----------|-------|
| Operating Voltage | 12V DC |
| Flow Rate | Depends on model |
| Power Source | External Adapter |

## Why This Pump?

- Compact size
- Easy integration
- Low power consumption
- Suitable for small-scale irrigation

## Role in the Project

- Delivers water to plants automatically when the soil becomes dry

---

# 6. Breadboard

## Description

The breadboard is used for temporary circuit prototyping without soldering.

## Advantages

- Reusable
- Easy to modify circuits
- Ideal for testing

## Role in the Project

- Holds the prototype circuit during development

---

# 7. Jumper Wires

## Description

Jumper wires provide electrical connections between components.

## Types Used

- Male-to-Male
- Male-to-Female
- Female-to-Female

## Role in the Project

- Connect sensors, relay, and ESP32

---

# 8. Power Supply

## Description

A regulated power supply provides stable voltage to both the ESP32 and the water pump.

## Requirements

| Device | Voltage |
|---------|----------|
| ESP32 | 5V (USB) |
| Pump | 12V DC |

> **Note:** Use separate power supplies for the ESP32 and the water pump to avoid voltage drops and unexpected resets.

---

# Hardware Summary

| Component | Purpose |
|-----------|---------|
| ESP32 | Central controller |
| Soil Moisture Sensor | Detects soil moisture |
| DHT11 | Measures temperature and humidity |
| Relay Module | Switches the water pump |
| Water Pump | Irrigates plants |
| Breadboard | Circuit prototyping |
| Jumper Wires | Electrical connections |
| Power Supply | Provides stable power |

---

# Estimated Cost

| Component | Approx. Cost (INR) |
|-----------|-------------------:|
| ESP32 | ₹500 |
| Soil Moisture Sensor | ₹150 |
| DHT11 | ₹120 |
| Relay Module | ₹120 |
| Water Pump | ₹300 |
| Breadboard | ₹150 |
| Jumper Wires | ₹100 |
| Power Supply | ₹250 |
| **Total** | **₹1,690** |

---

# Hardware Selection Advantages

- Affordable and easily available
- Beginner-friendly
- Reliable for IoT applications
- Low power consumption
- Expandable with additional sensors
- Compatible with Arduino IDE and Firebase

---

# Future Hardware Upgrades

The system can be enhanced by adding:

- Rain Sensor
- Water Level Sensor
- Water Flow Sensor
- OLED Display
- GSM Module
- Solar Panel with Battery
- LoRa Communication Module
- Multiple Soil Moisture Sensors
- ESP32-CAM for remote crop monitoring

---

# Conclusion

The selected hardware provides a cost-effective, scalable, and reliable foundation for an IoT-based smart irrigation system. Using the ESP32 as the central controller, together with environmental sensors, relay control, and cloud connectivity, the project demonstrates an efficient approach to automated irrigation for small farms, gardens, and greenhouse applications.
