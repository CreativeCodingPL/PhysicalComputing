
#include <Servo.h>

Servo machacz;

void setup() {
  machacz.attach(9);
  pinMode(A0, INPUT_PULLUP);
}
//boi sie jasnosci
void loop() {
  int tempo = analogRead(A0);
  machacz.write(tempo/5);
  delay(5);
}
