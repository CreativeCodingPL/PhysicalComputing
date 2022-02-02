int buttonPin = 2;
int ledPin = 13;
int onOff = 0;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
}
void loop() {
  int buttonState = digitalRead(buttonPin);
  if (buttonState == LOW) {
    if (onOff == 0) {
      onOff = 1;
    } else {
      onOff = 0;
    }
    zapalLubZgasDiode();
    delay(1000);
  }
}

void zapalLubZgasDiode() {
  if (onOff == 1) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
}
