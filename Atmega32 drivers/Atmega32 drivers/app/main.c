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
	u8 Time = 0,i=0;
	
	
	while (1)
	{
		I2C_start();
		I2C_Write(0xD0,SCMTSLA_Ack_Code);
		I2C_Write(0x05,SCMTSLA_Ack_Code);
		I2C_Stop();
		I2C_start();
		I2C_Write(0xD1,SCMTSLA_Ack_Code);
		I2C_Read(&Time,ReceiveData_NAck_code);
		I2C_Stop();
		_delay_ms(1000);
		disp_intXY(1,1,Time);
	}
				
}

