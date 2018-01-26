int tryb = 0;
//0 - normalne liczby
//1 - przyciete liczby
unsigned long ostatniOdczyt=0;

void setup() {
  pinMode(2, INPUT);
  Serial.begin(9600);
  digitalWrite(2, HIGH);
}

void loop() {
  if (digitalRead(2) == LOW && (millis() - ostatniOdczyt > 1000)) {
    ostatniOdczyt = millis();
    if(tryb==0) { 
      tryb = 1;
    }
    else if(tryb==1) {
      tryb=0;
    }
  }
  if (tryb == 0) {
    Serial.print(analogRead(A0));
    Serial.print(';');
    Serial.print(analogRead(A1));
    Serial.print(';'); 
    Serial.println(0);
  }
  else if (tryb == 1) {
    Serial.print(map(analogRead(A0),0, 1023, 255, 768));
    Serial.print(';');
    Serial.print(map(analogRead(A1),0, 1023, 255, 768));
    Serial.print(';'); 
    Serial.println(1);
  }
  delay(100);
}
