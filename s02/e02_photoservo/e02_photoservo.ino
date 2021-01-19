#include <Servo.h>

Servo servo;

void setup() {
  pinMode(A0, INPUT_PULLUP);
  servo.attach(2); // numer pinu z żółtym kabelkiem  
}

void loop() {
  int odczyt = analogRead(A0);
  int kat = map(odczyt, 20, 600, 0, 180);
  servo.write(kat);
  delay(100);

}
