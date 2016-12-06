#include "CurieIMU.h"
#include <Adafruit_NeoPixel.h>
int NUM_PIXEL = 5;
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUM_PIXEL, 6, NEO_GRB + NEO_KHZ800);
bool ledStatus = false;

void setup() {
  Serial.begin(9600); // initialize Serial communication
  while (!Serial) ;   // wait for serial port to connect.
  // Initialise the IMU
  CurieIMU.begin();
  CurieIMU.attachInterrupt(eventCallback);

  // Increase Accelerometer range to allow detection of stronger taps (< 4g)
  CurieIMU.setAccelerometerRange(4);

  // Reduce threshold to allow detection of weaker taps (>= 750mg)
  CurieIMU.setDetectionThreshold(CURIE_IMU_TAP, 50); // (750mg)

  // Enable Double-Tap detection
  CurieIMU.interrupts(CURIE_IMU_TAP);

  Serial.println("IMU initialization complete, waiting for events...");
  pixels.begin(); // This initializes the NeoPixel library.
  for (int i = 0; i < NUM_PIXEL; i++)
    pixels.setPixelColor(i, pixels.Color(0, 0, 0)); // Moderately bright green color.
  pixels.show(); // This sends the updated pixel color to the hardware.

}

void loop() {
  if (ledStatus) {
    for (int i = 0; i < NUM_PIXEL; i++) {
      pixels.setPixelColor(i, pixels.Color(0, 200, 0));
    }
    pixels.show(); // This sends the updated pixel color to the hardware.
    ledStatus = false;
    delay(500);
    for (int i = 0; i < NUM_PIXEL; i++) {
      pixels.setPixelColor(i, pixels.Color(0, 0, 0));
    }
    pixels.show(); // This sends the updated pixel color to the hardware.
    
  }
}

static void eventCallback()
{
  if (CurieIMU.getInterruptStatus(CURIE_IMU_TAP)) {
    if (CurieIMU.tapDetected(X_AXIS, NEGATIVE)) {
      Serial.println("Tap detected on negative X-axis");
      ledStatus = true;
    }
    if (CurieIMU.tapDetected(X_AXIS, POSITIVE)) {
      Serial.println("Tap detected on positive X-axis");
      ledStatus = true;
    }
    if (CurieIMU.tapDetected(Y_AXIS, NEGATIVE)) {
      Serial.println("Tap detected on negative Y-axis");
      ledStatus = true;
    }
    if (CurieIMU.tapDetected(Y_AXIS, POSITIVE)) {
      Serial.println("Tap detected on positive Y-axis");
      ledStatus = true;
    }
    if (CurieIMU.tapDetected(Z_AXIS, NEGATIVE)) {
      Serial.println("Tap detected on negative Z-axis");
      ledStatus = true;
    }
    if (CurieIMU.tapDetected(Z_AXIS, POSITIVE)) {
      Serial.println("Tap detected on positive Z-axis");
      ledStatus = true;
    }
  }
}
