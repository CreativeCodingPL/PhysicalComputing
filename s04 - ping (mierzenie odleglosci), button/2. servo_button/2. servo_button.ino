#include <Servo.h>

#define BUTTON_INTERNAL_PIN 2
#define BUTTON_EXTERNAL_PIN 9
#define LED_DO_BTN_INTERNAL_PIN 13
#define LED_DO_BTN_EXTERNAL_PIN 12
#define SERVO_PIN 10

Servo servo;
int servoPosition = 0;

void setup() {
  pinMode(BUTTON_INTERNAL_PIN, INPUT_PULLUP);
  pinMode(BUTTON_EXTERNAL_PIN, INPUT_PULLUP);
  
  pinMode(LED_DO_BTN_EXTERNAL_PIN, OUTPUT);
  pinMode(LED_DO_BTN_INTERNAL_PIN, OUTPUT);
  
  servo.attach(SERVO_PIN);
  Serial.begin(9600);

  servo.write(0);
  delay(1000);
}

void loop() {

  int stan_btn_ext = digitalRead(BUTTON_EXTERNAL_PIN);
  if (stan_btn_ext == HIGH) {
    digitalWrite(LED_DO_BTN_EXTERNAL_PIN, LOW);
    servoPosition -= 5;
    servoPosition = constrain(servoPosition, 0, 180);
  } else {
    digitalWrite(LED_DO_BTN_EXTERNAL_PIN, HIGH);
  }

  int stan_btn_int = digitalRead(BUTTON_INTERNAL_PIN);
  if (stan_btn_int == HIGH) {
    digitalWrite(LED_DO_BTN_INTERNAL_PIN, LOW);
    servoPosition += 5;
    servoPosition = constrain(servoPosition, 0, 180);
  } else {
    digitalWrite(LED_DO_BTN_INTERNAL_PIN, HIGH);
  }

  servo.write(servoPosition);
  delay(20);
}
