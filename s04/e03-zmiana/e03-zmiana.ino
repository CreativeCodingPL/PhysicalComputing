#include <Keyboard.h>


int micPin = 4;
int previousMicState = LOW;
void setup() {
  Serial.begin(9600);
  pinMode(micPin, INPUT);
  Keyboard.begin();
}

void loop() {
  //Serial.println(analogRead(A0));
  //Serial.println();
  int micState = digitalRead(micPin);
  if(micState == HIGH && previousMicState == LOW){
    Keyboard.write('a');
  }
  previousMicState = micState;
}
