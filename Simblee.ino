#include "Sensors//ADXL345.h"
#include <Wire.h>
ADXL345 adxl345;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  adxl345.PowerOn();
}

void loop() { 
  adxl345.read_accelerometer();
  Serial.print("x= ");
  Serial.print(adxl345.get_accelerometer_x());  
  Serial.print(" ; y= ");
  Serial.print(adxl345.get_accelerometer_y());  
  Serial.print(" ; z= ");
  Serial.println(adxl345.get_accelerometer_z());  
  Serial.println("****************");
}
