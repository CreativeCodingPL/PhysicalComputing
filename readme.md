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
![](https://abc-rc.pl/data/gfx/icons/small/1/3/6231.jpg)

Ultradźwiękowy pomiar odległości 2 cm - 200 cm. 
##### Zastosowanie 
Omijanie przeszkód przez robota, wykrywanie obecności człowieka w konkretnym miejscu przed obiektem itp.
##### Biblioteka
- [Ping](https://playground.arduino.cc/Code/Ping/)
- [New Ping](https://bitbucket.org/teckel12/arduino-new-ping/wiki/Home)
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
#### Serwo 
![](https://static2.abc-rc.pl/pol_is_Serwo-TowerPro-SG-90-9g-1-8kg-cm-serwo-SG90-788.jpg)

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
#### Czujnik dźwięku 
![](https://abc-rc.pl/data/gfx/icons/small/0/1/6710.jpg)

Detektor hałasu lub mikrofon
##### Parametry
- LM393
- **Bez biblioteki**
- Podłącza się pod pin cyfrowy (hałas) lub analogowy (mikrofon)
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
![](https://abc-rc.pl/data/gfx/icons/small/7/1/7917.jpg)

Nas ulubiony czujnik. Proste działanie, a duże możliwości i nieograniczona pomysłowość do ztosowań.
##### Parametry
- Model GL5528 lub LDR5528
- [Specyfikacja pełna](https://cdn.sparkfun.com/datasheets/Sensors/LightImaging/SEN-09088.pdf)
- Średnica 5mm 
- Opór przy typowym oświetleniu 10k-20k
- Opór zmienia się w zależności od natężenia padającego światłą.
- Podłącza się do pinu analogowego.
- Pamiętajcie o `INPUT_PULLUP`
# 
# 
#### Przycisk chwilowy
![](https://static2.abc-rc.pl/pol_ps_Zestaw-przyciskow-do-Arduino-25-szt-switch-12x12x7-3mm-12441_1.jpg)

Przycisk chwilowy którego wciśniecie zwiera piny bliższe siebie (tak samo po dwóch stronach). Wystarczyłby 2 piny, ale są 4 żeby lepiej trzymało się płytki :)
##### Parametry
- wymiary 12x12x7,3mm.  
- 4 pin. 
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
