# Sezon 03 - sonar, mikrofon, zamiana dzwieku na ruch

## Poruszone zagadnienia


### NewPing

- Bibloteka do obłsugi czujików ultradźwiękowych - "sonar"
- Czujnik [HC-SR04](https://botland.com.pl/ultradzwiekowe-czujniki-odleglosci/1420-ultradzwiekowy-czujnik-odleglosci-hc-sr04-2-200cm-5903351241366.html)

### Moduł mikrofonu elektretowego

- [Mikrofon elektretowy](https://pl.wikipedia.org/wiki/Mikrofon_elektretowy#:~:text=Mikrofon%20elektretowy%20o%20trzech%20ko%C5%84c%C3%B3wkach.)
- Moduł [Iduino ST1146](https://botland.com.pl/mikrofony-i-detektory-dzwieku/14292-czujnik-dzwieku-mikrofon-iduino-se019-5903351241946.html)
- Korzystamy z wyjscia analogowego - "AO"


### Pętla while

- while to pętla która wykonuje się do czasu aż warunek zakończenia pętli zdefinowany w nawiasach okrągłych `while(warunek)` nie stanie się fałszywy - stosujemy gdy petla for nie miała by sensu, gdyż nie stosujemy żadnegol licznika a coś innego determinuje wykonanie pętli. W przykąłdzie e02-e03 sprawdzamy czas jaki upłynął od momentu rozpoczęcia "zapętlenia".

- millis() - funkcja analogiczna do tej z Processing zwraca czas który upłynał od uruchomienia programu do momentu jej wywyołania

- Pomiar amplitudy dźwięku - aby okjreslić głośność musimy tak na prawde porównać maksymalną wartość jaka otrzymamy na analogowym oinie z minimalną w danym okresie czasu. Dopiero róznica miedzy odczytami daje nam amplitudę, czyli glośćność dźwięku

- Wygładzanie wartosci zmiennej w czasie
	- `wygladzonaZmienna = (0.3 * najnowszaWartosc) + (0.7 * wygladzonaZmienna);`
    - prosta sztuczka która pozwala "wygładzić" wartość zmiennej - w pewnym sensie mieszamy w okresloncyh proporcjach najnowsza wartosc jaka chcielibysmy jej przypisac z poprzednim jej stanem, zmieniajac proporcje miedzy `najnowszaWartosc` (np. ostatni odczyt z sensora) i poprzednia wartoscia `wygladzonaZmienna` możemy bardziej lub mniej wygladzac, kosztem "responsywnosci" - szybciej lub wolniej wartosc zmiennej "dojedzie" nam do najbardziej aktualnego stanu...

## Materiały pomocnicze

- [Biblioteka NewPing](https://playground.arduino.cc/Code/NewPing/)
- [millis()](https://www.arduino.cc/reference/en/language/functions/time/millis/)

## Praca domowa

Połączyć servo i sonar analogicznie do przykladu z mikrofonem, poeksperymentować z wygladzaniem ruchu servo w odpowiedzi na odczyty z sonaru.

