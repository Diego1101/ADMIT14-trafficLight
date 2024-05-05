#include <Arduino.h>
#include "main.h"

mqtt_status Connection_Status = MS_UNINITIALIZED;
Timer Timer_LightChange(TRAFFIC_LIGH_GREEN);
Timer Timer_Info_Send(TL_INFO_SEND);
TL_STATUS Light_Status = TL_GREEN;

void setup() {
  Serial.begin(9600);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);

  //Start with green
  digitalWrite(GREEN_LED, HIGH);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(RED_LED, LOW);

  Timer_LightChange.startNow();
  Timer_Info_Send.startNow();
}

void loop() {
  Connection_Status = initMqttConnection();
  handleLightChange();
  handleInfoSend();
}

void handleLightChange() {

  if(Timer_LightChange.isExpired()) {
    switch (Light_Status) {
    case TL_GREEN:
        digitalWrite(GREEN_LED, LOW);
        digitalWrite(YELLOW_LED, HIGH);
        digitalWrite(RED_LED, LOW);
        Timer_LightChange.setDuration(TRAFFIC_LIGH_YELLOW);
        Light_Status = TL_YELLOW;
      break;

      case TL_YELLOW:
        digitalWrite(GREEN_LED, LOW);
        digitalWrite(YELLOW_LED, LOW);
        digitalWrite(RED_LED, HIGH);
        Timer_LightChange.setDuration(TRAFFIC_LIGH_RED);
        Light_Status = TL_RED;
      break;

      case TL_RED:
        digitalWrite(GREEN_LED, LOW);
        digitalWrite(YELLOW_LED, HIGH);
        digitalWrite(RED_LED, HIGH);
        Timer_LightChange.setDuration(TRAFFIC_LIGH_PREPARE);
        Light_Status = TL_PREPARE;
      break;

      case TL_PREPARE:
        digitalWrite(GREEN_LED, HIGH);
        digitalWrite(YELLOW_LED, LOW);
        digitalWrite(RED_LED, LOW);
        Timer_LightChange.setDuration(TRAFFIC_LIGH_GREEN);
        Light_Status = TL_GREEN;
      break;
    
    default:
      break;
    }
    Timer_LightChange.startNow();
  }
}

void handleInfoSend() {
  if (Timer_Info_Send.isExpired()) {
    sendMessage(Light_Status, 1000);
    Timer_Info_Send.startNow();
  }
}
