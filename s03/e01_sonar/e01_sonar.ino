// nalezy najpierw zainstalowac biblioteke NewPing 
// a nastepnie uzyc #include by móc ją wykorzystac 
#include <NewPing.h>

// tworzymy nowy obiekt typu NewPing pod zmienna sonar
// i inicjalizujemy parametry - nr. pinu TRIG, nr. pinu ECHO, maksymalna odleglosc w cm
NewPing sonar(12,11,20);

void setup() {
  
  Serial.begin(9600);

  // piny cyfrowe (wszystkie poza A0-A5)
  // moga być zawrówno wejściem jak i wyjściem (sprawdzać prąd / ustawiać prąd)
  // jeśli chcemmy migac ledem należy użyć pinMode z parametrem OUTPUT
  // LED_BUILTIN to specjalna stała ktora zawsze wskazuje pin z LED'em niezleżnie 
  // od konkretnego modelu Arduino
  pinMode(LED_BUILTIN, OUTPUT);
  
}

void loop() {

  // motoda ping_cm() zwraca odelgosc w cm
  int odleglosc = sonar.ping_cm();

  // jeśli odległość jest mniejsza niż 10 cm i ("&&") jednocześnie nie jest równa ("!=") 0 (co oznacza bład odczytu) 
  if( odleglosc <= 10 && odleglosc != 0 ){
    // ...to zapalamy leda
    digitalWrite( LED_BUILTIN, HIGH );
  }else{
    // ...a jesli nie to gasimy
    digitalWrite( LED_BUILTIN, LOW );
  }

  // wypisujemy odleglosc do konsoli
  Serial.println(odleglosc);

  // jak się okazuje zbyt mały delay może spowodować błędy odczytu z sensora
  delay(50);

}
