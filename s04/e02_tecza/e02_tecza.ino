#include <Adafruit_NeoPixel.h>
#define LED_PIN 6
#define LED_COUNT 8
#define POT A0

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(9600);
  strip.begin();
  strip.setBrightness(255);
}

void loop() {
  int brightness = analogRead(POT)/4;
  // map(analogRead(POT), 0, 1023,0, 255);
  Serial.println(brightness);
  strip.clear();
  strip.setBrightness(brightness);
  int pasek = 65535/LED_COUNT;
  for(int i=0; i < LED_COUNT; i++){
    strip.setPixelColor(i, strip.ColorHSV(i*pasek));    
  }
  strip.show();
}
