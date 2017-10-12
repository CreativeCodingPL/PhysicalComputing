/*
 * Na podstawie przykładu:
 * using CheapStepper Arduino library v.0.2.0 by Tyler Henry, 7/2016
 * 
 */
 
#include <CheapStepper.h>

CheapStepper stepper;
// Jak połączyć ze sterownikiem:
// 8 <--> IN1
// 9 <--> IN2
// 10 <--> IN3
// 11 <--> IN4

boolean kierunekPrawo = true;

void setup() {
  
}

void loop() {

  // pełen obrót składa się z 4096 mini steps  
  for (int s=0; s<4096; s++){

    stepper.step(kierunekPrawo); //wykonuje jeden mini step (około 0.09 stopnia)
    //alternatywnie stepper.stepCW() lub stepper.stepCCW();  
  }
  
  delay(1000);
  
  kierunekPrawo = !kierunekPrawo;
}


