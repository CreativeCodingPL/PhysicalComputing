#include "CurieIMU.h"
#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(3, 6, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(9600); // initialize Serial communication
  while (!Serial);    // wait for the serial port to open

  // initialize device
  Serial.println("Initializing IMU device...");
  CurieIMU.begin();

  // Set the accelerometer range to 2G
  CurieIMU.setAccelerometerRange(2);

  pixels.begin(); // This initializes the NeoPixel library.
  for (int i = 0; i < 3; i++) 
      pixels.setPixelColor(i, pixels.Color(0, 150, 0)); // Moderately bright green color.
  pixels.show(); // This sends the updated pixel color to the hardware.

}

void loop() {
  float ax, ay, az;   //scaled accelerometer values

  // read accelerometer measurements from device, scaled to the configured range
  CurieIMU.readAccelerometerScaled(ax, ay, az);
  int ile = map(ax * 100, -100, 100, 0, 3);

  for (int i = 0; i < 3; i++) {
    if (i < ile)
      pixels.setPixelColor(i, pixels.Color(0, 150, 0)); // Moderately bright green color.
    else
      pixels.setPixelColor(i, pixels.Color(0, 0, 0)); // Moderately bright green color.
  }
  pixels.show(); // This sends the updated pixel color to the hardware.
  Serial.println(ile);
  delay(100);
}


