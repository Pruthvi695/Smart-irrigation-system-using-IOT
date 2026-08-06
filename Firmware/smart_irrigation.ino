/*
====================================================
 Smart Irrigation System using IoT
 Board : ESP32 Dev Module
 Author: Your Name
====================================================
*/

#include <WiFi.h>
#include <DHT.h>
#include "config.h"

//==============================
// DHT Sensor
//==============================
DHT dht(DHT_SENSOR_PIN, DHT_TYPE);

//==============================
// Variables
//==============================
unsigned long lastSensorRead = 0;
unsigned long lastFirebaseUpload = 0;

int soilMoistureRaw = 0;
int soilMoisturePercent = 0;

float temperature = 0;
float humidity = 0;

PumpState pumpState = PUMP_OFF;

//==============================
// Function Prototypes
//==============================
void connectWiFi();
void readSensors();
void controlPump();
void uploadData();
void printSensorData();


//====================================================
// Setup
//====================================================

void setup()
{
    Serial.begin(SERIAL_BAUD_RATE);

    pinMode(RELAY_PIN, OUTPUT);

    if (RELAY_ACTIVE_LOW)
        digitalWrite(RELAY_PIN, HIGH);
    else
        digitalWrite(RELAY_PIN, LOW);

    dht.begin();

    connectWiFi();

    Serial.println();
    Serial.println(PROJECT_NAME);
    Serial.println("System Started");
}


//====================================================
// Main Loop
//====================================================

void loop()
{
    if (millis() - lastSensorRead >= SENSOR_INTERVAL)
    {
        lastSensorRead = millis();

        readSensors();

        controlPump();

        printSensorData();
    }

    if (ENABLE_FIREBASE &&
        millis() - lastFirebaseUpload >= FIREBASE_INTERVAL)
    {
        lastFirebaseUpload = millis();

        uploadData();
    }
}


//====================================================
// WiFi Connection
//====================================================

void connectWiFi()
{
    Serial.print("Connecting to WiFi");

    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }

    Serial.println();
    Serial.println("WiFi Connected");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());
}


//====================================================
// Read Sensors
//====================================================

void readSensors()
{
    soilMoistureRaw = analogRead(SOIL_SENSOR_PIN);

    soilMoisturePercent =
        moisturePercentage(soilMoistureRaw);

    if (ENABLE_DHT11)
    {
        temperature = dht.readTemperature();

        humidity = dht.readHumidity();
    }
}


//====================================================
// Pump Control
//====================================================

void controlPump()
{
    if (!ENABLE_AUTO_PUMP)
        return;

    if (soilMoisturePercent < MOISTURE_THRESHOLD)
    {
        pumpState = PUMP_ON;

        if (RELAY_ACTIVE_LOW)
            digitalWrite(RELAY_PIN, LOW);
        else
            digitalWrite(RELAY_PIN, HIGH);
    }
    else
    {
        pumpState = PUMP_OFF;

        if (RELAY_ACTIVE_LOW)
            digitalWrite(RELAY_PIN, HIGH);
        else
            digitalWrite(RELAY_PIN, LOW);
    }
}


//====================================================
// Upload Data
//====================================================

void uploadData()
{
    /*
      Replace this section with
      Firebase upload code.

      Upload:

      soil moisture

      temperature

      humidity

      pump status

      timestamp
    */

    Serial.println("Uploading data to cloud...");
}


//====================================================
// Serial Monitor Output
//====================================================

void printSensorData()
{
    Serial.println("--------------------------------");

    Serial.print("Soil Moisture Raw : ");
    Serial.println(soilMoistureRaw);

    Serial.print("Soil Moisture (%) : ");
    Serial.print(soilMoisturePercent);
    Serial.println("%");

    Serial.print("Temperature : ");
    Serial.print(temperature);
    Serial.println(" C");

    Serial.print("Humidity : ");
    Serial.print(humidity);
    Serial.println(" %");

    Serial.print("Pump Status : ");

    if (pumpState == PUMP_ON)
        Serial.println("ON");
    else
        Serial.println("OFF");

    Serial.println("--------------------------------");
}
