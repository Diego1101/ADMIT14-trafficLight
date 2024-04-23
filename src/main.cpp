#include <Arduino.h>
#include "main.h"

mqtt_status Connection_Status = MS_UNINITIALIZED;
Timer Timer_LightChange(TRAFFIC_LIGH_INTERVAL);
Timer Timer_YellowLight(TRAFFIC_LIGH_YELLOW);
TL_STATUS Light_Status = TL_GREEN;

void setup() {
  Serial.begin(9600);
  pinMode(27, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(12, OUTPUT);

  //Start with green
  digitalWrite(27, HIGH);
  digitalWrite(14, LOW);
  digitalWrite(12, LOW);

  Timer_LightChange.startNow();
}

void loop() {
  Connection_Status = initMqttConnection();

  handleLightChange();
  // switch (Connection_Status) {
  // case MS_MQTT_CONNECTED:
  //   digitalWrite(27, HIGH);
  //   digitalWrite(14, LOW);
  //   digitalWrite(12, LOW);
  //   break;

  // case MS_WIFI_FAILED:
  //   digitalWrite(27, LOW);
  //   digitalWrite(14, HIGH);
  //   digitalWrite(12, LOW);
  //   break;

  // case MS_MQTT_FAILED:
  //   digitalWrite(27, LOW);
  //   digitalWrite(14, LOW);
  //   digitalWrite(12, HIGH);
  //   break;
  
  // default:
  //   break;
  // }
}

void handleLightChange() {

  if (Timer_LightChange.isExpired() && Timer_LightChange.isActive()) {
    Timer_LightChange.deactivate();

    if (Light_Status == TL_GREEN) {
        digitalWrite(27, LOW);
        digitalWrite(14, HIGH);
        digitalWrite(12, LOW);
        Light_Status = TL_YELLOW;
    } else if (Light_Status == TL_RED) {
        digitalWrite(27, LOW);
        digitalWrite(14, HIGH);
        digitalWrite(12, HIGH);
        Light_Status = TL_PREPARE;
    }

    Timer_YellowLight.startNow();
  }

  if (Timer_YellowLight.isExpired() && Timer_YellowLight.isActive()) {
    Timer_YellowLight.deactivate();

    if (Light_Status == TL_YELLOW) {
        digitalWrite(27, LOW);
        digitalWrite(14, LOW);
        digitalWrite(12, HIGH);
        Light_Status = TL_RED;
    } else if (Light_Status == TL_PREPARE) {
        digitalWrite(27, HIGH);
        digitalWrite(14, LOW);
        digitalWrite(12, LOW);
        Light_Status = TL_GREEN;
    }

    Timer_LightChange.startNow();
  }
}