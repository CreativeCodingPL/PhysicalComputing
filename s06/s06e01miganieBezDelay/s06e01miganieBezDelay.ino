//miganie bez delay

int ledState = LOW;        // pamieta czy dioad jest on czy off
long previousTime = 0;     // kiedy ostatnio dioda była zapalana lub gaszona

void setup() {
  pinMode(13, OUTPUT);
}

void loop() {

  if (millis() - previousTime > 500) {  //500 to czas w milisekundach co ile migac
    
    previousTime = millis(); //zapisuje czas kiedy ostatio dioda mignela on lub off

    // jeżeli dioda jest wyłączona to włącz i odwortnie itd.
    if (ledState == LOW) {
      ledState = HIGH;
    } 
    else {
      ledState = LOW;
    }

    digitalWrite(13, ledState);
  }
}

