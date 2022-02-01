#include <Servo.h>

Servo serwo;

void setup() {
  serwo.attach(9);
}

void loop() {
  serwo.write(0);
  delay(1000);
  serwo.write(180);
  delay(1000);
}
