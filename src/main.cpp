#include <Arduino.h>
#include "main.h"

mqtt_status connectionStatus = MS_UNINITIALIZED;

void setup() {
  Serial.begin(9600);
  pinMode(27, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(12, OUTPUT);

  connectionStatus = initMqttConnection();
  if (connectionStatus != MS_MQTT_CONNECTED) {
    Serial.print("Connection failed: ");
    Serial.println(connectionStatus);
  }
}

void loop() {
  digitalWrite(27, HIGH);
  digitalWrite(14, HIGH);
  digitalWrite(12, LOW);
  delay(300);
  digitalWrite(27, LOW);
  digitalWrite(12, HIGH);
  digitalWrite(14, LOW);
  delay(300);
}
