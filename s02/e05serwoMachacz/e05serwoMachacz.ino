
#include <Servo.h>

Servo machacz;

void setup() {
  machacz.attach(9);
}

void loop() {
  machacz.write(90);
  delay(500);
  machacz.write(110);
  delay(300);
}
