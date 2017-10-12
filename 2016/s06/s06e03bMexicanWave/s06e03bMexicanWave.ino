//miganie bez delay
#include <CheapStepper.h>
CheapStepper stepper;

int ledState = LOW;        // pamieta czy dioda jest on czy off
long previousLedTimeOn = 0; 
long previousLedTimeOff = 0;// kiedy ostatnio dioda była zapalana lub gaszona
int threshold = 800;
boolean kierunekPrawo = false;
boolean isMoving = false;

void setup() {
  pinMode(13, OUTPUT);
}
void loop() {

 
  if( analogRead(A0) >= threshold ){
    
    stepper.newMoveDegrees(kierunekPrawo,180);
    kierunekPrawo = true;
    isMoving = true;
    
  }else{

    kierunekPrawo = false;
    
  }

  long teraz = millis();
  
  if( teraz - previousLedTimeOn >= 1000 && isMoving ){

      previousLedTimeOn = teraz;
      digitalWrite(13,HIGH);
  
  }
  
  if( teraz - previousLedTimeOff >= 2000 && isMoving ){

    previousLedTimeOff = teraz;
    isMoving = false;
    digitalWrite(13,LOW);
    
  }
  
  stepper.run();
  
}
