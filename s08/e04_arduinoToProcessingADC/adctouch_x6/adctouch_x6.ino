#include <ADCTouch.h>
#define PIN_COUNT 3

int refs[PIN_COUNT];
int pins[PIN_COUNT] = { A0, A1, A2 };

void setup() {
  
  for(int i = 0; i< PIN_COUNT;i++){
    refs[i] = ADCTouch.read(pins[i], 500);
    delay(10);
  }
  
  Serial.begin(9600);
  
}

void loop() {
  
  for(int i=0;i<PIN_COUNT;i++){ // petla leci przez 3 odczyty z pinow analogowych
    Serial.print(ADCTouch.read(pins[i])-refs[i]); // wypisujemy na port odczyt z pinu
    if( i < PIN_COUNT-1 ){ // dodajemy przecinek odcielajacy kolejne wartosci (by potem je odczytac po stronie processing) ale tylko do przedostatniej wartosci by nie bylo przecinka na koncu 
      Serial.print(",");
    }
  }
  
  Serial.println(""); //wysylamy na port znak nowej linii - moglo by byc tez Serial.print('\n');
  delay(10);
  
}
