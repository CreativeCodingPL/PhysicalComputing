

void setup() {
	//rozpoczyna komunikację z komputerem 
	//po porcie szeregowym z predkością 9600
	//można podejrzeć programem odpalanym w arduino 
	//przez lubę lub Tools->Serial Monitor
	Serial.begin(9600);

}

void loop() {
	//Sensor podłączony pod A0
	Serial.println( analogRead(A0) );

}
