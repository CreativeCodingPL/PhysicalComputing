#include <Adafruit_NeoPixel.h>
#define LED_PIN 6
#define LED_COUNT 8

int pozycja = 0;

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.setBrightness(50);
}

void loop() {
  strip.clear();
  strip.setPixelColor(pozycja, strip.Color(255, 0, 0));
  strip.show();
  pozycja = (pozycja+1)%LED_COUNT;
  delay(100);
}
