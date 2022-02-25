
# Sezon 06 - komunikacja Processing <-> Arduino + NeoPixel

## Poruszone zagadnienia

## Serial 
- Serial po stronie Processing:
	* Pamietać o takm samym "baud rate" - np. 9600 po stronie Arduino jak i Processing - ```new Serial(this, portName, 9600);```
    * ```Serial.list()``` - wypisuje wszystkie porty dostepna na komputerze - przy incjalizacj portu musimy wskazac ten na ktorym jest Arduino
    * ```bufferUntil('\n');``` - powoduje że Prcessing bedize odczytwyac dane z bufora dopiero jesli napotka znak nowej linii - ```\n```
    * ```serialEvent( Serial port ) ``` - wbudowana metoda w processing wywoływana kiedy na porcie pojawia sie nowe dane (lub tylko wtedy jesli pojawil sie znak zdefiniowany via ```bufferUntil()```. UWAGA - ta metoda wywoluje sie niezleznie od ```draw()``` wiec należy korzystać ze zmiennych globalnych by przypisywac im wartosci przychodzace z portu i potem odwolywac sie do nich w ```draw()```
    * ```myPort.write()``` - metoda write pozwala na wyslanie pojedynczego bajtu lub calej sekwencji bajtow (moga byc wyslane jako tekst) na port
- Serial po stronie Arduino:
	* ```Serial.available()``` - sprawdza czy sa jakies dane w buforze
    * ```Serial.read()``` - odczytuje pojedynczy, ostatni bajt z bufora. UWAGA - odczytanie jednoczesnie usuwa dane z bufora.
    * ```Serial.print()``` i ```Serial.println()``` pozwalaja na wysyłanie danych w formie tekstowej
    * ```Serial.write()``` wysyła bajty
    
## NeoPixel

To brand produktów opartych o chipy WS2812B lub SK6812. Są to tak zwane adresowalne ledy RGB (a czasem RGBW gdzie mmay dodatkowy 4 kanał w postaci czystej bieli, bo biel uzyskiwana via mix RGB nie jest idealna). Adresowalnoc polegana tym że połączone ze sobą za pomocą jednego kabelka ledy w danym łańcuchu można sterować indywidualnie. Maksymalna ilość ledów na jednym kablu zależna jest od możiwości mikrokontorlera oraz zapewnieina adekwatneggo zasilania. 

Do obsługi adresowalnych ledów z poziomu arduini służy bliblioteka Adafruit NeoPixel, istnieja też alternatywne biblioteki (pod pewnymi wzgledami lepsze i/lub wspierajace wiecej typów) jak np. FastLED - obie można zainstalować z poziomu managera bibliotek w Arduino IDE.

Przykład użycia Adafruit NeoPixel:


```Arduino
// Pin sterujacy neopixelami: 
#define PIN        6 

// Ile pixeli na danym pinie - 7 w "jewelu" z zestawu
#define NUMPIXELS 7

// Konfiguracja biblioteki - ostani argument definiuje layout kanałow rgb i czestotliwosc odswiezania, mozna zostawic dla typowych neopixeli tak jak jest...
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 500 // pauza w animacji

void setup() {

  pixels.begin(); // Musimy zaincjalizowac biblioteke w setup
}

void loop() {

  pixels.clear(); // przed wyswietleniem danej "klatki" resetujemy wszystkiepixele na 0 - nie świecą...

  // W tej petli przechodzimy kolejno przez wszystkie pixele
  for(int i=0; i<NUMPIXELS; i++) { 

    // pixels.Color() przyjmuje indeks pixela oraz wartosci R,G,B
    // tutaj ustawiamy kolor zielony z ok. polowa jasnosci
    pixels.setPixelColor(i, pixels.Color(0, 150, 0));

    pixels.show();   // dopiero po wywolani show() pixele sie zupdejtuja

    delay(DELAYVAL); // pauza by bylo widac animacje
  }
}
```




## Materiały pomocnicze

- [dokumentacja Serial w Processing](https://processing.org/reference/libraries/serial/index.html)
- [dokumentacja Serial w Arduino](https://www.arduino.cc/reference/en/language/functions/communication/serial/)
- [tabela kodów ASCII](https://en.wikipedia.org/wiki/ASCII)
- [poradnik dot. neopixeli](https://learn.adafruit.com/adafruit-neopixel-uberguide)
