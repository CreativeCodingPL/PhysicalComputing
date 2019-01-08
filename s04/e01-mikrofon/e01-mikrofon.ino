int micPin = 4;

void setup() {
  Serial.begin(9600);
  pinMode(micPin, INPUT);

}

void loop() {
  Serial.println(analogRead(0));
  Serial.println(digitalRead(micPin));
}
