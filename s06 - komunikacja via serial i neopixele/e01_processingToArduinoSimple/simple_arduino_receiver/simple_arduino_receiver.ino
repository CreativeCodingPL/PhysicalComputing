
char val; // dane z Seriala
int ledPin = LED_BUILTIN; 

void setup() {
  pinMode(ledPin, OUTPUT); 
  Serial.begin(9600); // Start komunikacji z predkoscia 9600 baudow
}

void loop() {
  
  while (Serial.available()) { // sprawdzamy czy sadane w buforze
    
    val = Serial.read(); // i jesli sa to je odczytujemy
    
    // uwaga - Serial.read() nie tylko odczytuje dane ale 
    // usuwa je z bufora, wiec jesli w buforze beda np. 3 bajty (char)
    // to petla wykona sie 3 razy i ostatnia z wartosci trafi do 
    // zmiennej val
    
  }
  
  if (val == 'H') { // jesli odczytany bajt koduje litere H
    digitalWrite(ledPin, HIGH); // wlacz led
  } else {
    digitalWrite(ledPin, LOW); // a jesli nie to wylacz
  }
  delay(100);
}
