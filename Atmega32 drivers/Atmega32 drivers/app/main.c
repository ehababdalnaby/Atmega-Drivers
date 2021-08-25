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
	unsigned char value,i,lati_value[15],lati_dir, longi_value[15], longi_dir, alti[5],time[15] ;
	LCD_init();
	UART_INIT(9600);
	while(1)
	{
		if(UART_RX()=='$' && UART_RX()=='G'&&UART_RX()=='P'&&UART_RX()=='G'&&UART_RX()=='G'&&UART_RX()=='A')
		{
				UART_RX();
				//time
				time[0]=UART_RX();
				value=time[0];
				for(i=1;value!=',';i++)
				{
					time[i]=UART_RX();
					value=time[i];
				}
				time[i-1]=' ';
				//latitude
				lati_value[0]=UART_RX();
				value=lati_value[0];
				for(i=1;value!=',';i++)
				{
					lati_value[i]=UART_RX();
					value=lati_value[i];
				}
				lati_value[i-1]=' ';
				lati_dir=UART_RX();
				value=UART_RX();//remove next comma (,)
				//longitude
				longi_value[0]=UART_RX();
				value=longi_value[0];
				for(i=1;value!=',';i++)
				{
					longi_value[i]=UART_RX();
					value=longi_value[i];
				}
				longi_value[i-1]=' ';
				longi_dir=UART_RX();
				
				//disp_strXY(1,1,time);
				strfToint(lati_value);
				disp_strXY(1,1,lati_value);
				disp_char(lati_dir);
				
				strfToint(longi_value);
				disp_strXY(2,1,longi_value);
				disp_char(longi_dir);
				
				_delay_ms(1000);
			
		}//if
	}//while
}

