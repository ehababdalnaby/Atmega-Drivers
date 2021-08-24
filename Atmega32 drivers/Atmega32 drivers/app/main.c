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
	u8 hum[10],temp[10];
	BOOL checkSensor;
		while(1)
		{
			checkSensor=DHT_Represent(hum,temp);
			if(checkSensor==1)
			{
				disp_strXY(1,1,hum);
				disp_strXY(2,1,temp);
				disp_strXY(1,10,"bb");
				_delay_ms(2000);
			}
			else
			{
				disp_strXY(1,1,"7ambozo");
			}
	u8 temp[60];
	u8 hum[60];
		while(1)
		{
			disp_strXY(1,1,"Humid=     %RH");
			disp_strXY(2,1,"temp=      Deg.c");
			DHT_Represent(hum,temp);
			disp_strXY(1,7,hum);
			disp_strXY(2,6,temp);
			_delay_ms(500);
		}
	 
}

