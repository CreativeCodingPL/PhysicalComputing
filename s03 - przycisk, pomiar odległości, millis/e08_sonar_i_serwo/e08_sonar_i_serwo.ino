#include <Servo.h>
#include <NewPing.h>

NewPing sonar(12, 11, 20);
Servo servo;

void setup() {
  Serial.begin(9600);
  servo.attach(2);
}

void loop() {
  int distance_cm = sonar.ping_cm();

  if (distance_cm > 0) {
    int distance = map(distance_cm, 1, 20, 0, 180);
    Serial.println(distance);
    servo.write(distance);
    delay(100);
  }

}
