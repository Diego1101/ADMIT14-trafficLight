#pragma once 

// External libraries
#include <WiFi.h>
#include <PubSubClient.h>

//Local libraries
#include "MqttStatusType.h"
#include "mqttConnection.h"
#include "Timer.h"
#include "TrafficLightStatus.h"

const unsigned int TRAFFIC_LIGH_GREEN = 5000;
const unsigned int TRAFFIC_LIGH_YELLOW = 2000;
const unsigned int TRAFFIC_LIGH_RED = 5000;
const unsigned int TRAFFIC_LIGH_PREPARE = 2000;
void handleLightChange();