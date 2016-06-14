#include "Sensors//ADXL345.h"
#include "Sensors//HMC5883L.h"
#include <Wire.h>

//ADXL345 adxl345;
HMC5883L hmc5883l;

void setup() {  
  Serial.begin(9600);
  Wire.begin();
  
  hmc5883l = HMC5883L();
  hmc5883l.PowerOn_HMC5883();
}

void loop() { 
  hmc5883l.read_compass();
  Serial.print("x = ");
  Serial.print(hmc5883l.get_compass_x());
  Serial.print(" ; y = ");
  Serial.print(hmc5883l.get_compass_y());
  Serial.print(" ; z = ");
  Serial.println(hmc5883l.get_compass_z());
  Serial.println("*************************");
  delay(67);
}
