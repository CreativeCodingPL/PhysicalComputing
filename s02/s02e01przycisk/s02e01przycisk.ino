void setup() {
  Serial.begin(9600);
  pinMode(7, INPUT);
}

void loop() {
   int odczyt = digitalRead(7);
   Serial.println(odczyt);
   delay(50);
}
