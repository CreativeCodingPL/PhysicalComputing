int aktualny = 2;

void setup() {

  for (int i = 2; i < 14; i++) {
    pinMode(i, OUTPUT);
  }
  pinMode(A0, INPUT_PULLUP);
  pinMode(A1, INPUT_PULLUP);
}

void loop() {

  for (int i = 2; i < 14; i++) {
    digitalWrite(i, LOW);
  }

  for (int i = 2; i < aktualny; i++) {
    digitalWrite(i, HIGH);
  }

  if(digitalRead(A0)==LOW){
    aktualny = max(2, aktualny - 1);
  }

  
  if(digitalRead(A1)==LOW){
    aktualny = min(14, aktualny + 1);
  }
  
  delay(200);
}
