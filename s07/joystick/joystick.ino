void setup() {
  pinMode(2, INPUT);
  Serial.begin(9600);
  digitalWrite(2, HIGH);
}

void loop() {
  Serial.print(analogRead(A0));
  Serial.print(';');x
  Serial.print(analogRead(A1));
  Serial.print(';');
  if(digitalRead(2)==HIGH){
    Serial.println(0);
  }
  else {
    Serial.println(1);
  }
  delay(100);
}

