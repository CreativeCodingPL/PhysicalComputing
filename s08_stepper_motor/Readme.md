# Sezon 08 :: Silnik
## Etap 02 obsługa silnika krokowego (stepper motor)

## Poruszone zagadnienia

### Poruszanie silnikiem 
Silnik ustawia się pod zadanym w kodzie kątem. Dokładność jest zależna od trybu: **AccelStepper::FULL4WIRE** - *szybciej, ale mniej dokładnie* lub **AccelStepper::HALF4WIRE** - *wolniej, ale dokładniej*. Ten model silnika (24BYJ48-N08W) pokonuje 360 stopni (jeden obrót) w 32 krokach. Przekładnia 64:1 . Do kontroli silnika krokowego używamy biblioteki [AccelStepper](http://www.airspayce.com/mikem/arduino/AccelStepper/classAccelStepper.html).

### Czujnik szczelinowy
Poprzez emisję wiązki światła podczerwonego można wykryć, kiedy obiekt przechodzi między słupkami. Napięcie zasilania jest równe od 3,3 V do 5 V. Czujnik posiada wyjście cyfrowe i analogowe. Po podłączeniu zasilania, na wyjściach pojawią się stany logiczne 0 lub 1 (wyjście cyfrowe), lub zakres 0-1023 (wyjście analogowe).

## Przydatne linki
- [Jak działa silnik krokowy na przykładzie 28BYJ-48](https://youtu.be/B86nqDRskVU)
- [AccelStepper Class Reference](http://www.airspayce.com/mikem/arduino/AccelStepper/classAccelStepper.html)


## Schematy

### Jak podłączyć arduino i sterownik silnika krokowego
![](https://coeleveld.com/wp-content/uploads/2016/10/Arduino_Stepper_ULN2003A_28BYJ-48-1.jpg)