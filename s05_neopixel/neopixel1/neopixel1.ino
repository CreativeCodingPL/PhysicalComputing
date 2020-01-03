#include <Adafruit_NeoPixel.h>

#define NUMPIXELS 4 
#define NEOPIXEL_PIN 6

#define BTN_1_PIN 2
#define BTN_2_PIN 3
#define BTN_3_PIN 4

Adafruit_NeoPixel pixels(NUMPIXELS, NEOPIXEL_PIN, NEO_GRB + NEO_KHZ800);

int sensorVal = 0;

bool btn1 = false;
bool btn2 = false;
bool btn3 = false;



void setup() {
  
  pixels.begin();
  Serial.begin(9600);

  pinMode( BTN_1_PIN, INPUT_PULLUP );
  pinMode( BTN_2_PIN, INPUT_PULLUP );
  pinMode( BTN_3_PIN, INPUT_PULLUP );

}

void loop() {


  Serial.println( digitalRead( BTN_1_PIN ) );
  Serial.println( digitalRead( BTN_2_PIN ) );
  Serial.println( digitalRead( BTN_3_PIN ) );
  

  sensorVal = analogRead(A0);
  //Serial.println( sensorVal );
  
  int rVal = map( sensorVal, 40, 760, 0, 255 );
  int bVal = map( sensorVal, 40, 760, 255, 0 );
  
  pixels.clear(); // Set all pixel colors to 'off'

  // The first NeoPixel in a strand is #0, second is 1, all the way up
  // to the count of pixels minus one.
  for(int i=0; i<NUMPIXELS; i++) { // For each pixel...

    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:
    pixels.setPixelColor(i, pixels.Color(rVal, 0, bVal));

    pixels.show();   // Send the updated pixel colors to the hardware.

    //delay(500); // Pause before next pass through loop
  }

}
