void setup() {
  // put your setup code here, to run once:
  pinMode(7, OUTPUT);
  pinMode(9, OUTPUT);
}

long int t = 0; 
bool nie_pali = true;

void loop() {
  if(millis() - t > 500 && nie_pali) {
    digitalWrite(7, HIGH);
    nie_pali = false;
    t = millis();
  }

  if(millis() - t > 1000  && !nie_pali) {
    digitalWrite(7, LOW);
    nie_pali = true;
    t = millis();
  }

}
