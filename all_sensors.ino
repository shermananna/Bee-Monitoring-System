#include "SparkFun_SGP40_Arduino_Library.h" 
#include <Wire.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <HX711.h>

SGP40 mySensor; 
HX711 scale;

#define ONE_WIRE_BUS 2
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

float calibration_factor = -10000.0;

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

  while (!Serial) {}
  
  // Initialize HX711
  scale.begin(3, 4); // DT pin is connected to Arduino pin 2, SCK pin is connected to Arduino pin 3
  
  // Set scale parameters
  scale.set_scale(calibration_factor);
  scale.tare();
}

void loop()
{
  Serial.print(F("VOC Index is: "));
  Serial.println(mySensor.getVOCindex());


  sensors.requestTemperatures();
  float tempC = sensors.getTempCByIndex(0);
 
  if(tempC != DEVICE_DISCONNECTED_C)
  {
    Serial.print("Temperature for the device 1 (index 0) is: ");
    Serial.println(tempC);
  }

  else
  {
    Serial.println("Error: Could not read temperature data");
  }

 float weight = scale.get_units();
  
  // Print reading to serial monitor
  Serial.print("Weight: ");
  Serial.print(weight);
  Serial.println(" kg");

  delay(1000); 

}
