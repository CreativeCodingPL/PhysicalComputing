// prosty odczyt z pinu analogowego modułu mikrofonu Iduino ST1146
// https://botland.com.pl/mikrofony-i-detektory-dzwieku/14292-czujnik-dzwieku-mikrofon-iduino-se019-5903351241946.html
void setup() {
  // inicjujemy komunikacje po serialu z predkoscia 9600 "baudów"
  Serial.begin(9600);
}

void loop() {
  // po prostu odczytujemy stan na pinie analogowym A0 i wysyłsmy go na serial
  Serial.println(analogRead(A0));
  delay(1);
}
