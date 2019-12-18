# Sezon 02 :: akcja - reakcja; fotorezystor - serwo;

## Poruszone zagadnienia
### Sin oddech
- podsumowanie `PWM`
- oddychanie sin’usem za pomocą `PWM`. 
- `sin(t)` - zamienia wzrost t na falowanie. Tempo wzrostu `t` przekłada się na tempo falowania.
### Serial
- `Serial`, czyli przesyłanie danych pomiędzy Arduino i komputerem. Podgląd transmisji z pomocą serial monitor.
- port szeregowy Serial
- `Serial.begin()`, `Serial.println()` 
- monitor aktywności portu szeregowego (serial monitor “lupa”);
### Wejścia analogowe
- Wejścia/wyjścia analogowe/cyfrowe
- wejścia analogowe (`A0 - A5`);
- Wejścia analogowe, czyli o przetwarzaniu wartości ciągłych ze świata rzeczywistego na postać cyfrową np. temperatura, waga, jasność światłą itp. 
- `analogRead()`
### Fotorezystor
- [Fotorezystor](https://github.com/CreativeCodingPL/PhysicalComputing/tree/2019/s01_pierwsza_dioda_i_prezenty#fotorezystor) to prosty czujnik natężenia światła.
- jak podłączyć sprytnie czyli: `pinMode(A0, INPUT_PULLUP);`
- Tryb pracy pinu `INPUT_PULLUP`, czyli o włączaniu wewnętrznego rezystora za pomocą kodu. WoW! Można tworzyć obwody elektroniczne kodem?!
### Serwo
- [Serwomechanizm](https://github.com/CreativeCodingPL/PhysicalComputing/tree/2019/s01_pierwsza_dioda_i_prezenty#serwo), czyli silniczek z przekładnią i końcówką (na którą możemy zakładać "cosiki" zwane też orczykami), którą możemy ustawić pod kontem od 0 do 180 stopni. ### Fotorezystor
- Biblioteka i obiekt `Serwo`
- `servo.attach()`, `servo.write()`

## Materiały pomocnicze
- [Więcej o serwomechanizmie](https://learn.adafruit.com/adafruit-arduino-lesson-14-servo-motors/) 
- [Biblioteka Servo](https://www.arduino.cc/en/Reference/Servo)
- [Wejścia analogowe](https://www.arduino.cc/en/Tutorial/AnalogInput)

## Schematy



