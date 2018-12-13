#include <Adafruit_NeoPixel.h>

int NUMPIXELS = 5;
int PIN = 6;
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pixels.begin(); // This initializes the NeoPixel library.
}

void loop() {
  for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i, pixels.Color(random(100),random(100),random(100))); // Moderately bright green color.
    pixels.show(); // This sends the updated pixel color to the hardware.
    delay(300); // Delay for a period of time (in milliseconds).
  }
  pixels.clear();
  pixels.show();
  delay(700);
 }
