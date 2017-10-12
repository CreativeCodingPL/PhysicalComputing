byte val;
int ledPin = 9;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  while (Serial.available()) {
    val = Serial.read(); 
  }
  analogWrite(ledPin, val);
  delay(100);
}
