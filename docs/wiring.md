# 🔌 Wiring Guide

## Overview

This document describes the complete wiring of the Smart Irrigation System using an ESP32 development board. The system consists of a capacitive soil moisture sensor, DHT11 temperature and humidity sensor, a relay module, and a 12V DC water pump.

Proper wiring is essential to ensure accurate sensor readings, reliable pump operation, and safe power distribution.

---

# System Connection Diagram

```text
                     +----------------------+
                     |       ESP32          |
                     |----------------------|
                     | 3.3V --------------+----------------+
                     | GND ---------------+-----------+----+---------+
                     | GPIO34 -------- Soil Moisture AO             |
                     | GPIO4 --------- DHT11 DATA                  |
                     | GPIO26 -------- Relay IN                    |
                     +----------------------+                      |
                                                |                 |
                                                |                 |
                     +--------------------------+                 |
                     |                                            |
                     ▼                                            ▼

          +----------------------+                  +----------------------+
          | Soil Moisture Sensor |                  |      DHT11 Sensor    |
          |----------------------|                  |----------------------|
          | VCC → 3.3V           |                  | VCC → 3.3V           |
          | GND → GND            |                  | GND → GND            |
          | AO  → GPIO34         |                  | DATA → GPIO4         |
          +----------------------+                  +----------------------+

                               ESP32 GPIO26
                                     │
                                     ▼
                          +----------------------+
                          |    Relay Module      |
                          |----------------------|
                          | IN  → GPIO26         |
                          | VCC → 5V            |
                          | GND → GND           |
                          +----------+-----------+
                                     |
                                     ▼
                             +---------------+
                             | Water Pump    |
                             +---------------+
```

---

# ESP32 Pin Mapping

| ESP32 Pin | Connected Device | Purpose |
|-----------|------------------|---------|
| 3.3V | Soil Moisture Sensor | Power Supply |
| GND | Soil Moisture Sensor | Ground |
| GPIO34 | Soil Moisture AO | Analog Input |
| 3.3V | DHT11 | Power Supply |
| GND | DHT11 | Ground |
| GPIO4 | DHT11 DATA | Digital Input |
| GPIO26 | Relay IN | Relay Control |
| 5V | Relay VCC | Relay Power |
| GND | Relay GND | Common Ground |

---

# Soil Moisture Sensor Wiring

| Sensor Pin | ESP32 Pin |
|------------|-----------|
| VCC | 3.3V |
| GND | GND |
| AO | GPIO34 |

### Working

The sensor outputs an analog voltage proportional to the moisture present in the soil.

Typical readings:

| Soil Condition | Analog Reading |
|---------------|---------------:|
| Very Wet | 1000–1500 |
| Moist | 1500–2500 |
| Dry | 2500–3500 |

> Actual values vary by sensor and require calibration.

---

# DHT11 Wiring

| DHT11 Pin | ESP32 Pin |
|------------|-----------|
| VCC | 3.3V |
| GND | GND |
| DATA | GPIO4 |

### Working

The DHT11 transmits calibrated digital values for:

- Temperature
- Relative Humidity

---

# Relay Module Wiring

| Relay Pin | ESP32 Pin |
|------------|-----------|
| VCC | 5V |
| GND | GND |
| IN | GPIO26 |

### Relay Contacts

| Relay Terminal | Connection |
|---------------|------------|
| COM | 12V Supply Positive |
| NO | Pump Positive Terminal |
| NC | Not Used |

Pump Negative Terminal → 12V Supply Negative

---

# Water Pump Wiring

The water pump must **not** be powered directly from the ESP32.

Correct wiring:

```text
12V Adapter (+)
       │
       ▼
Relay COM

Relay NO
       │
       ▼
Pump (+)

Pump (-)
       │
       ▼
12V Adapter (-)
```

When the relay closes, power flows to the pump and irrigation begins.

---

# Power Distribution

## ESP32

- Powered via USB or regulated 5V input.

## Relay

- Powered from the ESP32 5V pin.

## Water Pump

- Powered by an independent 12V DC adapter.

> Using a dedicated power supply for the pump prevents voltage drops that could reset the ESP32.

---

# Breadboard Layout Recommendations

- Place the ESP32 at the center of the breadboard.
- Keep sensor wires as short as possible to reduce noise.
- Route power lines separately from signal lines.
- Secure all jumper wires before testing.
- Label connections if building a permanent prototype.

---

# Wiring Checklist

Before powering the system, verify:

- ESP32 receives stable power.
- Sensor VCC and GND are connected correctly.
- GPIO connections match the firmware.
- Relay is wired correctly.
- Pump uses a separate 12V supply.
- All grounds are common where required.
- No loose or exposed wires are present.

---

# Safety Precautions

- Never connect the pump directly to the ESP32 GPIO pins.
- Disconnect power before changing wiring.
- Keep electronics away from water.
- Use insulated connectors for the pump.
- Double-check polarity before powering the circuit.
- Test the relay with a low-voltage load before connecting the pump.

---

# Troubleshooting

| Problem | Possible Cause | Solution |
|---------|----------------|----------|
| No sensor readings | Loose wiring | Check VCC, GND, and signal connections |
| Relay not switching | Wrong GPIO or insufficient voltage | Verify GPIO26 and relay power |
| Pump not running | Relay contacts or power supply issue | Check COM/NO wiring and 12V adapter |
| ESP32 keeps restarting | Pump drawing power from ESP32 | Use a separate power supply for the pump |
| Moisture readings unstable | Poor calibration or noisy wiring | Recalibrate sensor and shorten analog wires |

---

# Summary

The wiring described in this document provides a reliable and safe hardware setup for the Smart Irrigation System. Correct pin mapping, proper power distribution, and careful assembly ensure stable operation and make future maintenance or expansion easier.
