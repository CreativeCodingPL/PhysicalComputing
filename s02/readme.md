# Sezon 02 :: Miganie jak oddychanie. Płynna regulacja mocy.

## Poruszone zagadnienia
- PWM, czyli regulacja mocy poprzez pin cyfrowy. Takie udawanie świata analogowego na pinie cyfrowym poprzez zastosowanie pewnej sztuczni zwanej PWM. Więcej o tym tu: https://www.arduino.cc/en/Tutorial/PWM, albo na wypasie (trochę za szczegółowo ;)) opisane tu: http://forbot.pl/blog/artykuly/elektronika/kurs-elektroniki-ii-6-sterowanie-sygnalem-pwm-id9527
- port szeregowy Serial
- monitor aktywności portu szeregowego (serial monitor “lupa”);
- potencjometr. Zamiana kontu obrotu na wartość na wejściu analogowym.
- wejścia analogowe (A0 - A5);
- generowanie dźwięku. Buzzer i polecenie tone().

### Wprowadzone polecenia, zmienne, stałe, typy itp.
tone(), analogWrite(), map(), analogRead(), Serial.begin(), Serial.println();

### Wprowadzone sensory i aktuatory
- sensory: potencjometr, aktutory: buzzer

## Praca domowa
Obród potencjometru powoduje zapalanie się i gaszenie (obrót prawo / lewo) kolejnych z pięciu diod LED.
