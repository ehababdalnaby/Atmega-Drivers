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
	
	u8 Time[20];
	u8 Calen[20];
	I2C_Init();
	LCD_init();
	Write_RTC(0x00,0x00,0x00,Thr,0x20,0x05,0x95);
	while (1)
	{
		 Read_RTC(Time,Calen);
		disp_strXY(1,1,Time);
		disp_strXY(2,1,Calen);
		_delay_ms(500);
	}
				
}

