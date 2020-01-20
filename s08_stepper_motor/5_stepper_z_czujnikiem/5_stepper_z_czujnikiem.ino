#include <AccelStepper.h>

#define in1 8
#define in2 9
#define in3 10
#define in4 11

AccelStepper stepper(AccelStepper::HALF4WIRE, in1, in3, in2, in4);

void setup() {
  stepper.setMaxSpeed(1000);
  stepper.setSpeed(50);
}

void loop() {
  // Odczyt z pinu 12 (D12)
  int sensorValue = digitalRead(12);
  if (sensorValue == 1) {
    stepper.stop();
  } else {
    stepper.runSpeed();
  }
}
