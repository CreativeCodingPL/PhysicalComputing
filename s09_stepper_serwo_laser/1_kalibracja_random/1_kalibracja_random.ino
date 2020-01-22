#include <AccelStepper.h>

#define in1 8
#define in2 9
#define in3 10
#define in4 11

int stan = 2;
int odleglosc = 512;


AccelStepper stepper(AccelStepper::HALF4WIRE, in1, in3, in2, in4);

void setup() {
  stepper.setMaxSpeed(1000);
  stepper.setSpeed(500);
  kalibracja();
  stepper.setMaxSpeed(1000);
  stepper.setSpeed(500);
  stepper.setAcceleration(1000);
}

void loop() {
  if(stepper.distanceToGo() == 0) {
    int nowyStan = floor(random(0,8));
    stepper.moveTo(nowyStan * odleglosc);
  }

  stepper.run();
}
void kalibracja() {
  while (digitalRead(12) == 0) {
    stepper.runSpeed();
  }
  stepper.setCurrentPosition(0);
}
