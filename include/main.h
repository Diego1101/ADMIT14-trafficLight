#pragma once

#define GREEN_LED 27
#define YELLOW_LED 14
#define RED_LED 12

#define TL_ID 1

// External libraries
#include <WiFi.h>
#include <PubSubClient.h>

//Local libraries
#include "MqttStatusType.h"
#include "mqttConnection.h"
#include "Timer.h"
#include "TrafficLightStatus.h"

const unsigned int TRAFFIC_LIGH_GREEN = 10000;
const unsigned int TRAFFIC_LIGH_YELLOW = 2000;
const unsigned int TRAFFIC_LIGH_RED = 10000;
const unsigned int TRAFFIC_LIGH_PREPARE = 2000;
const unsigned int TL_INFO_SEND = 5000;
void handleLightChange();
void handleInfoSend();
