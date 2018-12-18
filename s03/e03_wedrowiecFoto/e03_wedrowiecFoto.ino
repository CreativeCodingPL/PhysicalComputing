#include <Adafruit_NeoPixel.h>


//ile diod, na jakim pinie, jaki typ kontrolera diody
Adafruit_NeoPixel strip = Adafruit_NeoPixel(11, 6, NEO_GRBW + NEO_KHZ800);
int wedrowiec = 0;

void setup() {
  strip.setBrightness(50);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  pinMode(A0, INPUT_PULLUP);
}

void loop() {
  wedrowiec = map(analogRead(A0), 500, 100, 0, strip.numPixels()-1);
  for (int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, 0);
    if(i == wedrowiec) strip.setPixelColor(i,strip.Color(0, 0, 0, 255));
  }
  strip.show();
  delay(30);
}


