void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  short R = random(255); // (od 0 do 254, bo 255 zarezerwowaner na start paczki)
  byte G = random(255);
  byte B = random(255);
  Serial.write(255); //jak 255 to info ze mamy poczatek transmisji paczki trzech liczb RGB
  Serial.write(R);
  Serial.write(G);
  Serial.write(B);
  delay(100);
}
