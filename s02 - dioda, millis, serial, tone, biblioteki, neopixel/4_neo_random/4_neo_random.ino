#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel kwadrat(16, 9, NEO_GRB + NEO_KHZ800); 

void setup() {
  kwadrat.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  kwadrat.show();            // Turn OFF all pixels ASAP
  kwadrat.setBrightness(20); // Set BRIGHTNESS to about 1/5 (max = 255)
}

void loop() {
  kwadrat.setPixelColor(random(16), kwadrat.Color(random(255),   random(255),   random(255)));       
  //kwadrat.setPixelColor(random(16), kwadrat.Color(0,   255,   0));       
  //kwadrat.setPixelColor(random(16), kwadrat.Color(100,   50,   200));       
  kwadrat.show();      //  Update strip to match
  delay(50);
}


