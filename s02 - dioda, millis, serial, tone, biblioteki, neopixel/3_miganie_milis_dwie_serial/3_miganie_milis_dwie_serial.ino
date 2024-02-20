void setup() {
  // put your setup code here, to run once:
  pinMode(7, OUTPUT);
  pinMode(9, OUTPUT);
  Serial.begin(9600);
}

long int t7 = 0; 
long int t9 = 0; 

void loop() {
  if(millis() - t7 > 500 && digitalRead(7) == LOW) {
    digitalWrite(7, HIGH);
    t7 = millis();
    Serial.println("Ping 7");
  }
  if(millis() - t7 > 1000  &&  digitalRead(7) == HIGH) {
    digitalWrite(7, LOW);
    t7 = millis();
  }

  if(millis() - t9 > 300 && digitalRead(9) == LOW) {
    digitalWrite(9, HIGH);
    Serial.println("Ping 9");
    t9 = millis();
  }
  if(millis() - t9 > 150  &&  digitalRead(9) == HIGH) {
    digitalWrite(9, LOW);
    t9 = millis();
  }

}
