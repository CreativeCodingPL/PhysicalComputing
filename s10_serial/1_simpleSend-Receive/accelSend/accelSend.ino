#include <MPU6050_tockn.h>
#include <Wire.h>

MPU6050 mpu6050(Wire);
long timer = 0;

void setup() {
  
  Serial.begin(9600);
  Wire.begin();
  //mpu6050.begin();
  //mpu6050.calcGyroOffsets();

}

void loop() {

  //mpu6050.update();

  if(millis() - timer > 10){

    //Serial.print(mpu6050.getAngleX());
    Serial.print( random( 0, 180.0 ) );
    Serial.print( "," );
    //Serial.print(mpu6050.getAngleY());
    Serial.print( random( 0, 180.0 ) );
    Serial.print( "," );
    //Serial.println(mpu6050.getAngleZ());
    Serial.println( random( 0, 180.0 ) );

    timer = millis();
    
  }
 
}
