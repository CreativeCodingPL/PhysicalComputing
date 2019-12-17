## Prezent

![](zestaw.jpg)

### Zestaw w całej okazałości

Otrzymaliście na własność zestaw do eksperymentów na zajęciach i po zajęciach też :)

# 
#### Maker UNO - malezyjskie Arduino, świetne!
![](https://ksr-ugc.imgix.net/assets/020/483/931/36dac5c036b77eac5bf85a26b23f0b8e_original.gif?w=680&fit=max&v=1520485057&auto=format&gif-q=50&q=92&s=6cafeb7a1e9447f19d8a729d2fe50367)

Twórczo przetworzona oryginalna koncepcja Arduino, z przydatnymi  podczas nauki modyfikacjam. Dodatkowe 12 Led przy każdym pinie cyfrowym, dodatkowy przycisk na pinie 2, oraz głośniczek na pinie 8.

- [Detale techniczne i drivery](https://www.cytron.io/c-arduino/c-arduino-main-board/p-maker-uno-simplifying-arduino-for-education) 
- [Maker UNO: Simplifying Arduino for {Education}](https://makeruno.com.my)
# 

### Pozostałe komponenty w zestawie
Niektóre gotowe do użycia, inne wymagające dolutowania kabli lub gold pinów. Jednym słowem wsypko co niezbędne, żeby nauczyć się podstaw konstruowania obwodów elektorniczny do tworzenia instalacji.

# 
#### Wyświetlacz LCD 2x16
 ![](https://abc-rc.pl/data/gfx/icons/small/1/8/6181.jpg)

W starym dobrym stylu wyświetlanie dwóch lini tekstu po 16 znaków każda.
##### Parametry
- Sterowniki HD44780 
- Model QC1602A
##### Biblioteka
- [Liquid Crystal Library](https://www.arduino.cc/en/Tutorial/LiquidCrystalDisplay)
# 
# 
#### Czujnik ultradźwiękowy - HC-SR04  
![](https://abc-rc.pl/data/gfx/icons/small/1/3/6231.jpg)

Ultradźwiękowy pomiar odległości 2 cm - 200 cm. 
##### Zastosowanie 
Omijanie przeszkód przez robota, wykrywanie obecności człowieka w konkretnym miejscu przed obiektem itp.
##### Biblioteka
- [Ping](https://playground.arduino.cc/Code/Ping/)
- [New Ping](https://bitbucket.org/teckel12/arduino-new-ping/wiki/Home)
# 
# 
#### Czujnik ciśnienia i temperatury - GY-68 BMP180
![](https://abc-rc.pl/data/gfx/icons/small/8/9/6298.jpg)

Pomiar ciśnienia i temperatury.
##### Parametry
- Sterowanie po `I2C` (piny `STL` `STC`)
##### Biblioteka
- [Adafruit-BMP085-Library](https://github.com/adafruit/Adafruit-BMP085-Library)
# 
# 
#### Radio 2.4GHz - nRF24L01 
![](https://abc-rc.pl/data/gfx/icons/small/7/0/6407.jpg)

Łączność radiowa. 
##### Parametry
- Sterowanie SPI, czyli Arduino podłącza się za pomocą 5 pinów.
- Zasięg do 80 m.
- Jednoczesna komunikacja na 5 kanałach. Jeden do pięciu. 
##### Biblioteka
- [Optimized High Speed NRF24L01+ Driver](http://tmrh20.github.io/RF24/Arduino.html)
# 
# 
#### Sterownik do silnika krokowego - ULN2003 V3
![](https://abc-rc.pl/data/gfx/icons/small/2/2/6522.jpg)

Steruje silnikiem krokowym za pomocą 4 pinów cyfrowych.
Najłatwiej używać z biblioteką, ale dla zaawansowanych można też bez.
##### Biblioteka
- [podstawowa Stepper](https://www.arduino.cc/en/reference/stepper)
- [polecana AccelStepper](http://www.airspayce.com/mikem/arduino/AccelStepper/index.html)
# 
#### Silnik krokowy - 24BYJ48-N08W
![](https://abc-rc.pl/data/gfx/icons/small/1/7/12371.jpg)

Pozawala na bardzo precyzyjne i płynne poruszanie. Świetne nadaje się do płynnego poruszania szczególnie z małą prędkością.
#####  Parametry
- Napięcie: 5V
- 64 kroki na pełen obrót
- 4-fazowy
- Przekładnia 1:64
- Wymaga sterownika np. ULN2003
# 
# 
#### Sterownik L9110 do silników DC - HG7881
![](https://abc-rc.pl/data/gfx/icons/small/9/0/6709.jpg)

Pozwala na sterowanie dwoma silnikami DC.

- [Jak działa - wideo](https://youtu.be/q-C__0ysSis)
- *Bez biblioteki*
- podłącza się pod piny cyfrowe
# 
#### Silnik DC 6V z przekładnią 1:48 oraz koło 65 mm
![](https://abc-rc.pl/data/gfx/icons/small/2/9/6292.jpg)

Pozwala na poruszanie ze zmienną prędkością i umiarkowaną precyzją, za to dużą prędkością. Słabo nadaje się do poruszania z małą prędkością. Dobry do napędzania np. kół pojazdów.

- Wymaga sterownika np. L9110
# 
# 
#### Akcelerometr i żyroskop 3-osiowe XYZ - MPU-6050 i GY-521
![](https://abc-rc.pl/data/gfx/icons/small/2/7/6572.jpg)

Pomiar ruchu obiektu w przestrzeni. Przyspieszenia i obroty.

- Akcelerometr MPU-6050
- Żyroskop GY-521
# 
# 
#### Czujnik dźwięku 
![](https://abc-rc.pl/data/gfx/icons/small/0/1/6710.jpg)

Detektor hałasu lub mikrofon
##### Parametry
- LM393
- **Bez biblioteki**
- Podłącza się pod pin cyfrowy (hałas) lub analogowy (mikrofon)
# 
# 
#### Wyświetlacz LED 4 cyfry 
![](https://abc-rc.pl/data/gfx/icons/small/7/1/6717.jpg)

Wyświetla cyfry, ale też można robić efekty specjalne, glitch itp.
##### Parametry
- Dołączony sterownik TM1637
- 4 x 7 segmentów
- dwukropek 
##### Biblioteka
- [podstawowa - TM1637](https://playground.arduino.cc/Main/TM1637/)
- [fajniejsza - bremme/arduino-tm1637](https://github.com/bremme/arduino-tm1637)
# 
# 
#### Czujnik optyczny szczelinowy - LM393
![](https://abc-rc.pl/data/gfx/icons/small/2/5/7652.jpg)

Może być używany np. jako enkoder (pomiar prędkości obrotu lub liczby obrotów koła) lub czujnik krańcowy (pozycja startowa silnika krokowego).

- Szczelina o szerokości 5mm. 
- Jak coś zasłania szczelinę to na wyjściu stan niski.
- **Bez biblioteki**
- Podłącza się pod pin cyfrowy.
# 
# 
#### LED RGB 5050 sterownik WS2812 - CJMCU2814
![](https://abc-rc.pl/data/gfx/icons/small/7/7/9177.jpg)

WoW! Jest kolorowo! Cztery diody kolorowe sterowane za pomocą jednego pinu. 

##### Biblioteki
- [FastLED Animation Library](http://fastled.io)
- [Neopixel](https://learn.adafruit.com/adafruit-neopixel-uberguide)
# 
# 
#### Czujnik odbiciowy
![](https://abc-rc.pl/data/gfx/icons/small/6/0/10006.jpg)

Wykrywa przeszkody w zakresie od 0,2cm do 60cm

- **Bez biblioteki**
- Podłącza się pod wejście analogowe.
# 
# 
#### Przekaźnik 
![](https://abc-rc.pl/data/gfx/icons/small/7/0/12107.jpg)
##### Zastosowania
Sterowanie za pomocą Arduino urządzeniami zasilanymi z kontaktu. **Bez biblioteki**
##### Parametry 
- Sterowanie 5V (Arduino) 
- Urządzenie sterowane 250V / 10A
# 
# 
#### Fotorezystor 10k-20k - GL5528
![](https://abc-rc.pl/data/gfx/icons/small/7/1/7917.jpg)

Nas ulubiony czujnik. Proste działanie, a duże możliwości i nieograniczona pomysłowość do ztosowań.

- Średnica 5mm, LDR 5528
- Opór zmienia się w zależności od natężenia padającego światłą.
- *Bez biblioteki*
- Podłącza się do pinu analogowego.
- Pamiętajcie o INPUT_PULLUP
# 
# 
#### Przycisk chwilowy
![](https://static2.abc-rc.pl/pol_ps_Zestaw-przyciskow-do-Arduino-25-szt-switch-12x12x7-3mm-12441_1.jpg)

Przycisk o wymiarach 12x12x7,3mm.  Ma 4 pin. Wciśniecie zwiera piny bliższe siebie (tak samo po dwóch stronach). Wystarczyłby 2 piny, ale są 4 żeby lepiej trzymało się płytki :)

# 
# 
#### Dioda LED zielona
![](https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcSb5ToV2svfayvkFEODJulwK6WodHI8Qrb534G-zYm_1TRBZ2ZrBw&s)

Półprzewodnik. Świecie tylko jak krótsza noga do GND, a dłuższa do pinu. Nie podłączać do GND i 5V po się spali :)

##### Parametry 
- Zielona 
- Dyfuzyjna 
- Średnica 5 mm 
- Pobór prądu 20 mA
# 
# 
#### Dioda laserowa czerwona
![](https://abc-rc.pl/data/gfx/icons/small/7/9/8497.jpg)

Można zrobić zabawkę dla kota, albo rysować wzory na suficie.
#####  Parametry
- Napięcie pracy: 5V 
- Długości światłą: 650nm 
- Moc: 5mW - to sporo! **uwaga na oczy!**
# 
# 
#### Ładowarka sieciowa USB 5V + Przewód Micro USB 
![](https://abc-rc.pl/data/gfx/icons/small/7/3/8237.jpg)

Zasilanie układu bez komputera - samo działa, tak Arduino dziką bez komputera :)

Przewód to zasilania lub programowania.
# 
# 
#### Płytka uniwersalna  
![](https://abc-rc.pl/data/gfx/icons/small/8/2/10128.jpg)

Służy do budowy prototypów za pomocą lutowania. Trwałe połączenia, a prototyp podziała długo jak na prototyp. 

Posłuży też do nauki lutowania.

##### Parametry
- dwustronna 
- PCB 
- montaż THT
- wymiary 30x70mm 
- model PI22Z
- pola lutownicze ocynowane z otworami
# 
# 
#### Płytka stykowa
![](plytka-stykowa.jpg)

Połączone w każdej kolumnie po pięć dziurek jak zaznaczone na pomarańczowo na zdjęciu powyżej.
##### Zastosowanie
Posłuży do tworzenia obwodów bez lutowania.
##### Parametry
- 170 otworów w zewnętrznymi stykami
# 
# 
#### Przewody 
![](https://abc-rc.pl/data/gfx/icons/small/1/6/8761.jpg)

Jakoś to wszytko trzeba połączyć. Przewody ze złączami. Możliwość szybkiego łączenia bez lutowania, bezpośrednio Arduino z czujnikami lub za pomocą płytki stykowej.
##### Rodzaj przewodów w zestawie
- 20cm - męsko-żeńskie w taśmie
- 10cm - męsko-żeńskie w taśmie
- 20cm - męsko-męsko luzem
# 

