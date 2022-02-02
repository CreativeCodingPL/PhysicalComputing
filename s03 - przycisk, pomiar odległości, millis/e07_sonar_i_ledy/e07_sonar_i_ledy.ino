#include <NewPing.h>

// VCC > 5V
// D11 > Echo
// D12 > Trig
// Gnd > Gnd

NewPing sonar(12, 11, 20);

int minLed = 2;
int maxLed = 5;

void setup() {
  Serial.begin(9600);

  for(int i = minLed; i <= maxLed; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {

  int distance = sonar.ping_cm();
  int numLeds = map(distance, 4, 10, minLed, maxLed);

  Serial.println(numLeds);

  for(int i = minLed; i <= maxLed; i++) {
    digitalWrite(i, LOW);
  }

  for(int i = minLed; i <= numLeds; i++) {
    digitalWrite(i, HIGH);
  }

  delay(100);

}
