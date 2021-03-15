#include <Adafruit_NeoPixel.h>
#define NUMPIXELS 8
#define PIN_NUMBER 6

const int NUMBER_OF_FIELDS = 3; // ilu zmiennych sie spodziewamy w komunikacie
int fieldIndex = 0;            // indeks aktualnej zmiennej odczytywanej z portu
int values[NUMBER_OF_FIELDS];   // tablica trzymajca wartosci odczytane z portu

// zmienne globalne trzymajace ostatnie wartosci odczytane po serialu
int r = 0;
int g = 0;
int b = 0;

Adafruit_NeoPixel pixels(NUMPIXELS, PIN_NUMBER, NEO_GRB + NEO_KHZ800);

void setup() {

  Serial.begin(9600);
  pixels.begin();

}

void loop() {


  pixels.clear();

  for (int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(r,g,b));
  }

  pixels.show();

  processSerial();
  
}

// aktualizacja zmiennych na podstawie danych w tablicy
void updateVariables(){

  r = values[0];
  g = values[1];
  b = values[2];
  
}

// magiczna funkcja interpretujaca bajty splywajace w serialu
// wyszukuje bajty kodujace liczby, odpowiednio je przetwarza na inty,
// znajduje przecinki by wiedziec do ktorej zmiennej zapisac
// po wykryciu \n czysci tablice wartosci i resetuje indeks 
void processSerial() {
  
  if ( Serial.available()) {

    char ch = Serial.read();
    // is this an ascii digit between 0 and 9?
    if (ch >= '0' && ch <= '9') {
      // akumulacja wartosci
      values[fieldIndex] = (values[fieldIndex] * 10) + (ch - '0');
    }else if (ch == ',') {
      //jesli przecinek to zacznij wylapywac bajty do kolejnej zmiennej
      if (fieldIndex < NUMBER_OF_FIELDS - 1){
        fieldIndex++;   // increment field index
      }
    }
    else if( ch == '\n' ){ /// jesli now a linia to resetuj licznik etc.

      updateVariables();
      
      for (int i = 0; i <= fieldIndex; i++){
        values[i] = 0; 
      }
      fieldIndex = 0;  
      
    }
  }
}
