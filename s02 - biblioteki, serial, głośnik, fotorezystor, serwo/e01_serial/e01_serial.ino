void setup() {
  
  // Otwarcie portu i ustawienie prędkości na 9600 bitów na sekundę
  Serial.begin(9600);
}

void loop() {
  
  // Pomiaru czasu
  unsigned long time = millis();

  // Wypisywanie zmiennej `time` w nowym wierszu.
  Serial.println( time );
}
