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

int activePixel = 0;
int mode = 0;


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
  
  if( mode == 0 ){
  
    activePixel ++;
    if( activePixel == NUMPIXELS ){
      activePixel = 0;
    }
    
    pixels.clear(); // Set all pixel colors to 'off'
  
    // The first NeoPixel in a strand is #0, second is 1, all the way up
    // to the count of pixels minus one.
    for(int i=0; i<NUMPIXELS; i++) { // For each pixel...
  
      // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
      // Here we're using a moderately bright green color:
      if( i == activePixel ){
        pixels.setPixelColor(i, pixels.Color(255,255,255));
      }else{
        pixels.setPixelColor(i, pixels.Color(0,0,0));
      }
      
      delay(50); // Pause before next pass through loop
      
    }
     
  }

  

  pixels.show();   // Send the updated pixel colors to the hardware.

}
