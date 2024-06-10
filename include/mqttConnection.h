#pragma once

#include "main.h"

#ifndef _MQTTCLIENT_H_
#define _MQTTCLIENT_H_

// Constants
const String WIFI_SSID = "FRITZ!Box 7530 ZP";
const String WIFI_PASSWORD = "22454622954454611891";
const int MAX_TIMEOUT = 10000;
const int RETRY_DELAY = 500;

const uint16_t MQTT_PORT = 1883; 
const String MQTT_HOST = "raspberrypi.local";
// const String MQTT_HOST = "mqtt3.thingspeak.com";
const String MQTT_CLIENTID = "MyEMAhMkEAI4KgcWOSY0DDw";
const String MQTT_USER = "MyEMAhMkEAI4KgcWOSY0DDw";
const String MQTT_PASS = "xHBnVTTkNU3wstEf/Bnil7mV";

//Topic info
const String TOPIC = "trafficLight/info";

// Functions
void callback(char* topic, byte* message, unsigned int length);
mqtt_status initMqttConnection();
mqtt_status connectToWiFi();
mqtt_status checkBrokerConnection();
void sendMessage(unsigned int tlStatus, unsigned int timeChange);

#endif /* _MQTTCLIENT_H_ */
