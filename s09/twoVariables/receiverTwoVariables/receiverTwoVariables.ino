#include <Adafruit_NeoPixel.h>
#define NUMPIXELS 8
#define PIN_NUMBER 6

// opis - vide receiverRGB w webcamColor

const int NUMBER_OF_FIELDS = 2; 
int fieldIndex = 0;            
int values[NUMBER_OF_FIELDS];   

int progress = 0;
int brightness = 0;

Adafruit_NeoPixel pixels(NUMPIXELS, PIN_NUMBER, NEO_GRB + NEO_KHZ800);

void setup() {

  Serial.begin(9600);
  pixels.begin();

}

void loop() {

 pixels.clear();
  
  for(int i=0;i<NUMPIXELS;i++){
    if( i <= progress-1 ){ // jesli numer piksela jest mniejszy lub rowny wartosci progress pomnijeszonej o jeden zapal piksel na czerwono
      pixels.setPixelColor(i, pixels.Color(brightness, 0, 255-brightness));
    }else{ // jesli wiekszy to zgaś
      pixels.setPixelColor(i, pixels.Color(0, 0, 0));
    }
    
  }
  
  pixels.show();

  processSerial();
  
}

void updateVariables(){

  progress = values[0];
  brightness = values[1];
  
}

void processSerial() {
  
  if ( Serial.available()) {

    char ch = Serial.read();
    // is this an ascii digit between 0 and 9?
    if (ch >= '0' && ch <= '9') {
      // yes, accumulate the value
      values[fieldIndex] = (values[fieldIndex] * 10) + (ch - '0');
    }else if (ch == ',') {
      // comma is our separator, so move on to the next field
      if (fieldIndex < NUMBER_OF_FIELDS - 1){
        fieldIndex++;   // increment field index
      }
    }
    else if( ch == '\n' ){

      updateVariables();
      
      for (int i = 0; i <= fieldIndex; i++){
        values[i] = 0; // set the values to zero, ready for the next message
      }
      fieldIndex = 0;  // ready to start over
      
    }
  }
}
