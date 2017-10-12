#include <Servo.h>

Servo serwus;

void setup() {

  serwus.attach(9);
  
}

float k = 0;

void loop() {
  int wartosc = 1000*sin(k);
  int jasnosc = map(wartosc, -1000, 1000, 20, 160);
  serwus.write(jasnosc);
  k = k + 0.003;
  delay(1);
}
