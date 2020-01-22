#include <AccelStepper.h>

#define in1 8
#define in2 9
#define in3 10
#define in4 11

int stan = 2;
int odleglosc = 512;

int sekwencja[] = {2, 4, 7, 3, 6};
int ilosc = 5;
int aktualny = 0;

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
    int nowyStan = sekwencja[aktualny];
    //int nowyStan = floor(random(0,8));
    stepper.moveTo(nowyStan * odleglosc);
    aktualny += 1;
    if(aktualny > ilosc - 1){
      aktualny = 0;
    }
   // aktualny = (aktualny+1)%ilosc;
  }

  stepper.run();
}
void kalibracja() {
  while (digitalRead(12) == 0) {
    stepper.runSpeed();
  }
  stepper.setCurrentPosition(0);
}
