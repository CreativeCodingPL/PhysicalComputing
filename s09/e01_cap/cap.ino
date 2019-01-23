#include <ADCTouch.h>

int ref;
void setup() {
  
  Serial.begin(9600);
  ref = ADCTouch.read(A0, 500);
}

void loop() {
  
  int val = ADCTouch.read(A0);
  val = val - ref;
  Serial.println(val);
  int freq = val;
  tone(3, freq, 100);
  if(val > 40){
    Serial.println("WCISNIETY");
  }
}
