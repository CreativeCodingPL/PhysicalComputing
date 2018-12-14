void setup() {
  
  pinMode(6, OUTPUT);

}

void loop() {

  analogWrite(6, 255);
  delay(400);
  analogWrite(6, 255/40);
  delay(300);
   
}
