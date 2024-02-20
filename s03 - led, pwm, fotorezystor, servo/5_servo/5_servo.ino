#include <Servo.h>
Servo servo;

void setup() {
  servo.attach(9); // PWM
}

void loop() {
  servo.write(0);
  delay(100);

  servo.write(90);
  delay(100);

  servo.write(180);
  delay(100);

  servo.write(90);
  delay(100);
}
