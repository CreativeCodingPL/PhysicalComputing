#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel strip = Adafruit_NeoPixel(8, 6, NEO_GRB + NEO_KHZ800);

int current = 0;
int dir = 1;

void setup() {
  strip.begin();
  strip.show();
}
void loop() { 
   for(int i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, 0, 0,0);
    }
    
    if(current<0 || current>strip.numPixels()-1){
     dir = -dir;
    }
    current+=dir;
    strip.setPixelColor(current, 255,0,0);
    strip.show();
    delay(50);
}
