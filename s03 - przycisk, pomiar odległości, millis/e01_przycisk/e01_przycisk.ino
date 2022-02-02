void setup() {
  pinMode(2, INPUT_PULLUP);
  Serial.begin(9600);
}
void loop() {
  
  int wartosc = digitalRead(2);

  // UWAGA: używając pull-up logika działania przycisku jest odwrócona.
  
  // To znaczy, że wartość HIGH jest kiedy przycisk nie jest wduszony,
  // natoamist wartość LOW jest wtedy, gdy przycisk jest wduszony.
  
  if (wartosc == HIGH) {
    
    Serial.println("open");
    
  } else {
    
    Serial.println("pressed");
    
  }
}
