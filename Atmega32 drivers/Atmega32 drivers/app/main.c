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
	u8 humidity_I = 0 , humidity_D = 0, temp_I = 0, temp_D = 0 , sumCheck = 0;
	LCD_init();
		while(1)
		{
			DHT_start();
			DHT_Response();
			//disp_charXY(2,10,'S');
			humidity_I=DHT_read();
			//disp_charXY(2,11,'H');
			humidity_D=DHT_read();
			//disp_charXY(2,12,'H');
			temp_I=DHT_read();
			//disp_charXY(2,13,'T');
			temp_D=DHT_read();
			//disp_charXY(2,14,'T');
			sumCheck=DHT_read();
			disp_intXY(1,1,humidity_I);
			disp_intXY(1,6,humidity_D);
			disp_intXY(1,10,temp_I);
			disp_intXY(2,1,temp_D);
			disp_intXY(2,6,sumCheck);
			_delay_ms(2000);
		}
	 
}

