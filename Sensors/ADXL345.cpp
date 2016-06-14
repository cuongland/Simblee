#include "Arduino.h"
#include "ADXL345.h"
#include "Wire.h"

//contructor
ADXL345::ADXL345()
{
}

void ADXL345::PowerOn(void)
{
	Wire.beginTransmission(ADDRESS_ADXL35_);
	Wire.write(POWER_CTL_REG);
	Wire.write(POWER_CTL_MEASURE);
	Wire.endTransmission();
}

void ADXL345::read_accelerometer(void)
{
	int temp;
	Wire.beginTransmission(ADDRESS_ADXL35_);
	Wire.write(DATAX0_REG);	
	Wire.endTransmission();
	Wire.beginTransmission(ADDRESS_ADXL35_);
	Wire.requestFrom(ADDRESS_ADXL35_, BUFFER_SIZE_ACC_);    // request 6 bytes from device

	for(temp = 0; temp<BUFFER_SIZE_ACC_; temp++)
	{
		if(Wire.available())
			buffer[temp] = Wire.read();
	}
	Wire.endTransmission();
	convert_data_accelerometer();
}

void ADXL345::convert_data_accelerometer(void)
{
	accelerometer_x = ACCELEROMETER_(buffer[0],buffer[1]);
	accelerometer_y = ACCELEROMETER_(buffer[2],buffer[3]);
	accelerometer_z = ACCELEROMETER_(buffer[4],buffer[5]);
}

int ADXL345::get_accelerometer_x(void)
{
	return accelerometer_x;
}
int ADXL345::get_accelerometer_y(void)
{
	return accelerometer_y;
}
int ADXL345::get_accelerometer_z(void)
{
	return accelerometer_z;
}
int ADXL345::get_address(void)
{
	return ADDRESS_ADXL35_;
}
