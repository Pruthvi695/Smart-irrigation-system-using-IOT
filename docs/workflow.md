# 🔄 System Workflow

## Overview

The Smart Irrigation System operates by continuously monitoring soil moisture and environmental conditions. Based on predefined threshold values, the ESP32 automatically controls the irrigation pump and uploads sensor data to the cloud for remote monitoring.

The entire process is automated, requiring minimal human intervention while ensuring efficient water usage.

---

# Workflow Diagram

```text
                    START
                      │
                      ▼
         Power ON the ESP32 Board
                      │
                      ▼
      Initialize Wi-Fi & Sensor Modules
                      │
                      ▼
      Connect to Firebase Cloud Database
                      │
                      ▼
      Read Soil Moisture Sensor Value
                      │
                      ▼
 Read Temperature & Humidity from DHT11
                      │
                      ▼
      Upload Sensor Data to Firebase
                      │
                      ▼
 Compare Soil Moisture with Threshold
                      │
         ┌────────────┴────────────┐
         │                         │
         ▼                         ▼
 Moisture < Threshold?           NO
         │                         │
        YES                        │
         │                         │
         ▼                         ▼
   Turn Relay ON             Keep Pump OFF
         │                         │
         ▼                         │
   Start Water Pump                │
         │                         │
         ▼                         │
 Monitor Soil Moisture Continuously│
         │                         │
         ▼                         │
 Moisture ≥ Threshold?             │
         │                         │
        YES                        │
         │                         │
         ▼                         │
    Turn Relay OFF                 │
         │                         │
         ▼                         ▼
    Stop Water Pump
         │
         ▼
 Update Pump Status to Firebase
         │
         ▼
 Dashboard Displays Live Data
         │
         ▼
     Wait Few Seconds
         │
         ▼
      Repeat the Process
```

---

# Step-by-Step Workflow

## Step 1: System Initialization

After powering the ESP32, the firmware initializes:

- Wi-Fi module
- Soil moisture sensor
- DHT11 sensor
- Relay module
- Firebase connection

The system verifies that all peripherals are functioning before entering the monitoring loop.

---

## Step 2: Network Connection

The ESP32 connects to the configured Wi-Fi network.

Once connected:

- IP address is assigned.
- Internet connectivity is verified.
- Firebase authentication is completed.

If the connection fails, the system repeatedly attempts to reconnect.

---

## Step 3: Sensor Data Acquisition

The ESP32 reads data from:

### Soil Moisture Sensor

Provides the moisture level of the soil.

### DHT11 Sensor

Measures:

- Ambient Temperature (°C)
- Relative Humidity (%)

These values are stored in memory for processing.

---

## Step 4: Cloud Synchronization

The collected sensor values are uploaded to Firebase.

Uploaded parameters include:

- Soil Moisture
- Temperature
- Humidity
- Pump Status
- Timestamp

This allows remote monitoring through the dashboard.

---

## Step 5: Decision Making

The ESP32 compares the current soil moisture reading with a predefined threshold.

Example:

- Threshold = 35%

Decision logic:

- If moisture < 35%, irrigation is required.
- If moisture ≥ 35%, irrigation is not required.

---

## Step 6: Automatic Irrigation

If the soil is dry:

- Relay module is activated.
- Water pump starts.
- Irrigation begins.

The pump continues operating until the desired moisture level is reached.

---

## Step 7: Continuous Monitoring

Even while the pump is running:

- Soil moisture is measured continuously.
- Temperature is updated.
- Humidity is updated.
- Data is uploaded periodically.

This prevents overwatering.

---

## Step 8: Pump Shutdown

Once the soil moisture reaches the threshold:

- Relay is turned OFF.
- Water pump stops.
- Pump status is updated in Firebase.

---

## Step 9: Remote Monitoring

The dashboard displays:

- Live soil moisture
- Temperature
- Humidity
- Pump status
- Historical readings (if enabled)

Users can monitor the system from anywhere with internet access.

---

## Step 10: Repeat Cycle

After a short delay (for example, every 5–10 seconds), the ESP32 repeats the monitoring process.

This continuous loop ensures that irrigation decisions are always based on the latest sensor data.

---

# Workflow Summary

| Step | Action |
|------|--------|
| 1 | Initialize ESP32 and sensors |
| 2 | Connect to Wi-Fi |
| 3 | Connect to Firebase |
| 4 | Read sensor values |
| 5 | Upload data to the cloud |
| 6 | Compare moisture with threshold |
| 7 | Start pump if soil is dry |
| 8 | Stop pump when moisture is sufficient |
| 9 | Update dashboard |
| 10 | Repeat monitoring cycle |

---

# Key Benefits of the Workflow

- Fully automated irrigation
- Continuous environmental monitoring
- Real-time cloud synchronization
- Efficient water usage
- Reduced manual intervention
- Easy scalability for multiple irrigation zones

---

# Future Workflow Enhancements

The workflow can be extended with additional features such as:

- Weather forecast integration to avoid watering before rainfall.
- Water level sensing to prevent dry running of the pump.
- Multiple irrigation zones with independent control.
- SMS or email alerts for system faults.
- AI-based irrigation scheduling using historical sensor data.
- Solar-powered operation with battery monitoring.

---

# Conclusion

The workflow of the Smart Irrigation System ensures that irrigation decisions are made automatically using real-time sensor data. By integrating ESP32, environmental sensors, cloud connectivity, and relay-controlled pumping, the system provides an efficient, reliable, and scalable solution for modern smart agriculture.
