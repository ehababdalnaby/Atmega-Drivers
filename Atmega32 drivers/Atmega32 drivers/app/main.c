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
	u8 Time = 0;
	I2C_start();
	I2C_Write(0xD3,SCMTSLA_Ack_Code);
	while (1)
	{
		_delay_ms(1000);
		I2C_Read(&Time,ReceiveData_Ack_code);
		disp_charXY(1,3,'p');
		disp_intXY(1,1,Time);
	}
	
	
	
}

