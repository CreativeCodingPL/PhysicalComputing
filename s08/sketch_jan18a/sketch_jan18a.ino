void setup() {
  // put your setup code here, to run once:
  pinMode(5, OUTPUT);  //IN1 -> A
  pinMode(6, OUTPUT);  //IN2 -> B
}

void loop() {
  // silnik reci sie w strone pierwsza (ktora sprawdz sam :))
  digitalWrite(5, HIGH); //prad, (+), (vin) -> A 
  digitalWrite(6, LOW); //masa, GND, (-) -> B
  delay(2000); 
  // silnik reci sie w strone druga (ktora sprawdz sam :), ale napewno przeciwan niz poprzednio)
  digitalWrite(6, HIGH); //prad, (+), (vin) -> B 
  digitalWrite(5, LOW); //masa, GND, (-) -> A
  delay(2000);
}
