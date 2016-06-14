

#ifndef ADXL345_h
#define ADXL345_h

#include "Arduino.h"

#define BUFFER_SIZE_ACC_	6

#define ADDRESS_ADXL35_ 0x53

#define POWER_CTL_REG	0x2D
#define DATAX0_REG		0x32

#define POWER_CTL_MEASURE	0x8

#define ACCELEROMETER_(x, y) (x)|((y)<<8)

class ADXL345
{
public:
	ADXL345();
	int get_address(void);
	void PowerOn(void);
	void read_accelerometer(void);
	int get_accelerometer_x(void);
	int get_accelerometer_y(void);
	int get_accelerometer_z(void);
	
private:
	int buffer[BUFFER_SIZE_ACC_];
	int accelerometer_x,accelerometer_y,accelerometer_z;
	
	void convert_data_accelerometer(void);
};
	
#endif
