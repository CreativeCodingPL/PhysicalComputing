int button = 7;
void setup() {
  Serial.begin(9600);
  pinMode(button, INPUT);
}

void loop() {
  int x = analogRead(0);
  int y = analogRead(1);
  int s = digitalRead(button);

  Serial.print(x);
  Serial.print(", ");
  Serial.print(y);
  Serial.print(", ");
  Serial.println(s);
}
