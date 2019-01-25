
void setup() {
// nic nie trzeba bo domyslnie kazdy pin jest inputem
}

void loop() {
  
  bool ruch = digitalRead(6); //pir OUT podlaczony do pinu 6
  
  if(ruch) tone(3, 456, 500);  //ruch jest zmienna logiczna wiec sama w sobie tworzy warunek

  Serial.println(ruch);
}
