#include <NewPing.h>

// VCC > 5V
// D11 > Echo
// D12 > Trig
// Gnd > Gnd

NewPing sonar(12, 11, 20);

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}
void loop() {
  int distance = sonar.ping_cm();

  Serial.println(distance);
  delay(50);
}
