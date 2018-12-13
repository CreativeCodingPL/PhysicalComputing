void setup() {
  // put your setup code here, to run once:
  pinMode(5, OUTPUT);  //IN1 -> A
  pinMode(6, OUTPUT);  //IN2 -> B
}

void loop() {
  // silnik reci sie w strone pierwsza (ktora sprawdz sam :))
  analogWrite(5, 70); //prad, (+), (vin) -> A 
  analogWrite(6, 0); //masa, GND, (-) -> B
  delay(2000); 
  // silnik reci sie w strone druga (ktora sprawdz sam :), ale napewno przeciwan niz poprzednio)
  analogWrite(6, 70); //prad, (+), (vin) -> B 
  analogWrite(5, 0); //masa, GND, (-) -> A
  delay(2000);
}
