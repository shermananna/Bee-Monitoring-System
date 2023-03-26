#include "SparkFun_SGP40_Arduino_Library.h" 
#include <Wire.h>

void setup()
{
  Serial.begin(9600);
  Wire.begin();

  if (mySensor.begin() == false)
  {
    Serial.println(F("SGP40 not detected. Check connections. Freezing..."));
    while (1)
      ; 
  }

  sensors.begin();
  
  void loop()
{
  Serial.print(F("VOC Index is: "));
  Serial.println(mySensor.getVOCindex());
    
    delay(1000); 

}
