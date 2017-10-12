void setup() {
  pinMode(9, OUTPUT); // piny oznaczone ~ obsługują PWM 
                      // czyli cyfrową regulacje mocy
                      // Tu moc objawia się jako jasność świecenia
}

void loop() {
  analogWrite(9, 255); // 255 maksymalna moc (tu jasność)
  delay(300);
  analogWrite(9, 0);  // zerowa moc, czyli nie świeci
  delay(150);
  analogWrite(9, 35); // świeci słabo
  delay(150);
  analogWrite(9, 0); // nie świecei
  delay(500);
}
