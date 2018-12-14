void setup() {
  pinMode(A0, INPUT_PULLUP); //sztuczka, zeby dzialalo bez dodatkowego rezystora na zewnatrz, bo wlaczamy rezystor wewnetrzny
  pinMode(6, OUTPUT);
}

void loop() {
  int jasnosc = analogRead(A0);  
  // jasnosc = map(jasnosc, 0, 1023, 0, 255); //wersja cool
  jasnosc = jasnosc / 4; //na prostaka
  analogWrite(6, jasnosc);
}
