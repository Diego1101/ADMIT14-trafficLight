#include <Arduino.h>
#include "main.h"

MqttClient mqttClient;

void setup() {
  Serial.begin(9600);
  pinMode(27, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(12, OUTPUT);

  mqttClient.init();
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
