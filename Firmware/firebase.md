# 🔥 Firebase Integration Guide

## Overview

Firebase Realtime Database is used as the cloud backend for the Smart Irrigation System. It stores sensor readings, irrigation status, and timestamps, enabling real-time monitoring from anywhere with an internet connection.

The ESP32 uploads sensor data periodically, while users can view live updates through a web or mobile dashboard.

---

# Why Firebase?

Firebase was selected because it provides:

- Real-time data synchronization
- Cloud-based storage
- Secure authentication
- Easy integration with ESP32
- Free tier for small projects
- Cross-platform compatibility

---

# System Architecture

```text
                    Soil Moisture Sensor
                             │
                             ▼
                          ESP32
                             │
                       Wi-Fi Network
                             │
                             ▼
                  Firebase Realtime Database
                             │
            ┌────────────────┴────────────────┐
            ▼                                 ▼
      Mobile Dashboard                 Web Dashboard
```

---

# Step 1: Create a Firebase Project

1. Sign in to the Firebase Console.
2. Click **Create Project**.
3. Enter a project name (e.g., `SmartIrrigationSystem`).
4. Continue with the default settings.
5. Wait for the project to be created.

---

# Step 2: Create a Realtime Database

1. Open your Firebase project.
2. Select **Realtime Database**.
3. Click **Create Database**.
4. Choose a region close to your location.
5. Start in **Test Mode** while developing.
6. Click **Enable**.

---

# Step 3: Obtain Project Credentials

From **Project Settings**, collect:

- API Key
- Database URL
- Project ID

These values are required in `firmware/config.h`.

Example:

```cpp
#define API_KEY "YOUR_FIREBASE_API_KEY"

#define DATABASE_URL "https://your-project-id-default-rtdb.firebaseio.com/"

#define USER_EMAIL "your-email@example.com"

#define USER_PASSWORD "your-password"
```

---

# Step 4: Database Structure

The ESP32 stores data in the following format:

```text
SmartIrrigation
│
├── moisture
│      42
│
├── temperature
│      28.6
│
├── humidity
│      63
│
├── pumpStatus
│      "ON"
│
├── timestamp
│      "2026-08-06T18:30:00Z"
```

---

# Example JSON

```json
{
  "SmartIrrigation": {
    "moisture": 42,
    "temperature": 28.6,
    "humidity": 63,
    "pumpStatus": "OFF",
    "timestamp": "2026-08-06T18:30:00Z"
  }
}
```

---

# Data Upload Process

Every upload cycle, the ESP32 sends:

- Soil moisture percentage
- Temperature
- Humidity
- Pump status
- Timestamp

Typical upload interval:

```
Every 5 seconds
```

This interval can be changed in `config.h`.

---

# Security Rules

For development:

```json
{
  "rules": {
    ".read": true,
    ".write": true
  }
}
```

⚠️ These rules are **only for testing**.

For production, enable Firebase Authentication and restrict database access appropriately.

---

# Firebase Authentication

The ESP32 authenticates using:

- Email
- Password
- API Key

These credentials should be stored securely in `config.h` and **never committed to GitHub**.

---

# Data Flow

```text
Sensors
   │
   ▼
ESP32
   │
   ▼
Read Sensor Values
   │
   ▼
Connect to Wi-Fi
   │
   ▼
Authenticate with Firebase
   │
   ▼
Upload Data
   │
   ▼
Database Updated
   │
   ▼
Dashboard Refreshes Automatically
```

---

# Cloud Features

The Firebase backend provides:

- Real-time updates
- Historical data storage
- Remote accessibility
- Automatic synchronization
- Multi-device support

---

# Example Database Paths

| Path | Description |
|------|-------------|
| `/SmartIrrigation/moisture` | Soil moisture (%) |
| `/SmartIrrigation/temperature` | Temperature (°C) |
| `/SmartIrrigation/humidity` | Relative humidity (%) |
| `/SmartIrrigation/pumpStatus` | Current pump state |
| `/SmartIrrigation/timestamp` | Last update time |

---

# Troubleshooting

| Problem | Possible Cause | Solution |
|---------|----------------|----------|
| Authentication failed | Invalid API key or user credentials | Verify values in `config.h` |
| No data in database | Wi-Fi disconnected | Check network connection |
| Upload errors | Incorrect database URL | Confirm Realtime Database URL |
| Permission denied | Database rules too restrictive | Review Firebase security rules |

---

# Future Enhancements

The Firebase integration can be extended with:

- Irrigation history logs
- User authentication
- Push notifications
- Water usage analytics
- Weather forecast integration
- Multiple field support
- Device management

---

# Summary

Firebase enables secure, cloud-based storage and real-time synchronization of sensor data collected by the ESP32. It allows users to monitor irrigation remotely while providing a scalable foundation for future smart farming features.
