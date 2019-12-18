#include <NewPing.h>

//            trig, echo, max_distance
NewPing sonar(12, 11, 200);

void setup() {
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int odleglosc = sonar.ping_cm();
  Serial.println(odleglosc);
  delay(50);
}
