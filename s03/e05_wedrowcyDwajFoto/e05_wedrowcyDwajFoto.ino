#include <Adafruit_NeoPixel.h>


//ile diod, na jakim pinie, jaki typ kontrolera diody
Adafruit_NeoPixel strip = Adafruit_NeoPixel(11, 6, NEO_GRBW + NEO_KHZ800);
int wedrowiec1 = 0;
int wedrowiec2 = 0;

void setup() {
  strip.setBrightness(50);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  pinMode(A0, INPUT_PULLUP);
  pinMode(A1, INPUT_PULLUP);
}

void loop() {
  wedrowiec1 = map(analogRead(A0), 500, 0, 0, strip.numPixels()-1);
  wedrowiec2 = map(analogRead(A1), 500, 0, strip.numPixels()-1, 0);
  for (int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, 0);
    if(i == wedrowiec1) strip.setPixelColor(i,strip.Color(0, 0, 0, 80));
    if(i == wedrowiec2) strip.setPixelColor(i,strip.Color(255, 0, 0, 0));
    if(wedrowiec1 == wedrowiec2) strip.setPixelColor(wedrowiec1,strip.Color(255, 0, 0, 80));
  }
  strip.show();
  delay(30);
}


