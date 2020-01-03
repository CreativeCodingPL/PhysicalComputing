#include <Adafruit_NeoPixel.h>

#define NUMPIXELS 4 
#define NEOPIXEL_PIN 6

Adafruit_NeoPixel pixels(NUMPIXELS, NEOPIXEL_PIN, NEO_GRB + NEO_KHZ800);

int sensorVal = 0;

void setup() {

  pixels.begin();
  Serial.begin(9600);

}

void loop() {

  sensorVal = analogRead(A0);
  Serial.println( sensorVal );
  
  int redVal = map( sensorVal, 40, 700, 0, 255 );
  int blueVal = map( sensorVal, 40, 700, 255, 0 );

  pixels.clear(); 
  
  for(int i=0; i<NUMPIXELS; i++) { 

    pixels.setPixelColor(i, pixels.Color( redVal, 0 ,blueVal ) );
    //delay(500); // Pause before next pass through loop
    
  }

  pixels.show();

   
}
