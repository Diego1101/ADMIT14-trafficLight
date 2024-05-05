#include <Arduino.h>
#include "main.h"

mqtt_status Connection_Status = MS_UNINITIALIZED;
Timer Timer_LightChange(TRAFFIC_LIGH_GREEN);
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
}

void handleLightChange() {

  if(Timer_LightChange.isExpired()) {
    switch (Light_Status) {
    case TL_GREEN:
        digitalWrite(27, LOW);
        digitalWrite(14, HIGH);
        digitalWrite(12, LOW);
        Timer_LightChange.setDuration(TRAFFIC_LIGH_YELLOW);
        Light_Status = TL_YELLOW;
      break;

      case TL_YELLOW:
        digitalWrite(27, LOW);
        digitalWrite(14, LOW);
        digitalWrite(12, HIGH);
        Timer_LightChange.setDuration(TRAFFIC_LIGH_RED);
        Light_Status = TL_RED;
      break;

      case TL_RED:
        digitalWrite(27, LOW);
        digitalWrite(14, HIGH);
        digitalWrite(12, HIGH);
        Timer_LightChange.setDuration(TRAFFIC_LIGH_PREPARE);
        Light_Status = TL_PREPARE;
      break;

      case TL_PREPARE:
        digitalWrite(27, HIGH);
        digitalWrite(14, LOW);
        digitalWrite(12, LOW);
        Timer_LightChange.setDuration(TRAFFIC_LIGH_GREEN);
        Light_Status = TL_GREEN;
      break;
    
    default:
      break;
    }
    Timer_LightChange.startNow();
  }
}