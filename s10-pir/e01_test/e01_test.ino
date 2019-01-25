#include <ADCTouch.h>

int spoczynkowa;
void setup() {
  spoczynkowa = ADCTouch.read(A0, 500);
}

void loop() {
  
  int val = ADCTouch.read(A0);
  val = val - spoczynkowa;
  int freq = map(val, 0, 400, 200, 1500);
  tone(3, freq);
  Serial.println(val);
  noTone();
}
