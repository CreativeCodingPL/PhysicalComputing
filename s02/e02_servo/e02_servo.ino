#include <Servo.h>

Servo servo;

void setup() {
  servo.attach(2); // numer pinu z żółtym kabelkiem  
}

void loop() {
  servo.write(0);
  delay(1000);
  servo.write(180);
  delay(1000);

}
