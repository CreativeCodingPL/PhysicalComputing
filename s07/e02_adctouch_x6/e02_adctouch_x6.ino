#include <ADCTouch.h>
#define PIN_COUNT 6

int refs[PIN_COUNT];
int pins[PIN_COUNT] = { A0, A1, A2, A3, A4, A5 };
void setup() {
  for(int i = 0; i< PIN_COUNT;i++){
    refs[i] = ADCTouch.read(pins[i], 500);
    delay(10);
  }
  Serial.begin(9600);
}

void loop() {
  for(int i=0;i<PIN_COUNT;i++){
    Serial.print(ADCTouch.read(pins[i])-refs[i]);
    Serial.print(" ");
  }
  Serial.println("");
  delay(10);
}
