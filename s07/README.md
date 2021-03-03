
# Sezon 07 - czujniki pojemnościowe

## Poruszone zagadnienia

- Biblioteka ADCTouch
- tone

## ADCTouch

- ```ADCTouch.read(analogPin)``` - zczytuje wartosc pojemnosci z pinu analogowego - wartość 0-1023. Warto zrobić odczyt wartości referencyjnej w setup
- ```ADCTouch.read(analogPin, samples)``` - to co powyższe tylko robi wiele odczytów i zwraca uśrednioną wartość

## Tone

- ```tone(pin, frequency)``` -  odtwarza dzwięk na pinie o podanej częstotliwości dopóki go nie zmienimy lub wyłączymy
- ```tone(pin, frequency, duration)``` - odtwarza dzwięk na pinie o podanej częstotliwości przez podany czas (w ms)
- ```noTone(pin)``` - wyłącza dzwięk na pinie


## Materiały pomocnicze

- [biblioteka ADCTouch](https://playground.arduino.cc/Code/ADCTouch/)
- [tone](https://www.arduino.cc/reference/en/language/functions/advanced-io/tone/)
