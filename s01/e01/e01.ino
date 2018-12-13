
int pinNum = 11;

void setup(){
  pinMode(pinNum, OUTPUT);

}
void loop(){
  digitalWrite(pinNum, HIGH);
  delay(1000);
  digitalWrite(pinNum, LOW);
  delay(1000);
}

