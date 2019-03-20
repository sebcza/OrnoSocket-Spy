#include "orgb417pb.h"
uint8_t GPIO_Pin = D2;
ORGB417PB receiver(digitalPinToInterrupt(GPIO_Pin), D0);
unsigned long value = 0;

void setup() {
  Serial.begin(74880); 
  delay(2000);
  Serial.println("\nReady.\n\n");
}

void loop() {
  if (receiver.has_code()) {
    if (value != receiver.code()) {
      value = receiver.code();
      Serial.print("Found: ");
      Serial.print(value);
      Serial.print(" - ");
      Serial.println(value, BIN);
    }
    receiver.clear_code();
  }
}
