#include <ADCTouch.h>
#define PIN_COUNT 6

int refs[PIN_COUNT];
int pins[PIN_COUNT] = { A0, A1, A2, A3, A4, A5 };
int freqs[PIN_COUNT] = { 523, 622, 698, 784, 880, 988 };
void setup() {
  for(int i = 0; i< PIN_COUNT;i++) {
    refs[i] = ADCTouch.read(pins[i], 500);
    delay(10);
  }
  //Serial.begin(9600);
}

void loop() {
  bool pressed = false;
  for(int i=0;i<PIN_COUNT;i++){
    if(ADCTouch.read(pins[i])-refs[i] > 15){
      tone(8, freqs[i]*2);
      pressed = true;
    }
  }
  if(!pressed){
    noTone(8);
  }
  //Serial.println("");
  //delay(10);
}
