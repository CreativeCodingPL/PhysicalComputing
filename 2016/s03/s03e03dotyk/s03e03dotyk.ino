int pin = 6;
void setup() {
  Serial.begin(9600);
}

void loop() {
  int val = readCapacitivePin( pin );
  Serial.println(val);
}


