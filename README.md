# 🌱 Smart Irrigation System using IoT

An IoT-enabled Smart Irrigation System that automates watering by monitoring real-time soil moisture levels. The system uses an ESP32 microcontroller to collect environmental data, upload it to the cloud, and automatically control irrigation, reducing water wastage while improving crop health.

---

# 📖 Table of Contents

- Project Overview
- Features
- Motivation
- Technologies Used
- System Architecture
- Hardware Components
- Software Stack
- Working Principle
- Installation
- Usage
- Project Structure
- Future Enhancements
- Contributors

---

# 🌾 Project Overview

Agriculture consumes approximately **70% of the world's freshwater resources**. Traditional irrigation methods often lead to excessive water usage due to manual operation and a lack of real-time monitoring.

The Smart Irrigation System addresses this problem by automating irrigation based on live soil moisture readings. Using IoT technology, farmers can monitor environmental conditions remotely and control irrigation through an online dashboard.

This project demonstrates how embedded systems, cloud computing, and wireless communication can be integrated into a low-cost precision agriculture solution.

---

# ✨ Features

- 🌱 Automatic irrigation
- 💧 Soil moisture monitoring
- 🌡 Temperature & humidity monitoring
- ☁ Cloud connectivity
- 📱 Remote dashboard
- 📊 Live sensor visualization
- 🔔 Notification support
- 📈 Historical data logging
- ⚡ Low power operation
- 🌍 Water conservation

---

# 🎯 Motivation

Traditional irrigation systems rely heavily on manual observation, leading to:

- Water wastage
- Uneven irrigation
- Higher labour costs
- Reduced crop productivity

This project automates irrigation decisions using sensor data, minimizing human intervention while ensuring optimal water usage.

---

# 🛠 Technologies Used

## Hardware

- ESP32 Development Board
- Capacitive Soil Moisture Sensor
- DHT11 Sensor
- Relay Module
- 12V DC Water Pump
- Power Supply

## Software

- Arduino IDE
- C++
- Firebase Realtime Database
- Blynk IoT
- Git
- GitHub

---

# 🏗 System Architecture

```

         Soil Moisture Sensor
                 │
                 ▼
              ESP32
                 │
      ┌──────────┴──────────┐
      ▼                     ▼
 Relay Module           WiFi Module
      │                     │
      ▼                     ▼
 Water Pump          Firebase Cloud
                             │
                             ▼
                     Mobile Dashboard

```

---

# ⚙ Hardware Components

| Component | Quantity |
|------------|-----------|
| ESP32 | 1 |
| Soil Moisture Sensor | 1 |
| DHT11 | 1 |
| Relay Module | 1 |
| Water Pump | 1 |
| Power Adapter | 1 |

---

# 💻 Software Stack

Arduino IDE → ESP32 Firmware → Firebase → Dashboard

---

# ⚡ Working Principle

1. ESP32 reads soil moisture values.

2. Moisture level is compared with the threshold.

3. If soil is dry,

   Pump turns ON.

4. Soil moisture is continuously monitored.

5. Once the threshold is reached,

   Pump turns OFF.

6. Sensor readings are uploaded to Firebase.

7. Users monitor data using a mobile dashboard.

---

# 📂 Project Structure

```

smart-irrigation-system-iot/
│
├── docs/
├── firmware/
├── hardware/
├── cloud/
├── images/
├── README.md
└── LICENSE

```

---

# 🚀 Installation

Clone the repository

```bash
git clone https://github.com/yourusername/smart-irrigation-system-iot.git
```

Open

```
firmware/smart_irrigation.ino
```

Upload the code to ESP32 using Arduino IDE.

Configure WiFi credentials inside

```
config.h
```

Run the project.

---

# 📊 Expected Output

- Live moisture percentage
- Automatic pump control
- Cloud logging
- Mobile monitoring
- Water-saving analytics



# 🔮 Future Enhancements

- Weather API integration
- AI-based irrigation prediction
- Solar-powered operation
- Multi-field monitoring
- Crop recommendation system
- SMS/WhatsApp alerts



# 🤝 Contributors

- Pruthvika N V
- Sriya G
- Shilpa T S
- Sindhu
