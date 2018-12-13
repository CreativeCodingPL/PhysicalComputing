// ---------------------------------------------------------------------------
// Example NewPing library sketch that does a ping about 20 times per second.
// ---------------------------------------------------------------------------

#include <NewPing.h>

#define TRIGGER_PIN  12  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     11  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 400 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

void setup() {

}

float t = 0;
void loop() {
  delay(20);                     // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.

  int dystans = sonar.ping_cm();
  // Send ping, get distance in cm and print result (0 = outside set distance range)
  int jasnosc = map(sin(t)*150, -150, 150, 0, 255);
  analogWrite(9, jasnosc);

  t = t + 0.001*(300-dystans);
}
