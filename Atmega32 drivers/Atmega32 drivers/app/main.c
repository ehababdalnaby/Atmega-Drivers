/*
* Atmega32 drivers.c
*
* Created: 8/18/2021 9:30:05 PM
* Author : Ehab & Mohamed & Mahmoud Muhammed
*/

#include "includes.h"
#include "GPS.h"


#ifndef INCLUDES_H_
#error define includes.h file
#endif

extern volatile u32 overflow;



#include "NTI.h"
#include "I2C EEPROM.h"

int main(void)
{
	u16 counter=0;
// 	for (counter=0;counter<1024;counter++)
// 	{
// 		I2C_EEPROM_Write(counter,NTI[counter]);
// 	}
	_delay_ms(10);
	u8 imageRecieve;
GLCD_init();

	for (counter=0;counter<1024;counter++)
	{
		I2C_EEPROM_Read(counter,&imageRecieve);
		_delay_ms(1);
		GLCD_Disp_image(imageRecieve);
 	}
	u8 i=0,j=0;
	counter=0;
	for (i=0;i<8;i++)
	{
		for (j=0;j<128;j++)
		{
			
			I2C_EEPROM_Read(counter,&imageRecieve);
			_delay_ms(10);
			GLCD_Disp_Char_XY(i+1,j+1,imageRecieve);
			counter++;
		}
	}
while(1);

		

}

