
# Sezon 07 - protokół I2C - ekranik oled i MPU

## Poruszone zagadnienia

## i2c
- Protokó kominikacji między mikrokontolrerem a zewnętrznymi urządzeniami (bardziej zawansowane czujniki, ekrany etc.)
- Wymaga 4 kabelków - zasilanie + 2 do przesyłania danych - SDA i SCL (data i clock). Na Arduino uno R3 adekwatne piny są tak właśnie opisane, na Maker Uno SDA to pin A4 a SCL to pin A5.
- Protokół i2c jest pomyślany do integrowania urządzeń znajdujących się raczej blisko siebie - w praktyce na nieekranowanych zwykłych kabelkach może działać w odleglosci do parudziesięciu CM, może nawet ok metra ale raczej nie więcej.
- Na jednej linii danych może "wisieć" praktycznie dowolna liczba urządzeń (teoretycznie 128, realnie max 112) w konfiguracji master - slave (gdzie master to np. Arduino a slave to np. ekran oled).
- Każde urządzenie podpiete do mikrokntrolera via i2c musi mieć swój unikalny adres. Czasem adres jest ustawiony na twardo i nie możemy go zmienić, czasem jest możliwośc wyboru miedzy kilkoma adresami poprzez zlutowanie tzw. "zworek" na płytce urządzenia a w bardziej zaawansowanych modułach można adres utawić programistucznie za pomocą dodatkowych pinów.
- Za podstawowa obsługę i2c na arduino odpowiada wbudowana biblioteka `Wire`, musimy jednak ją explicite "zaincludować" - `#include <Wire.h>`
- Najczęściej nie piszemy kodu do obsługi poszczególnych urządzeń od podstaw tylko korzystamy z adekwatnhcy bibiliotek ukrywajacych szczegóły implementacji pod bardizej przyjaznym interfejsem. 
    
## MPU - akcelerometr + żyroskop

- Moduł MPU-6050 integruje dwa czujniki przyspieszenia - akcelerometr 3-osiowy, mierzący przyśpieszenia liniowe oraz żyroskop 3-osiowy mierzący przyśpieszenia kątowe (przyśpieszenie to zmiana prędkości w czasie). Jest to zatem czujnik 6DOF (six degrees of freedom) pozwalajacy na bardziej zawansowaną analizę ruchu / orientacji niż np. "goły" akcelerometr. Jednak wyciągnięcie danej orientacji wymaga obliczeń opo stronie mikrokontrolera. Biblioteka Adafruit z którą działaliśmy na zajęciach pozwala wyciagnac jedynie poszczególne odczyty dla obu czujników. Bardziej zaawansowana biblioteka np. `MPU6050_tockn` lub `TinyMPU6050` dostarczaja też funkcje zwracajace aktualną orientację czujnika ( czyli aktualny obrót w 3 osiach a nie zmiany przyśpieszeń ).


## OLED i Adafruit GFX

- Moduł SSD1306 to monochromatyczny ekran oled 128x32
- Adafruit dostarcza do niego bibliotekę `Adafruit SSD1306` powiązaną z biblioteką `Adafruit GFX`
- Biblioteka `Adafruit GFX` dostarcza szeregu metod pozwalających łatwo rysować na ekranie - pojedyncze pixele, linie, prostokąty, koła etc. Warto zajrzeć do wbudowanego przykąłdu, k†óry demonstruje większość dostepnych funkcji.


## Praca domowa:

1. Zhackować grę OLED + MPU - zmodyfikować timingi, grafikę, zasady.
2. Napisać sketch rysujacy dynamicznie na ekranie oled na podstawie inputu z dowolnego sensora / sensorów.
3. (powiązane z 1 i 2 ) Przetestować alternatywna biblotekę do obsługi MPU pozwalajaca na odczyt orientacji sensora (vide opis w sekcji MPU powyżej)



## Materiały pomocnicze

- [video wyjaśniajace i2c](https://www.youtube.com/watch?v=6IAkYpmA1DQ)
- [opis biblioteki Adafruit GFX](https://learn.adafruit.com/adafruit-gfx-graphics-library)

