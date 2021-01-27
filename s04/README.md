# Sezon 04 :: NeoPixele, potencjometr i wyświetlacz OLED, automat stanowy

## Poruszone zagadnienia

### NeoPixels RGB

- diody sterowane za pomocą jednego pinu. Każda dioda ma wbudowany swój własny mikrokontroler (driver) WOW!
- Każda dioda ma trzy barwy składowe R, G, B, Stąd RGB. Są też z dodatkową diodą białą (W)! Wtedy RGBW. U nas zamieniona jest kolejność, czyli mamy diodę GRB. Dlatego na początku piszemy `Adafruit_NeoPixel pixels(NUMPIXELS, NEOPIXEL_PIN, NEO_GRB + NEO_KHZ800);`
- `pixels.begin();` aktywuje bibliotekę
- `pixels.show();` aktualizuje stan diod
- `pixels.clear();` gasi wszystkie diody
- `pixels.setPixelColor(i, R, G, B);` ustawia kolor diody `i` na podstawie podanych składowych `R, G, B`.
- `pixels.Color(R, G, B);` tworzy kolor, który można zapisać w jednej zmiennej.

### Potencjometr

- Podłączenie potencjometru
  - 2 skrajne nóżki: GND/VCC lub VCC/GND (od kolejności zależy kierunek wartości)
  - środkowa nóżka do pinu analogowego

### Wyświetlacz OLED

- Biblioteka Adafruit SSD1306
- Biblioteka Adafruit GFX
- Protokół I2C

### Automat stanowy

- Albo bardziej formalnie Deterministyczne automaty skończone, to abstrakcyjna maszyna, takie wyobrażenie automatu, który ma stany i przejścia między nimi zachodzące pod pewnymi warunkami. Przydatny koncept, żeby nieco uporządkować myślenie o programowaniu nieco bardziej złożonych instalacji. U nas etapy przez jakie przechodzi zegar sterowany silnikiem krokowym, to odpowiedniki stanów, a warunki (if) decydujące kiedy mają nastąpić przejścia między etapami, to odpowiedniki przejść między stanami automatu.
- Przykład automatu: Schemat działania odtwarzacza wideo ![Przykład automatu: Schemat działania odtwarzacza wideo](http://edu.pjwstk.edu.pl/wyklady/jfa/scb/jfa-main-img229.png)

## Materiały pomocnicze
- [The Magic of NeoPixels - Adafruit NeoPixel Überguide](https://learn.adafruit.com/adafruit-neopixel-uberguide/the-magic-of-neopixels)
- [Adafruit GFX Graphics Library](https://learn.adafruit.com/adafruit-gfx-graphics-library/overview)