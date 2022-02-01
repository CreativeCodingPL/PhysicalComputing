int ledPin = 9;

void setup() {
  pinMode(A0, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int odczyt = analogRead(A0);

  // zazwyczaj od 300 (ciemno) do 800 (jasno)
  int jasnosc = map(odczyt, 300, 800, 255, 0);

  // zmieniamy na wartosci od 0 (ciemno) do 255 (jasno)
  jasnosc = constrain(jasnosc, 0, 255);
  
  Serial.println(jasnosc);

  analogWrite(ledPin, jasnosc);
}
