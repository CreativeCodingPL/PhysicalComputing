#define TRIG_PIN 9
#define ECHO_PIN 10

void setup() {
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() {

  long czas, dystans_w_cm;

  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  czas = pulseIn(ECHO_PIN, HIGH);
  dystans_w_cm = czas / 2 / 29;
  dystans_w_cm = constrain(dystans_w_cm, 2, 20);

  Serial.print("Odleglosc: ");
  Serial.println(dystans_w_cm);

  delay(100);
}
