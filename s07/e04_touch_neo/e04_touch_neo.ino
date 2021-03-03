#include <ADCTouch.h>
#include <Adafruit_NeoPixel.h>
#define NUMPIXELS 8
#define PIN_COUNT 6

int refs[PIN_COUNT];
int pins[PIN_COUNT] = { A0, A1, A2, A3, A4, A5 };
int vals[PIN_COUNT];

Adafruit_NeoPixel pixels(NUMPIXELS, 6, NEO_GRB + NEO_KHZ800);

void setup() {

  for (int i = 0; i < PIN_COUNT; i++) {
    refs[i] = ADCTouch.read(pins[i], 500);
    delay(10);
  }
  pixels.begin();
  Serial.begin(9600);
}

void loop() {
  pixels.clear();
  for (int i = 0; i < PIN_COUNT; i++) {
    vals[i] = ADCTouch.read(pins[i]) - refs[i];
    Serial.print(vals[i]);
    Serial.print(" ");
  }
  int maxLed = map(vals[0],0,400,0,NUMPIXELS);
  int brightness = map(vals[1], 0, 400, 0, 255);
  for(int i=0;i<NUMPIXELS;i++){
    if(i<maxLed) {
      pixels.setPixelColor(i, pixels.Color(brightness, 0, 0));
    }
    else {
      pixels.setPixelColor(i, pixels.Color(0, 0, 0));
    }
  }
  Serial.println("");
  pixels.show();
}
