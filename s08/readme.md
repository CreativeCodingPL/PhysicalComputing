# Sezon 08 :: Stepper motory - wrrrr 

## Poruszone zagadnienia
- Sterowanie stepper motor. Jak jest zbudowany? Jak działa i jak go kontrolować za pomocą arduino?

### Wprowadzone nowe polecenia, typy, biblioteki i inne elementy
- biblioteki: CheapStepper; AccelStepper
- polecenia CheapStepper: step(kierunek obrotu), CheapStepper stepper (pin,pin,pin,pin).
- polecenia AccelStepper: setMaxSpeed(), setAcceleration(), setSpeed(), moveTo(), distanceToGo(), run().

## Praca domowa
Ruch na tarczy w wybrane pozycje. Nauczyć się kontrolować położenie silnika z użyciem poleceń moveTo() oraz distanceToGo().

## Materiały pomocnicze 
- Jak działa stepper motor: https://youtu.be/B86nqDRskVU
- CheapStepper: https://github.com/tyhenry/CheapStepper
- AccelStepper: http://www.airspayce.com/mikem/arduino/AccelStepper/index.html
