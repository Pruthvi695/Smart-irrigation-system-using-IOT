# 🖼️ Project Images

## Overview

This folder contains all visual assets used in the Smart Irrigation System project. These images help explain the system architecture, hardware setup, workflow, and dashboard, making the project easier to understand and reproduce.

---

# Folder Structure

```text
images/
│
├── architecture.png
├── circuit-diagram.png
├── workflow.png
├── dashboard-ui.png
├── prototype.jpg
└── README.md
```

---

# Image Descriptions

## 1. architecture.png

Illustrates the overall IoT architecture of the project.

Shows:

- ESP32
- Soil Moisture Sensor
- DHT11 Sensor
- Relay Module
- Water Pump
- Wi-Fi
- Firebase
- Dashboard

Purpose:

Provides a high-level understanding of data flow within the system.

---

## 2. circuit-diagram.png

Shows the complete hardware wiring.

Includes:

- ESP32 GPIO connections
- Soil Moisture Sensor
- DHT11 Sensor
- Relay Module
- Water Pump
- Power Supply

Purpose:

Helps users assemble the hardware correctly.

---

## 3. workflow.png

Displays the operational workflow.

Example:

```text
Start
  │
  ▼
Read Sensors
  │
  ▼
Upload Data
  │
  ▼
Compare Moisture
  │
  ├── Dry → Pump ON
  │
  └── Wet → Pump OFF
  │
  ▼
Repeat
```

Purpose:

Illustrates the firmware logic in a simple visual format.

---

## 4. dashboard-ui.png

Screenshot or mock-up of the monitoring dashboard.

Recommended widgets:

- Soil Moisture
- Temperature
- Humidity
- Pump Status
- Moisture Gauge
- Historical Charts

Purpose:

Demonstrates how users monitor the irrigation system remotely.

---

## 5. prototype.jpg

Photograph of the completed hardware prototype.

Suggested views:

- Top view
- Side view
- Close-up of ESP32
- Sensor placement
- Water pump connection

Purpose:

Shows the physical implementation of the project.

---

# Recommended Image Specifications

| Property | Recommendation |
|----------|----------------|
| Format | PNG or JPG |
| Resolution | 1920 × 1080 or higher |
| Background | Clean and uncluttered |
| Labels | Clearly annotate components where applicable |

---

# Usage in Documentation

Reference these images throughout the repository using Markdown:

```markdown
![System Architecture](../images/architecture.png)

![Circuit Diagram](../images/circuit-diagram.png)

![Workflow](../images/workflow.png)

![Dashboard](../images/dashboard-ui.png)

![Prototype](../images/prototype.jpg)
```

---

# Future Images

As the project evolves, you can add:

- Firebase database screenshots
- Serial Monitor output
- Mobile application screenshots
- Web dashboard screenshots
- Sensor calibration graphs
- Water usage charts
- Multi-zone irrigation setup
- Field deployment photographs

---

# Summary

Well-designed visuals significantly improve the readability and professionalism of the repository. They help users understand the system architecture, hardware assembly, firmware workflow, and cloud monitoring at a glance, making the project easier to learn from and replicate.
