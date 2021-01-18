# Sezon 01 - lutowanie i miganie

Pierwsze zajęcia offlinie. Zaczęliśmy of rozdania prezentów :)

## Prezent

![](zestaw.jpg)

## Poruszone zagadnienia

### Lutowanie
- Jak poprawnie wykonywać luty.
- Trening lutowania na module pierściania LED. Dolutowanie goldpin (nie wszysko złoto co … ;)).

![](goldpin.jpg)

- [Soldering (cool!) video)](https://youtu.be/QKbJxytERvg)
- [Przewodnik lutowania z Adafruit](https://learn.adafruit.com/adafruit-guide-excellent-soldering)

### Maker UNO - malezyjskie Arduino, świetne!
![](https://ksr-ugc.imgix.net/assets/020/483/931/36dac5c036b77eac5bf85a26b23f0b8e_original.gif?w=680&fit=max&v=1520485057&auto=format&gif-q=50&q=92&s=6cafeb7a1e9447f19d8a729d2fe50367)

Twórczo przetworzona oryginalna koncepcja Arduino, z przydatnymi  podczas nauki modyfikacjam. Dodatkowe 12 Led przy każdym pinie cyfrowym, dodatkowy przycisk na pinie 2, oraz głośniczek na pinie 8.

- [Detale techniczne i drivery](https://www.cytron.io/c-arduino/c-arduino-main-board/p-maker-uno-simplifying-arduino-for-education) 
- [Maker UNO: Simplifying Arduino for {Education}](https://makeruno.com.my)

- Wgrywanie kodu na Arduino, wygór kłytki, portu.
- Miganie diodami wlutowanymi w Maker Uno, instrukcje `pinMode();` `digitalWrite(7, HIGH);` `delay(400);`
- Beep! Beep! instrukcja `tone(8, 440);`
- Pierścień `LED RGB 7 x WS2812 5050`

![](../foto/pierscien-led-rgb-7.jpg)

- `Adafruit NeoPixel` Library, do obsługi `LED WS2812` zwanych też `NeoPixel`
- Jak instalować biblioteki: Arduino IDE, wybrać w menu `Sketch > Include Library > Manage Libraries`, a następnie wyszukać bibliotekę wpisując np. neopixel

![](library_manager.png)

- Podłączenie Neopixel do Arduino

![](led-arduino.jpg)

- Przykładowy kod `strandtest`. Wymaga zainstalowania biblioteki `Adafruit NeoPixel`

- Na koniec zajęć przykład z POV (Persistence of Vision) `MakerUno_POV`

![](POV.png)



