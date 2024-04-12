#pragma once

#include "main.h"

#ifndef _MQTTCLIENT_H_
#define _MQTTCLIENT_H_

// Constants
const String WIFI_SSID = "Plg";
const String WIFI_PASSWORD = "dnuW0JvW";
const int MAX_TIMEOUT = 10000;
const int RETRY_DELAY = 500;

const uint16_t MQTT_PORT = 1883; 
const String MQTT_HOST = "test.mosquitto.org";

// Functions
mqtt_status initMqttConnection();
mqtt_status connectToWiFi();
mqtt_status checkBrokerConnection();
void callback(char* topic, byte* message, unsigned int length);

#endif /* _MQTTCLIENT_H_ */