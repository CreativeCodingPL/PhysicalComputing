void setup() {
    
  // Częstotliwość syngału (120 - 1500Hz)
  int czestotliwosc = 262; // nuta C4

  // Ćwierćnuta (♩)
  int czasTrwaniaDzwieku = 1000 / 4;
  
  tone(8, czestotliwosc, czasTrwaniaDzwieku);
}

void loop() {
  
}
