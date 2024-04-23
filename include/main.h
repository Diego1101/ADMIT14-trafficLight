#pragma once 

// External libraries
#include <WiFi.h>
#include <PubSubClient.h>

//Local libraries
#include "MqttStatusType.h"
#include "mqttConnection.h"
#include "Timer.h"
#include "TrafficLightStatus.h"

const unsigned int TRAFFIC_LIGH_YELLOW = 1000;
const unsigned int TRAFFIC_LIGH_INTERVAL = 8000;
void handleLightChange();