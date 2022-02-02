int buttonPin = 2;
int ledPin = 13;
int onOff = 0;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
}
void loop() {
  int wartosc = digitalRead(buttonPin);

  if (wartosc == LOW) {

    if (onOff == 0) {
      onOff = 1;
      digitalWrite(ledPin, HIGH);
    } else {
      onOff = 0;
      digitalWrite(ledPin, LOW);
    }

    delay(1000);
  }
}
