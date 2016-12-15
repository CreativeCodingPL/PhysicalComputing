#include <CheapStepper.h>

CheapStepper stepper (8,9,10,11); 

void setup() {

  stepper.setRpm(16); 
   //accepted RPM range: 6RPM (may overheat) - 24RPM (may skip)
   //ideal range: 10RPM (safe, high torque) - 22RPM (fast, low torque)

  
  stepper.setTotalSteps(4076); 
  //for more info see: http://forum.arduino.cc/index.php?topic=71964.15
}

void loop() {
    stepper.moveToCW(2048);
    
    delay(1000); // wait a sec

    stepper.moveDegreesCW(90);
    
    delay(1000);
   
    stepper.moveToDegreeCCW(0);
    
    delay(1000);  
}

