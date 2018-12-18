#include <Adafruit_NeoPixel.h>


//ile diod, na jakim pinie, jaki typ kontrolera diody
Adafruit_NeoPixel strip = Adafruit_NeoPixel(11, 6, NEO_GRBW + NEO_KHZ800);

void setup() {
  strip.setBrightness(50);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {

  strip.setPixelColor(0, strip.Color(255,0,0,0));
  strip.setPixelColor(1, strip.Color(0,255,0,0));
  strip.setPixelColor(2, strip.Color(0,0,255,0));
  strip.setPixelColor(3, strip.Color(0,0,0,255));
  strip.show();
}


