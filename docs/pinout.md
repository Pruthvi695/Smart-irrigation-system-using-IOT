# 📍 ESP32 Pinout Reference

## Overview

This document provides the GPIO pin assignments for the Smart Irrigation System using the ESP32 Development Board. Proper pin selection ensures reliable sensor readings, stable relay control, and smooth Wi-Fi operation.

---

# ESP32 GPIO Allocation

| GPIO Pin | Connected Component | Signal Type | Purpose |
|----------|---------------------|-------------|---------|
| GPIO34 | Soil Moisture Sensor | Analog Input | Reads soil moisture values |
| GPIO4 | DHT11 Sensor | Digital Input | Reads temperature & humidity |
| GPIO26 | Relay Module | Digital Output | Controls water pump |
| 3.3V | Sensors | Power | Supplies power to sensors |
| 5V | Relay Module | Power | Powers relay |
| GND | All Components | Ground | Common ground connection |

---

# Pin Layout

```text
                ESP32 DEVKIT V1

           +-----------------------+
      3V3  | ●                 ● | VIN
      EN   | ●                 ● | GND
 GPIO36    | ●                 ● | GPIO23
 GPIO39    | ●                 ● | GPIO22
 GPIO34 <--| ●                 ● | GPIO1
 GPIO35    | ●                 ● | GPIO3
 GPIO32    | ●                 ● | GPIO21
 GPIO33    | ●                 ● | GPIO19
 GPIO25    | ●                 ● | GPIO18
 GPIO26 <--| ●                 ● | GPIO5
 GPIO27    | ●                 ● | GPIO17
 GPIO14    | ●                 ● | GPIO16
 GPIO12    | ●                 ● | GPIO4 <--- DHT11
 GND       | ●                 ● | GPIO0
 GPIO13    | ●                 ● | GPIO2
           +-----------------------+

GPIO34 → Soil Moisture Sensor
GPIO4  → DHT11
GPIO26 → Relay
```

---

# Pin Details

## GPIO34

### Connected To

Capacitive Soil Moisture Sensor

### Purpose

Reads analog voltage produced by the sensor.

### Features

- Analog Input Only
- High ADC accuracy
- Cannot be used as an output

---

## GPIO4

### Connected To

DHT11 Temperature & Humidity Sensor

### Purpose

Receives digital data from the DHT11.

### Features

- Digital Input/Output
- Compatible with DHT library
- Stable during boot

---

## GPIO26

### Connected To

Relay Module

### Purpose

Turns the water pump ON or OFF.

### Features

- Digital Output
- PWM capable
- Reliable relay control

---

# Power Pins

## 3.3V

Used for:

- Soil Moisture Sensor
- DHT11 Sensor

---

## 5V

Used for:

- Relay Module

---

## GND

All components share a common ground.

---

# ADC Pins

The ESP32 provides multiple Analog-to-Digital Converter (ADC) pins.

Common ADC pins:

| GPIO | ADC |
|------|-----|
| GPIO32 | ADC1 |
| GPIO33 | ADC1 |
| GPIO34 | ADC1 |
| GPIO35 | ADC1 |
| GPIO36 | ADC1 |
| GPIO39 | ADC1 |

For this project:

**GPIO34** is selected because it belongs to ADC1, which remains reliable while Wi-Fi is active.

---

# Pins to Avoid

Some ESP32 pins have special boot functions.

Avoid using these unless necessary:

| GPIO | Reason |
|------|--------|
| GPIO0 | Boot Mode |
| GPIO2 | Boot Configuration |
| GPIO12 | Flash Voltage Selection |
| GPIO15 | Boot Configuration |

Using these incorrectly may prevent the ESP32 from booting.

---

# Why These Pins Were Selected

| Component | GPIO | Reason |
|-----------|------|--------|
| Soil Moisture Sensor | GPIO34 | High-quality analog input |
| DHT11 | GPIO4 | Stable digital communication |
| Relay | GPIO26 | Reliable digital output |

---

# Signal Types

| Component | Signal |
|-----------|--------|
| Soil Moisture Sensor | Analog |
| DHT11 | Digital |
| Relay Module | Digital Output |

---

# Electrical Considerations

- ESP32 GPIO pins operate at **3.3V logic**.
- Do not apply **5V directly** to GPIO pins.
- Use a common ground for all connected devices.
- Provide a separate power source for the 12V water pump.

---

# Future GPIO Expansion

Available GPIOs that can be used later:

| GPIO | Possible Use |
|------|--------------|
| GPIO18 | OLED Display |
| GPIO19 | Water Flow Sensor |
| GPIO21 | I²C SDA |
| GPIO22 | I²C SCL |
| GPIO23 | Rain Sensor |
| GPIO25 | Buzzer |
| GPIO27 | Water Level Sensor |
| GPIO32 | Additional Soil Moisture Sensor |
| GPIO33 | LCD Display |

---

# Summary

The chosen GPIO assignments provide a simple, reliable, and expandable hardware interface. Using GPIO34 for analog sensing, GPIO4 for digital sensor communication, and GPIO26 for relay control ensures stable system operation while leaving sufficient GPIOs available for future enhancements.
