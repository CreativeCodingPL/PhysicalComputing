
# Sezon 08 - komunikacja Processing <-> Arduino

## Poruszone zagadnienia

## Serial 
- Serial po stronie Processing:
	* Pamietać o takm samym "baud rate" - np. 9600 po stronie Arduino jak i Processing - ```new Serial(this, portName, 9600);```
    * ```Serial.list()``` - wypisuje wszystkie porty dostepna na komputerze - przy incjalizacj portu musimy wskazac ten na ktorym jest Arduino
    * ```bufferUntil('\n');``` - powoduje że Prcessing bedize odczytwyac dane z bufora dopiero jesli napotka znak nowej linii - ```\n```
    * ```serialEvent( Serial port ) ``` - wbudowana metoda w processing wywoływana kiedy na porcie pojawia sie nowe dane (lub tylko wtedy jesli pojawil sie znak zdefiniowany via ```bufferUntil()```. UWAGA - ta metoda wywoluje sie niezleznie od ```draw()``` wiec należy korzystać ze zmiennych globalnych by przypisywac im wartosci przychodzace z portu i potem odwolywac sie do nich w ```draw()```
    * ```myPort.write()``` - metoda write pozwala na wyslanie pojedynczego bajtu lub calej sekwencji bajtow (moga byc wyslane jako tekst) na port
- Serial po stronie Arduino:
	* ```Serial.available()``` - sprawdza czy sa jakies dane w buforze
    * ```Serial.read()``` - odczytuje pojedynczy, ostatni bajt z bufora. UWAGA - odczytanie jednoczesnie usuwa dane z bufora.




## Materiały pomocnicze

- [dokumentacja Serial w Processing](https://processing.org/reference/libraries/serial/index.html)
- [dokumentacja Serial w Arduino](https://www.arduino.cc/reference/en/language/functions/communication/serial/)
- [tabela kodów ASCII](https://en.wikipedia.org/wiki/ASCII)
