void setup() {
  pinMode( 9, OUTPUT); // PWM -> tylko piny digital, które mają symbol ~
  pinMode(10, OUTPUT); // mogą używać analogWrite, np. piny: 3, 5, 6, 9, 10 i 11
}

void loop() {

  analogWrite( 9, 25);  //  10% mocy świecenia
  analogWrite(10, 255); // 100% mocy świecenia (zakres od 0 do 255)
  
  delay(1);
}