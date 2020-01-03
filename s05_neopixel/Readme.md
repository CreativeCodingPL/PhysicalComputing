# Sezon 05 :: NeoPixele i czujnik odległości IR

## Poruszone zagadnienia

### NeoPixels RGBW
- diody sterowane za pomocą jednego pinu. Każda dioda ma wbudowany swój własny mikrokontroler (driver) WOW!
- Każda dioda ma trzy barwy składowe R, G, B, Stąd RGB. Są też z dodatkową diodą białą (W)! Wtedy RGBW. U nas zamieniona jest kolejność, czyli mamy diodę GRB. Dlatego na początku piszemy `Adafruit_NeoPixel pixels(NUMPIXELS, NEOPIXEL_PIN, NEO_GRB + NEO_KHZ800);`
- `pixels.begin();` aktywuje bibliotekę
- `pixels.show();` aktualizuje stan diod
- `pixels.clear();`
- `pixels.setPixelColor(i, C);` 
- `pixels.Color(R, G, B);`

### [Czujnik odbiciowy](https://github.com/CreativeCodingPL/PhysicalComputing/tree/2019/s01_pierwsza_dioda_i_prezenty#czujnik-odbiciowy) - IR Sensor odległości
- Ocenia odległość oświetlając obiekty światłem podczerwonym (dioda IR) i sprawdzając natężenie odbytego światła (dioda foto-czuła IR). Orientacyjny zakres odległości: 0,2 cm - 60 cm. 


## Materiały pomocnicze 
- [The Magic of NeoPixels - Adafruit NeoPixel Überguide](https://learn.adafruit.com/adafruit-neopixel-uberguide/the-magic-of-neopixels)
- [DESIGN YOUR CIRCUIT WITH CIRCUITO.IO](https://www.circuito.io)
- [Fritzing - document prototypes](http://fritzing.org/home/)
- [AdaFruit Fritzing Library](https://github.com/adafruit/Fritzing-Library)

## Schematy

### e04_wedrowiecPokretlo
![](e04_wedrowiecPokretlo.png)

### e05_wedrowcyDwajFoto
![](e05_wedrowcyDwajFoto.png)
