unsigned long aktualnyCzas;

void setup() {
  Serial.begin(9600);
}
void loop() {

  aktualnyCzas = millis();

  Serial.println(aktualnyCzas);
}
