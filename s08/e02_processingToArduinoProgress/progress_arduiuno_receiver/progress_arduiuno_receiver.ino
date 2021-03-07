#include <Adafruit_NeoPixel.h>
#define NUMPIXELS 8
#define PIN_NUMBER 6

int progress = 0;

Adafruit_NeoPixel pixels(NUMPIXELS, PIN_NUMBER, NEO_GRB + NEO_KHZ800);

void setup() {

  Serial.begin(9600);
  pixels.begin();

}

void loop() {

  while (Serial.available()) { 
    progress = Serial.read(); // przypisujemy zmiennej progress najnowsza wartosc z bufora danych
  }
  
  pixels.clear();
  
  for(int i=0;i<NUMPIXELS;i++){
    if( i <= progress-1 ){ // jesli numer piksela jest mniejszy lub rowny wartosci progress pomnijeszonej o jeden zapal piksel na czerwono
      pixels.setPixelColor(i, pixels.Color(255, 0, 0));
    }else{ // jesli wiekszy to zgaś
      pixels.setPixelColor(i, pixels.Color(0, 0, 0));
    }
    
  }
  
  pixels.show();
}
