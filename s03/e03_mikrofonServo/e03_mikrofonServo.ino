// importujemy biblioteke servo
#include <Servo.h>
// tworzymy obiekt typu Servo
Servo servo;


// okno samplowania(50 mS = 20Hz = 20 razy na sekunde)
// czyli z jakiego okresu bedziemy zbierac probki z mikrofonu by oszacowac glosnosc
const int sampleWindow = 50; 
unsigned int sample;

// zmienna pozwalajaca nam przemapowac glosnosc na ruch servo
const int maxScale = 180;

//int servoPos = 0; // - wersja z int'em jako alternatywa do stopniowej zmiany pozycji
float servoPos = 0;

void setup() {
  Serial.begin(9600);
  // by sterowac servo musimy w setup wywolac metode attach( numerPinuSterujcegoServo )
  servo.attach(2);
}

void loop() {

   unsigned long startMillis= millis();  // sprawdzamyh jaki jest czs na poczatku loopa
   unsigned int peakToPeak = 0;   // zmienna w do kotrej zapiszemy info o glosnosci
 
   unsigned int signalMax = 0; //minium sygnalu z mikrofonu - relna wartosc ustawiona bedzie w petli ponizej
   unsigned int signalMin = 1024; //maksimum sygnalu z mikrofonu - relna wartosc ustawiona bedzie w petli ponizej

    // petla while, kreci sie dopóki róznica miedzy czasem z poczatku petli (startMilis) a aktualnym (zwracane pzez millis())
    // jest mniejsza niz długość sampla (sampleWindow), czyli de facto przez 50 ms robimy tyle odczytow z mikrofonu ile sie da w tym czasie
   while (millis() - startMillis < sampleWindow){ 

      //odczyt z pinu analogowego A0
      sample = analogRead(A0); 
      
      if (sample < signalMax) { // przyjmujemy tylko prawidlowe odczyty: 0-1024

         // ustawicznie sprawdzamy czy aktualny odczyt jest wiekszy od ostatnio ustawionej wartosci zmiennej signalMax
         // jesli tak to aktualizujemy signalMax, jesli nie to zostawiamy ostatnio ustalona wartosc
         if (sample > signalMax){
            signalMax = sample;  // zapisujemy max
         }
         // ...analogicznie z signalMin
         else if (sample < signalMin){
            signalMin = sample;  // zapisujemy min
         }
         
      }
   }

   // sprawdzamy roznice pomiedzy najwyzszym a najnizszym odczytem co daje nam
   // realne info o amplitudzie, czyli głośności dźwięku
   peakToPeak = signalMax - signalMin;

   // mapujemy wartość głośności 0-1023 na pozycje servo 0-180
   int mappedPeak = map(peakToPeak, 0, 1023, 0, maxScale);

   // "wygladzanie" pozycji servo - aktualna pozycja servo to 
   // wypadkowa najnowszego odczytu (30%) i poprzedniego stanu zmiennej (70%)
   // zmienianie tych proporchi powoduje zwiekszanie/zmniejszanie wygladzania
   // kosztem mniejszej/wiekszej responsywności
   servoPos = (0.3 * float(mappedPeak)) + (0.7 * servoPos);

   // alternatywna wersja kodu gdzie servoPos było intem
//   if( peakToPeak > 55 && mappedPeak > servoPos ){
//    servoPos = mappedPeak;
//   }else{
//    //servo.write( 0 );
//    if( servoPos > 0 ){
//      servoPos -= 5;
//    }
//   }

   // ustawiamy pozycje servo, pamietajac o konwersji float na int
   servo.write( int(servoPos) );

   //wypisujemy pozycje servo w konsoli
   Serial.println(servoPos);
  
}
