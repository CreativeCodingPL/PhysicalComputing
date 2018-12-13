#include <AccelStepper.h>
#define HALFSTEP 8

// Motor pin definitions
#define motorPin1  8     // IN1 on the ULN2003 driver 1
#define motorPin2  9     // IN2 on the ULN2003 driver 1
#define motorPin3  10     // IN3 on the ULN2003 driver 1
#define motorPin4  11    // IN4 on the ULN2003 driver 1

// Initialize with pin sequence IN1-IN3-IN2-IN4 for using the AccelStepper with 28BYJ-48
AccelStepper stepper1(HALFSTEP, motorPin1, motorPin3, motorPin2, motorPin4);

void setup() {
  stepper1.setMaxSpeed(1000.0);
  stepper1.setAcceleration(400.0);
  stepper1.setSpeed(200);
  stepper1.moveTo(0); //pelen obrot cyli krokow wewnetrzychdla naszego silnika to 32*64 

}
int pozycja = 0;
void loop() {

  //Change direction when the stepper reaches the target position
  if (stepper1.distanceToGo() == 0) {
    pozycja++;
    if(pozycja == 1) stepper1.moveTo(1500);
    if(pozycja == 2) stepper1.moveTo(3000);
    if(pozycja == 3) stepper1.moveTo(0 );  
    delay(500);  
  }
  
   stepper1.run();
}
