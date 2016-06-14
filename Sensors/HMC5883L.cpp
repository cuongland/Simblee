#include "Arduino.h"
#include "HMC5883L.h"
#include "Wire.h"

//contructor
HMC5883L::HMC5883L()
{	
}

int HMC5883L::get_address_HMC5883L(void)
{
	return ADDRESS_HMC5883L_;
}

void HMC5883L::writeto_HMC5883L(int address_reg, int value)
{
	Wire.beginTransmission(ADDRESS_HMC5883L_);
	Wire.write(address_reg);
	Wire.write(value);
	Wire.endTransmission();
}

void HMC5883L::PowerOn_HMC5883(void)
{
	//8-average, 15 Hz default
	writeto_HMC5883L(CONDFIGURATION_REG_A, ( (1<<MA1)|(1<<MA0)|(1<<DO2) ) );	
	//gain is 5
	writeto_HMC5883L(CONDFIGURATION_REG_B, ((1<<GN2)|(1<<GN0)) );
	//continuous-measurement mode
	writeto_HMC5883L(MODE_REG_, 0x00 );
}

void HMC5883L::read_compass(void)
{
	int temp;
	Wire.beginTransmission(ADDRESS_HMC5883L_);
	Wire.write(DATAX_H_X_M_REG);	
	Wire.endTransmission();
	delay(6);
	Wire.beginTransmission(ADDRESS_HMC5883L_);
	Wire.requestFrom(ADDRESS_HMC5883L_, BUFFER_SIZE_HMC_);    // request 6 bytes from device

	for(temp = 0; temp<BUFFER_SIZE_HMC_; temp++)
	{
		if(Wire.available())
		buffer[temp] = Wire.read();
	}
	Wire.endTransmission();
	convert_data_compass();
}

void HMC5883L::convert_data_compass(void)
{
	compass_x = COMPASS_(buffer[0], buffer[1]);
	compass_y = COMPASS_(buffer[2], buffer[3]);
	compass_z = COMPASS_(buffer[4], buffer[5]);
}

int HMC5883L::get_compass_x(void)
{
	return compass_x;
}

int HMC5883L::get_compass_y(void)
{
	return compass_y;
}

int HMC5883L::get_compass_z(void)
{
	return compass_z;
}