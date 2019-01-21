# Sezon 8 - komunikacja Serial

## Ogólne
- baudrate - prędkość komunikacji - musi być taka sama w Arduio i Prcessing
- najczestszy baudrate 9600, maksymalny bezpieczny 115200
- znaki końca komunikatu - \n, \r
- wykorzystanie biblioteki SerialCommand do obslugi komunikacji Processing -> Arduino

## Processing
- Wbudowane biblioteki Serial Arduinio i Processing
- serialEvent()
- serial.wtite()


## Arduino
- Serial.println() 
- Serial.write()


## Praca domowa
- Dokończyć przykład joystickDrawing - tak by faktycznie rysowała się jakaś kreska, lib inne formy, obłśuga "klikniecja" jopysticka do zmiany trybu rysowania
- Na bazie któregoś z przykłądu komunikacji Arduino -> Processing lub Processing -> Arduino zrobić własny wariant z innym sensorem / diodą / servo po strponie Arduino i inną reakcja / interfejsem po stronie Processing


## Materiały dodatkowe
- [Wbudowana biblioteka Serial processing](https://processing.org/reference/libraries/serial/index.html)
- [Wbudowana bibiloteka Serial arduino](https://www.arduino.cc/reference/en/language/functions/communication/serial/)
- [Biblioteka Arduino-SerialCommand](https://github.com/kroimon/Arduino-SerialCommand)

