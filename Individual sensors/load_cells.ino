#include "HX711.h"

// Initialize HX711
HX711 scale;

// Define calibration factors
float calibration_factor = -10000.0; // Change this to calibrate the scale

void setup() {
  Serial.begin(9600);
  while (!Serial) {}
  
  // Initialize HX711
  scale.begin(2, 3); // DT pin is connected to Arduino pin 2, SCK pin is connected to Arduino pin 3
  
  // Set scale parameters
  scale.set_scale(calibration_factor);
  scale.tare();
}

void loop() {
  // Read weight
  float weight = scale.get_units();
  
  // Print reading to serial monitor
  Serial.print("Weight: ");
  Serial.print(weight);
  Serial.println(" kg");
  
  delay(1000); // Wait for a second before taking new reading
}
