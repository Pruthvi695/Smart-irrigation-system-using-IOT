#ifndef CONFIG_H
#define CONFIG_H

/****************************************************
 * Smart Irrigation System using IoT
 * Configuration File
 *
 * Author : Your Name
 * Board  : ESP32 Dev Module
 * IDE    : Arduino IDE 2.x
 ****************************************************/

//====================================================
// Wi-Fi Configuration
//====================================================

// Replace with your Wi-Fi credentials

#define WIFI_SSID       "YOUR_WIFI_NAME"
#define WIFI_PASSWORD   "YOUR_WIFI_PASSWORD"


//====================================================
// Firebase Configuration
//====================================================

// Replace these values with your Firebase project details

#define API_KEY         "YOUR_FIREBASE_API_KEY"

#define DATABASE_URL    "https://your-project-id-default-rtdb.firebaseio.com/"

#define USER_EMAIL      "your-email@example.com"

#define USER_PASSWORD   "your-password"


//====================================================
// GPIO Pin Configuration
//====================================================

#define SOIL_SENSOR_PIN     34

#define DHT_SENSOR_PIN      4

#define RELAY_PIN           26


//====================================================
// Sensor Configuration
//====================================================

#define DHT_TYPE DHT11


//====================================================
// Moisture Threshold
//====================================================

// Soil Moisture (%)
//
// Pump ON  -> Moisture below threshold
// Pump OFF -> Moisture above threshold

const int MOISTURE_THRESHOLD = 35;


//====================================================
// Sensor Calibration
//====================================================

// Raw ADC values
// Adjust these after calibration

const int DRY_SOIL_VALUE = 3500;

const int WET_SOIL_VALUE = 1200;


//====================================================
// Pump Configuration
//====================================================

const bool RELAY_ACTIVE_LOW = true;


//====================================================
// Timing Configuration
//====================================================

// Read sensors every 5 seconds

const unsigned long SENSOR_INTERVAL = 5000;

// Upload data every 5 seconds

const unsigned long FIREBASE_INTERVAL = 5000;

// Retry Wi-Fi every 10 seconds

const unsigned long WIFI_RETRY_INTERVAL = 10000;


//====================================================
// Serial Monitor
//====================================================

const long SERIAL_BAUD_RATE = 115200;


//====================================================
// Project Information
//====================================================

#define PROJECT_NAME "Smart Irrigation System"

#define VERSION "1.0.0"

#define AUTHOR "Your Name"


//====================================================
// Feature Flags
//====================================================

// Enable or disable optional features

#define ENABLE_FIREBASE      true

#define ENABLE_DHT11         true

#define ENABLE_SERIAL_LOG    true

#define ENABLE_AUTO_PUMP     true


//====================================================
// Pump Status
//====================================================

enum PumpState
{
    PUMP_OFF = 0,
    PUMP_ON = 1
};


//====================================================
// Helper Function
//====================================================

// Convert raw ADC value to moisture percentage

inline int moisturePercentage(int rawValue)
{
    rawValue = constrain(rawValue, WET_SOIL_VALUE, DRY_SOIL_VALUE);

    return map(rawValue,
               DRY_SOIL_VALUE,
               WET_SOIL_VALUE,
               0,
               100);
}

#endif
