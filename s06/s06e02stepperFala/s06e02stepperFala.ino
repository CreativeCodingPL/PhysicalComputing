#include <CheapStepper.h>

CheapStepper stepper; 

long lastFala = 0;
long ledTimeStart = 0;
boolean fala = false;
boolean kierunek = false;
boolean ledOn = false;

void setup() {
  pinMode(13, OUTPUT);
}

void loop() {
    if( analogRead(A0) > 800 && millis()-lastFala>500) {
      fala = true;
      lastFala = millis();   
    }

    if(fala) {
      fala = false;
      stepper.newMoveDegrees(kierunek, 90);  
      ledTimeStart = millis();
      kierunek = !kierunek;
      ledOn = true;
    }

    if(ledOn && millis() - ledTimeStart > 1500) {
      ledOn = false;
      digitalWrite(13, HIGH);
    }
    
    if(millis() - ledTimeStart > 1500+300) {
      digitalWrite(13, LOW);
    }
    
    stepper.run();
}

