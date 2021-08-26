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


int main(void)
{
	I2C_Init();
	LCD_init();
	u8 data1[15]="NTI Group";
	u8 data='x';
	
	 I2C_EEPROM_Write(0x00,'E');
	 I2C_EEPROM_Write(0x01,'a');
	 I2C_EEPROM_Write(0x02,'f');	
	 I2C_EEPROM_Page_Write(0x00,data1);
	 I2C_EEPROM_Read(0x02,&data);
	 disp_charXY(1,1,data);
}

