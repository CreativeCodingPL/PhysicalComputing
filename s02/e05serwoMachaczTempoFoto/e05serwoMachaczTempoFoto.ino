
#include <Servo.h>

Servo machacz;

void setup() {
  machacz.attach(9);
  pinMode(A0, INPUT_PULLUP);
}
//boi sie jasnosci
void loop() {
  int tempo = analogRead(A0);
  machacz.write(60);
  delay(tempo);
  machacz.write(120);
  delay(tempo);
}
