#include <ADCTouch.h>

int ref0, ref1, ref2, ref3, ref4, ref5;
void setup() {
  
  Serial.begin(9600);
  ref0 = ADCTouch.read(A0, 500);
  ref1 = ADCTouch.read(A1, 500);
  ref2 = ADCTouch.read(A2, 500);
  ref3 = ADCTouch.read(A3, 500);
  ref4 = ADCTouch.read(A4, 500);
  ref5 = ADCTouch.read(A5, 500);
}

void loop() {
  int val0 = ADCTouch.read(A0) - ref0;
  int val1 = ADCTouch.read(A1) - ref1;
  int val2 = ADCTouch.read(A2) - ref2;
  int val3 = ADCTouch.read(A3) - ref3;
  int val4 = ADCTouch.read(A4) - ref4;
  int val5 = ADCTouch.read(A5) - ref5;
  
  if(val0 > 40){
    Serial.println(0);
  }
  if(val1 > 40){
    Serial.println(1);
  }
  if(val2 > 40){
    Serial.println(2);
  }
  if(val3 > 40){
    Serial.println(3);
  }
  if(val4 > 40){
    Serial.println(4);
  }
  if(val5 > 40){
    Serial.println(5);
  }
}
