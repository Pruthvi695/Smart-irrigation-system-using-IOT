# 🏗️ System Architecture

## Overview

The **Smart Irrigation System using IoT** is designed to automate irrigation by continuously monitoring soil moisture and environmental conditions. The system uses an ESP32 microcontroller as the central controller, which collects sensor data, uploads it to a cloud platform, and controls a water pump through a relay module.

The architecture follows a layered design consisting of four major layers:

1. Sensing Layer
2. Processing Layer
3. Cloud Layer
4. Application Layer

---

# Architecture Diagram

```text
                  +-------------------------+
                  |        Farmer/User      |
                  |  Mobile App / Dashboard |
                  +------------+------------+
                               |
                               |
                         Internet / Wi-Fi
                               |
                               ▼
                   +-----------------------+
                   | Firebase Realtime DB  |
                   |  (Cloud Storage)      |
                   +-----------+-----------+
                               |
                               |
                     Upload Sensor Data
                               |
                               ▼
                    +----------------------+
                    |       ESP32          |
                    | Microcontroller Unit |
                    +----+------------+----+
                         |            |
              Reads Data |            | Controls Relay
                         |            |
          +--------------+            +--------------+
          |                                        |
          ▼                                        ▼
+------------------------+              +----------------------+
| Soil Moisture Sensor   |              | Relay Module         |
+------------------------+              +----------+-----------+
                                                  |
                                                  ▼
                                        +----------------------+
                                        |  Water Pump          |
                                        +----------------------+

                         |
                         ▼

               +------------------------+
               | DHT11 Temperature &    |
               | Humidity Sensor        |
               +------------------------+
```

---

# Architecture Layers

## 1. Sensing Layer

The sensing layer consists of sensors responsible for collecting environmental data.

### Soil Moisture Sensor

Measures the moisture content in the soil and outputs an analog value that indicates whether the soil is dry or wet.

**Purpose**

- Detect soil moisture
- Determine irrigation requirement

---

### DHT11 Sensor

Measures:

- Temperature
- Relative Humidity

These values help monitor environmental conditions and can be used for future predictive irrigation.

---

# 2. Processing Layer

The processing layer is handled by the **ESP32 Development Board**.

Its responsibilities include:

- Reading sensor values
- Comparing moisture level with a predefined threshold
- Deciding whether irrigation is required
- Controlling the relay module
- Uploading data to Firebase
- Receiving remote commands

Since ESP32 has built-in Wi-Fi, no external Wi-Fi module is required.

---

# 3. Communication Layer

Communication between the ESP32 and cloud is established through Wi-Fi.

Protocol used:

- HTTP/HTTPS
- Firebase Realtime Database API

The ESP32 periodically uploads:

- Soil moisture
- Temperature
- Humidity
- Pump status
- Timestamp

---

# 4. Cloud Layer

The cloud layer stores sensor readings and provides remote accessibility.

Responsibilities:

- Store live sensor values
- Store irrigation history
- Synchronize pump status
- Allow remote monitoring

Recommended Cloud Platform:

- Firebase Realtime Database

---

# 5. Application Layer

The application layer provides the user interface.

The dashboard displays:

- Live soil moisture
- Temperature
- Humidity
- Pump ON/OFF status
- Historical sensor readings

Users can also manually control irrigation if required.

---

# Data Flow

The complete flow of information is as follows:

1. Soil Moisture Sensor measures soil moisture.
2. DHT11 measures temperature and humidity.
3. ESP32 reads all sensor values.
4. Sensor data is processed.
5. Moisture value is compared with threshold.
6. If soil is dry:
   - Relay is activated.
   - Water pump starts.
7. Sensor values are uploaded to Firebase.
8. Dashboard updates automatically.
9. User monitors irrigation remotely.

---

# Functional Modules

## Sensor Module

Responsible for collecting environmental information.

Inputs:

- Soil Moisture
- Temperature
- Humidity

Outputs:

- Digital/Analog sensor values

---

## Controller Module

Processes incoming sensor values.

Functions:

- Decision making
- Wi-Fi communication
- Relay control
- Cloud synchronization

---

## Irrigation Module

Includes:

- Relay
- Water Pump

The relay acts as an electrically controlled switch that powers the pump when irrigation is required.

---

## Cloud Module

Provides:

- Data storage
- Remote access
- Historical records
- Dashboard synchronization

---

## User Interface Module

Allows users to:

- View live sensor readings
- Monitor pump status
- Access irrigation history
- Manually control irrigation (optional)

---

# Advantages of this Architecture

- Modular and scalable
- Low-cost implementation
- Easy to maintain
- Real-time monitoring
- Remote accessibility
- Efficient water management
- Suitable for farms, gardens, and greenhouses

---

# Possible Enhancements

The architecture can be extended by integrating:

- Rain Sensor
- Water Level Sensor
- Solar Power System
- Weather API
- AI-based Irrigation Prediction
- Multiple Soil Moisture Sensors
- GSM Notifications
- LoRa Communication
- MQTT Protocol

---

# Summary

The Smart Irrigation System architecture integrates sensing, embedded processing, cloud computing, and remote monitoring into a single IoT solution. By automating irrigation decisions based on real-time soil moisture data, the system minimizes water wastage, reduces manual intervention, and improves irrigation efficiency while remaining scalable for future enhancements.
