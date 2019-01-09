# Sezon 05 :: Silnik krokowy i automat stanowy 

## Poruszone zagadnienia

### Silnik krokowy i biblioteka do sterowania silnikiem
- Silnik krokowy 28BYJ-48: 32 kroki na obrót; przekładnia 1:64
- Biblioteka AccelStepper do kontroli silnika krokowego.
- Komentarze do wszyskich użytych poleceń w kodzie przykładu e07_final

### Automat stanowy
- Albo bardziej formalnie Deterministyczne automaty skończone, to abstrakcyjna maszyna, takie wyobrażenie automatu, który ma stany i przejścia między nimi zachodzące pod pewnymi warunkami. Przydatny koncept, żeby nieco uporządkować myślenie o programowaniu nieco bardziej złożonych instalacji. U nas etapy przez jakie przechodzi zegar sterowany silnikiem krokowym, to odpowiedniki stanów, a warunki (if) decydujące kiedy mają nastąpić przejścia między etapami, to odpowiedniki przejść między stanami automatu.
- Przykład automatu: Schemat działania odtwarzacza wideo ![Przykład automatu: Schemat działania odtwarzacza wideo](http://edu.pjwstk.edu.pl/wyklady/jfa/scb/jfa-main-img229.png) 

## Praca domowa
Dokończyć plakaty

## Przydatne linki
- [Jak działa silnik krokowy na przykładzie 28BYJ-48](https://youtu.be/B86nqDRskVU)
- [AccelStepper Class Reference](http://www.airspayce.com/mikem/arduino/AccelStepper/classAccelStepper.html)

## Schematy

### Do wszyskich przykładów, jak podłączyć arduino i sterownik silnika krokowego
![](https://coeleveld.com/wp-content/uploads/2016/10/Arduino_Stepper_ULN2003A_28BYJ-48-1.jpg)
