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

extern u8 gps[100];
void GPS_Read(void){
	u8 i=0;
	u8 longitude[10], latitude[10], gpsTime[10], altidude[10], buffer[100], temp;
	u8 gpgga[]="$GPGGA",gpggaTemp[7];
	temp=UART_RX();

	while(temp != '\n')
	//while(temp!=',')
	{
		gpggaTemp[i]=temp;
		i++;
	}
	// 		i=0;
	// 		if((strcmp(gpgga,gpggaTemp))==0){
	// 			while(temp != '\n')
	// 			{
	// 				buffer[i]=temp;
	// 				i++;
	// 			}
	// 		}
	disp_strXY(1,1,buffer);
	
	
}

int main(void)
{
	// 	u8 gps[100];
	// 	u8 i=0;
	// 	u8 CHECK[]="GPGGA";
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
				
				disp_strXY(1,1,lati_value);
				disp_char(lati_dir);
				
				
				disp_strXY(2,1,longi_value);
				disp_char(longi_dir);
				
				_delay_ms(1000);
			
		}//if
	}//while
}

