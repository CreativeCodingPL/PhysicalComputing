# Physical Computing

Zajęcia poświęcone są osadzeniu kodu w kontekście fizycznym. Połączenie „bitów i atomów", dzięki tworzeniu układów elektronicznych. Duży nacisk położymy na nadawanie interakcji formy namacalnej/fizycznej, czyli „ucieleśnianie" informacji albo „ożywianie" przedmiotów, reagowanie na widza i zmianę kontekstu, czy konstruowanie wyrafinowanych form interakcji i zachowań.
Ponadto opanujemy podstawy programowania cyfrowych układów elektronicznych. Nauczymy się tworzyć obwody elektroniczne reagujące na bodźce z otaczającego środowiska i wpływające na te środowisko poprzez dźwięk, światło i oddziaływania mechaniczne.
Opanujemy popularną platformę Arduino służącą do tworzenia szybkich prototypów, a skonstruowaną z myślą o artystkach i projektantach. Nauczymy się używać podstawowego zestawu sensorów i aktuatorów.

Do tego otrzymaliście od nas zestawy z odjazdowym malezyjskim Maker Uno i zestawem komponentów, seniorów i aktuatorów. Niektóre gotowe do użycia, inne wymagające dolutowania gold pinów. Jednym słowem wszystko co niezbędne, żeby nauczyć się podstaw konstruowania obwodów elektorniczny do tworzenia instalacji.
   
## Zestawy rozdane

![](zestaw.jpg)

## Skład zestawu 
Poniże szczegółowy opis elementów w zestawie, wraz z odesłaniami do bibliotek tam gdzie są one wymagane.
 
