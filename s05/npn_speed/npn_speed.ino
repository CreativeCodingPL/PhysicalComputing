void setup() {
  pinMode(6, OUTPUT);
}

void loop() {
  //PWM musi być pin z ~
  analogWrite(6, 255/2);  //50% PWM 
  delay(1000);                       
  analogWrite(6, 255/4);  //25% PWM  
  delay(1000);                       
  analogWrite(6, 58);  // PWM  
  delay(3000);                       
}
