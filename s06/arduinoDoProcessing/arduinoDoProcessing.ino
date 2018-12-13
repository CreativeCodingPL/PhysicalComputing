void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int los = random(255);
  Serial.write(los);
  delay(100);
}
