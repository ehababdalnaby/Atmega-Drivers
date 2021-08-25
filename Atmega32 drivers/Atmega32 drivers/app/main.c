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
	u8 value,i,lati_value[20]={0},lati_dir, longi_value[20]={0}, longi_dir, alti[5],time[20] ;
	LCD_init();
	UART_INIT(9600);
	disp_strXY(1,5,"LOADING");
	disp_strXY(2,1,"<<");
	disp_strXY(2,15,">>");
	for (i=3;i<15;i++)
	{
		disp_charXY(2,i,'-');
		_delay_ms(900);
	}
	LCD_CLEAR();
	
	while(1)
	{
		
		 GPS_READing(lati_value,&lati_dir,longi_value,&longi_dir,alti,time);
	}//while
}

