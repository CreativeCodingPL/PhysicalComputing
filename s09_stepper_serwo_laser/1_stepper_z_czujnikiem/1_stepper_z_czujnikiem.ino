#include <AccelStepper.h>

#define in1 8
#define in2 9
#define in3 10
#define in4 11
int circle = 64 * 64;
int holes = 8;
int dist = circle / holes;
int etap = 1;

AccelStepper stepper(AccelStepper::HALF4WIRE, in1, in3, in2, in4);

void setup() {
  stepper.setMaxSpeed(1000);
  stepper.setAcceleration(1000);
  stepper.setSpeed(500);
  Serial.begin(9600);
  calibrate();
  stepper.setMaxSpeed(1000);
  stepper.setAcceleration(1000);
  stepper.setSpeed(500);
}

void loop() {
   
  if (stepper.distanceToGo() == 0)
  {
    if (etap == 1) stepper.moveTo(dist * 2); //A->C
    if (etap == 2) stepper.moveTo(dist); //C->B
    if (etap == 3) stepper.moveTo(dist * 3); //B->D
    if (etap == 4) stepper.moveTo(0); //D->A
    if (etap == 4)
      etap = 1;
    else
      etap++;
  }

  stepper.run();
}

void calibrate() {
  while (true) {
    int sensorValue = digitalRead(12);
    if (sensorValue == 1) {
      Serial.println(sensorValue);
      stepper.stop();
      stepper.setCurrentPosition(0);
      Serial.println("Skalibrowane");
      break;
    } else {
      stepper.runSpeed();
    }
  }
}
