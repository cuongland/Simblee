#ifndef HMC5883L_h
#define HMC5883L_h

#include "Arduino.h"

#define BUFFER_SIZE_HMC_		6
#define COMPASS_(x, y)			((x)<<8)|(y)

#define ADDRESS_HMC5883L_ 0x1E

#define CONDFIGURATION_REG_A	0X0
#define CONDFIGURATION_REG_B	0X1
#define MODE_REG_				0X2
#define DATAX_H_X_M_REG			0X3
#define DATAX_H_X_L_REG			0X4
#define DATAX_H_Y_M_REG			0X5
#define DATAX_H_Y_L_REG			0X6
#define DATAX_H_Z_M_REG			0X7
#define DATAX_H_Z_L_REG			0X8
#define STATUS_H_REG			0x9
#define IDENTIGICATION_H_A_REG	0XA
#define IDENTIGICATION_H_B_REG	0XB
#define IDENTIGICATION_H_C_REG	0XC

#define MA1						6
#define MA0						5
#define DO2						4
#define DO1						3
#define DO0						2
#define MS1						1
#define MS0						0
#define GN2						7
#define GN1						6
#define GN0						5
#define MD1						1
#define MD0						0
#define LOCK					1
#define RDY						0

class HMC5883L
{
public:
	HMC5883L();
	int get_address_HMC5883L(void);		
	void PowerOn_HMC5883(void);
	void read_compass(void);
	int get_compass_x(void);
	int get_compass_y(void);
	int get_compass_z(void);
	
private:	
	int buffer[BUFFER_SIZE_HMC_];
	int compass_x,compass_y,compass_z;
	void writeto_HMC5883L(int address_reg, int value);
	void convert_data_compass(void);
};

#endif