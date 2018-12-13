
int pinNum = 11;

void setup() {
  pinMode(pinNum, OUTPUT);

}
void loop() {
  for (int i = 0; i < 255; i++) {
    analogWrite(pinNum, i);
    delay(10);
  }

}