# 
#### Maker UNO - malezyjskie Arduino, świetne!
![](https://ksr-ugc.imgix.net/assets/020/483/931/36dac5c036b77eac5bf85a26b23f0b8e_original.gif?w=680&fit=max&v=1520485057&auto=format&gif-q=50&q=92&s=6cafeb7a1e9447f19d8a729d2fe50367)

Twórczo przetworzona oryginalna koncepcja Arduino, z przydatnymi  podczas nauki modyfikacjam. Dodatkowe 12 Led przy każdym pinie cyfrowym, dodatkowy przycisk na pinie 2, oraz głośniczek na pinie 8.

- [Detale techniczne i drivery](https://www.cytron.io/c-arduino/c-arduino-main-board/p-maker-uno-simplifying-arduino-for-education) 
- [Maker UNO: Simplifying Arduino for {Education}](https://makeruno.com.my)
# 
# 
#### Czujnik ultradźwiękowy - HC-SR04  
![](foto/HC-SR04.png)

Ultradźwiękowy pomiar odległości 2 cm - 200 cm. 
##### Zastosowanie 
Omijanie przeszkód przez robota, wykrywanie obecności człowieka w konkretnym miejscu przed obiektem itp.
##### Biblioteka
- [Ping](https://playground.arduino.cc/Code/Ping/)
- [New Ping](https://bitbucket.org/teckel12/arduino-new-ping/wiki/Home)
# 
# 
#### Sterownik ULN2003 i silnik krokowy 28BYJ-48
![](foto/stepper.png)

Steruje silnikiem krokowym za pomocą 4 pinów cyfrowych.
Najłatwiej używać z biblioteką, ale dla zaawansowanych można też bez.
##### Biblioteka
- [podstawowa Stepper](https://www.arduino.cc/en/reference/stepper)
- [polecana AccelStepper](http://www.airspayce.com/mikem/arduino/AccelStepper/index.html)
# 
#### Silnik krokowy 28BYJ-48
Pozawala na bardzo precyzyjne i płynne poruszanie. Świetne nadaje się do płynnego poruszania szczególnie z małą prędkością.
#####  Parametry
- Napięcie: 5V
- 64 kroki na pełen obrót
- 4-fazowy
- Przekładnia 1:64
- Wymaga sterownika np. ULN2003
# 
# 
#### Serwo 
![](foto/sg90.png)

Serwomechanizm ustawia się pod zadanym w kodzie kontem. Jest szybki. Potrzebuje niewiele czasu by przesunąć owczych do zadanego konta. Jest lekki ale silny :)
##### Parametry
- Moment: 1,8 kg/cm
- Waga: 9g
- Prędkość: 0,12 s/60st
- Napięcie pracy: 4,5V - 6V
- Materiał trybów: tworzywo
- Złącze: servo JR
- Sterowanie i zasilanie: 
* brązowy - GND, 
* pomarańczowy - 5V, 
* żółty - pin cyfrowy 
##### Biblioteka 
- [Servo](https://www.arduino.cc/en/reference/servo)
# 
# 
#### Czujnik dźwięku - mikrofon - Iduino ST1146 
![](foto/Iduino-ST1146.png)

Detektor hałasu lub mikrofon. Posiada dwa wyjścia: 
- analogowe A0 - umożliwiające pomiar natężenia sygnału oraz 
- cyfrowe D0 - zmieniające stan po przekroczeniu ustalonego poziomu.
##### Parametry
- **Bez biblioteki**
- Podłącza się pod pin cyfrowy (hałas) lub analogowy (mikrofon)
- [Strona poroducenta](http://www.openplatform.cc/index.php/home/index/details/apiid/192)
# 
# 
#### LED RGB (full color)
![](foto/pierscien-led-rgb-7.jpg)

WoW! Jest kolorowo! Cztery diody kolorowe sterowane za pomocą jednego pinu. 
##### Parametry
- Sterownik **WS2812**
- Układ kolorów **GRB**
- Model całego układu CJMCU-2812-7
- Model diody 5050
##### Biblioteki
- [FastLED Animation Library](http://fastled.io)
- [Neopixel](https://learn.adafruit.com/adafruit-neopixel-uberguide)
# 
# 
#### Czujnik odbiciowy
![](foto/TCRT5000.png)

Wykrywa za pomocą światła podczerwonego przeszkody w niewielkich odległościach. Działa **bez biblioteki**
##### Parametry
- Zakres odległości: 0,2 cm - 10 cm
- Podłącza się po pinu analogowego wyjście A0 lub cyfrowego wyjście D0
- Moduł czujnika TCRT5000 
# 
# 
#### Fotorezystor 
![](foto/fotorezystor.png)

Nasz ulubiony czujnik. Wykrywa natężenie światła. Proste działanie, a można uzyskać ciekawą dynamikę np. sprzęgając sygnał z fotorezystora z reakcją serwomechanizmu.
##### Parametry
- Średnica 5 mm.
- Opór przy typowym oświetleniu 10k-20k.
- Opór zmienia się w zależności od natężenia padającego światłą.
- Podłącza się do pinu analogowego.
- Sprytnie bez rezystora z `INPUT_PULLUP`.
# 
# 
#### Przycisk chwilowy
![](foto/przyciski.png)

Przycisk chwilowy którego wciśniecie zwiera piny bliższe siebie (tak samo po dwóch stronach). Wystarczyłby 2 piny, ale są 4 żeby lepiej trzymało się płytki :)
##### Parametry
- wymiary 12x12x7,3mm.  
- 4 pin. 
# 
# 
#### OLED 0.91" 128x32px I2C
![](foto/oled.png)

Wyświetlacz OLED o przekątnej 0.91" i rozdzielczości 128 x 32 px. kolor wyświetlanych znaków - biały. Ekran oparty na sterowniku SSD1306 pracuje z napięciami 3,3 V oraz 5 V, komunikuje się poprzez interfejs I2C
##### Parametry
- Sterownik **SSD1306**
- rozdzielczości `128 x 32 px`
- Połączeni z Arduino przez `I2C` (SDA, SCL)
- napięcie 5V lub 3.3V
##### Biblioteki
- [Adafruit SSD1306](https://github.com/adafruit/Adafruit_SSD1306)
- [U8g2: Library for monochrome displays](https://github.com/olikraus/u8g2)
# 
# 
####  Diody LED 5 mm (9 szt.) - po 3 szt. czerwonych, zielonych i żółtych diod.
![](foto/diody.png)

Półprzewodnik. Świecie tylko jak krótsza noga do GND, a dłuższa do pinu. Nie podłączać bezpośrednio do GND i 5V po się spali :)
##### Parametry 

###### dioda żółta:
- Obudowa: DIP 5 mm
- Długość emitowanej fali: 589 nm
- Jasność: 40 mcd
- Kąt świecenia: 60 °
- Temp. pracy: od -40 °C do +80 °C
- Prąd If: 25 mA
- Napięcie Vf: 2,0 V

###### dioda zielona:
- Obudowa: DIP 5 mm
- Długość emitowanej fali: 571 nm
- Jasność: 100 - 150 mcd
- Kąt świecenia: 50°
- Temp. pracy: od-40 °C do +80 °C
- Prąd If: 20 mA
- Napięcie Vf: 2,3 - 2,5 V

###### dioda czerwona:
- Obudowa: DIP 5 mm
- Długość emitowanej fali: 625-645 nm
- Jasność: 450 - 800 mcd
- Kąt świecenia : 70 °
- Temp. pracy: od -40 °C do +80 °C
- Prąd If: 20mA
- Napięcie Vf: 2,0 - 2,3 V
# 
# 
#### Płytka stykowa
![](foto/plytka-stykowa.png)

Posłuży do tworzenia obwodów bez lutowania. Otowry wewnętrznier połączone, w każdej kolumnie `1,2,3,4,…,30` po pięć dziurek `a,b,c,d,e` oraz `f,g,h,i,j` jak zaznaczone na zdjęciu powyżej. Linie zasilania `+/-` połączone w poziomie. 
##### Parametry
- 400 otworów w zewnętrznymi stykami
# 
# 
#### Rezystory - 10 sztuk 220 Ω i po 5 sztuk 1 kΩ i 10 kΩ.
![](foto/rezystory.png)

Rezystor inaczej opornik. Ograniczna przepływ prądu. Np. 220Ω (Ohn) widoczy na zdjęciu ([kolory oznaczją wartość 220](https://resistorcolorcodecalc.com)) świetnie nadaje się do ograczniczenia prądu diody do wymagancych 20 mA. Można też robić dzielnik napięczia z fotorezystorem przy pomocy rezystora 10 kΩ itp.
##### Parametry
- moc 0,25W
- dokładność 5%
# 
# 
#### Potencjometr obrotowy 10kΩ
![](foto/potencjometr.png)

Proste pokrętło podłączone do wyprowadzeń analogowych pozwala płynnie regulować coś (prędkość, położenie serwa itp.). Kont obrotu pokrętła odczytujmemy jako wartość na wejściu analogowym. 
# 
# 
#### Tranzystor 2N2222
![](foto/2n2222.png)

Element półprzewodnikowy pozwalający m.in. sterować elementami, które pobierają większy prąd niż może dostarczyć pojedynczy pin mikrokontrolera.
##### Parametry
- Typ tranzystora: NPN
- Napięcie: 40 V
- Prąd: 0,6 A
- Obudowa: TO-92
# 
# 
#### Silnik 3V z wiatraczkiem
![](foto/silnik.png)

Choć niewielki, pobiera za dużo prądu jak na zasilanie pbepośrednio z pinu, tak jak można zrobić to z diodą LED. Można podłaczyć do za pomocą `transystora`.
# 
# 
#### Przewody 
![](foto/kable-MF.png)

Jakoś to wszytko trzeba połączyć. Przewody ze złączami. Możliwość szybkiego łączenia bez lutowania, bezpośrednio Arduino z czujnikami lub za pomocą płytki stykowej.
##### Rodzaj przewodów w zestawie
- 20cm - męsko-żeńskie w taśmie
- 20cm - męsko-męskie w taśmie
# 
