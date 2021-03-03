#include <ADCTouch.h>

int ref;
int pin = A0;
void setup() {
  ref = ADCTouch.read(pin, 500);
}

void loop() {
  Serial.println(ADCTouch.read(pin)-ref);
  delay(100);
}
