# 📊 IoT Dashboard Design

## Overview

The Smart Irrigation Dashboard provides a centralized interface for monitoring environmental conditions and controlling irrigation remotely. It displays live sensor readings, pump status, historical trends, and system health in real time.

The dashboard is designed to be simple, responsive, and accessible from both desktop and mobile devices.

---

# Dashboard Objectives

The dashboard allows users to:

- Monitor soil moisture in real time
- View temperature and humidity
- Check irrigation pump status
- Turn the pump ON or OFF manually (optional)
- View historical sensor data
- Monitor system connectivity
- Track water usage statistics

---

# Dashboard Layout

```text
+-------------------------------------------------------------+
|               SMART IRRIGATION SYSTEM                       |
+-------------------------------------------------------------+

+-------------+-------------+-------------+------------------+
| Moisture    | Temperature | Humidity    | Pump Status      |
|    42 %     |   28.5 °C   |    63 %     |      ON          |
+-------------+-------------+-------------+------------------+

+-------------------------------------------------------------+
|                    Soil Moisture Gauge                      |
|                         42 %                                |
+-------------------------------------------------------------+

+-------------------------------------------------------------+
|                  Moisture History Graph                     |
+-------------------------------------------------------------+

+-------------------------------------------------------------+
| Temperature & Humidity Trend                               |
+-------------------------------------------------------------+

+-------------------------------------------------------------+
|                 Manual Pump Control                         |
|             [ START ]      [ STOP ]                         |
+-------------------------------------------------------------+

+-------------------------------------------------------------+
| Last Updated : 06 Aug 2026 18:35:10                         |
| Wi-Fi Status : Connected                                    |
| Firebase Status : Connected                                 |
+-------------------------------------------------------------+
```

---

# Dashboard Widgets

## 1. Soil Moisture Card

Displays:

- Current moisture percentage
- Moisture condition

Example

```
Soil Moisture

42%

Status

Moist
```

---

## Moisture Levels

| Moisture (%) | Condition |
|--------------|-----------|
| 0–30 | Dry |
| 31–60 | Moist |
| 61–100 | Wet |

---

# 2. Temperature Card

Displays

```
Temperature

28.5°C
```

Updates every upload cycle.

---

# 3. Humidity Card

Displays

```
Humidity

63%
```

---

# 4. Pump Status

Shows current relay status.

Possible values

```
Pump ON
```

or

```
Pump OFF
```

Status updates automatically after each irrigation cycle.

---

# 5. Moisture Gauge

A circular gauge provides a quick visual representation of soil moisture.

Example

```text
           100%

      ┌─────────────┐
      │             │
      │     42%     │
      │             │
      └─────────────┘

             Dry
```

Recommended colors

- Green → Wet
- Yellow → Moderate
- Red → Dry

---

# 6. Moisture History

A line chart displaying previous readings.

Example

```text
Moisture %

80 ┤
70 ┤
60 ┤
50 ┤
40 ┤      ●
30 ┤   ●
20 ┤ ●
10 ┤____________________________

    10AM 12PM 2PM 4PM 6PM
```

Purpose

- Observe irrigation trends
- Detect sensor anomalies
- Evaluate irrigation efficiency

---

# 7. Temperature Trend

Displays temperature over time.

Useful for

- Greenhouses
- Weather monitoring
- Crop analysis

---

# 8. Humidity Trend

Displays humidity variation during the day.

Helps identify:

- Environmental changes
- Irrigation effectiveness

---

# 9. Manual Pump Control

Buttons

```
START PUMP
```

```
STOP PUMP
```

These controls are optional.

If enabled:

- Command is sent to Firebase.
- ESP32 reads the updated command.
- Relay changes state.
- Dashboard reflects the new status.

---

# 10. Device Status

Shows

```
Wi-Fi

Connected
```

```
Firebase

Connected
```

```
ESP32

Online
```

---

# 11. Last Synchronization

Displays

```
Last Updated

06-Aug-2026

18:35:10
```

---

# Dashboard Color Scheme

| Component | Suggested Color |
|-----------|-----------------|
| Background | White |
| Moisture Card | Green |
| Temperature | Orange |
| Humidity | Blue |
| Pump ON | Green |
| Pump OFF | Red |
| Charts | Blue/Green |

---

# Mobile Dashboard

The dashboard should adapt to smaller screens.

Recommended layout

```text
Moisture

Temperature

Humidity

Pump

Gauge

Charts

Buttons
```

Cards should stack vertically for better readability.

---

# Dashboard Data Mapping

| Firebase Path | Dashboard Widget |
|---------------|------------------|
| `/SmartIrrigation/moisture` | Moisture Card |
| `/SmartIrrigation/temperature` | Temperature Card |
| `/SmartIrrigation/humidity` | Humidity Card |
| `/SmartIrrigation/pumpStatus` | Pump Status |
| `/SmartIrrigation/timestamp` | Last Updated |

---

# Dashboard Refresh

Recommended refresh interval

```
5 seconds
```

The dashboard updates automatically whenever Firebase data changes.

---

# User Notifications

The dashboard may display alerts such as:

```
Soil is Dry

Pump Started
```

```
Soil Moisture Restored

Pump Stopped
```

```
Wi-Fi Disconnected
```

```
Firebase Offline
```

---

# Future Dashboard Enhancements

The dashboard can be extended with:

- Rain forecast widget
- Water tank level
- Water flow meter
- AI irrigation recommendations
- Monthly water usage reports
- Multiple farm support
- GPS-based field monitoring
- Dark mode
- Export data to CSV
- Multi-language interface

---

# Dashboard Technology Options

| Technology | Purpose |
|------------|---------|
| Firebase Realtime Database | Cloud backend |
| Blynk IoT | Mobile dashboard |
| Node-RED Dashboard | Web interface |
| Flutter | Android/iOS app |
| React.js | Web dashboard |
| Chart.js | Data visualization |

---

# Summary

The Smart Irrigation Dashboard provides a comprehensive interface for monitoring and controlling the irrigation system. By combining real-time sensor data, cloud synchronization, graphical visualization, and optional manual controls, it enables efficient irrigation management while improving usability and decision-making for farmers and gardeners.
