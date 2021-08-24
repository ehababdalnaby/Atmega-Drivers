/*
 * Atmega32 drivers.c
 *
 * Created: 8/18/2021 9:30:05 PM
 * Author : Ehab & Mohamed & Mahmoud Muhammed
 */ 

#include "includes.h"
#ifndef INCLUDES_H_
#error define includes.h file
#endif


int main(void)
{
	
	LCD_init();
	u16 a,b;
		while(1)
		{
			DHT_Represent(&a,&b);
			disp_intXY(1,1,a);
			disp_intXY(2,1,b);
			_delay_ms(2000);
		}
	 
}

