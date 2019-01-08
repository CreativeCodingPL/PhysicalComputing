#include <Keyboard.h>


int micPin = 4;
void setup() {
  Serial.begin(9600);
  pinMode(micPin, INPUT);
  Keyboard.begin();
}

void loop() {
  //Serial.println(analogRead(A0));
  if(digitalRead(micPin)){
    Keyboard.write('a');
  }
}
