//miganie bez delay
#include <CheapStepper.h>
CheapStepper stepper;

int ledState = LOW;        // pamieta czy dioda jest on czy off
long previousLedTime = 0;     // kiedy ostatnio dioda była zapalana lub gaszona
long previousStepTime = 0;
boolean kierunekPrawo = true;

void setup() {
  pinMode(13, OUTPUT);
}
void loop() {
  long teraz = millis();
 
  if (teraz - previousLedTime >= 100) {  //500 to czas w milisekundach co ile migac
    previousLedTime = teraz; //zapisuje czas kiedy ostatnio dioda mignela on lub off

    // jeżeli dioda jest wyłączona to włącz i odwrotnie itd.
    if (ledState == LOW) {
      ledState = HIGH;
    } 
    else {
      ledState = LOW;
    }
    digitalWrite(13, ledState);
  }

  if(teraz - previousStepTime >= 5000){
     previousStepTime = teraz;
     kierunekPrawo = !kierunekPrawo;
     stepper.newMoveDegrees(kierunekPrawo,180);
  }
  
  stepper.run();
}
