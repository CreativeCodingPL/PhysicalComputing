
void setup() {

  pinMode(6, INPUT_PULLUP);

}

void loop() {
  
  bool wcisniety = digitalRead(6); //pir OUT podlaczony do pinu 6
  
  if(wcisniety) tone(3, 1500, 50);  //ruch jest zmienna logiczna wiec sama w sobie tworzy warunek

}
