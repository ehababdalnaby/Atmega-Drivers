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

LCD_init();
UART_INIT(9600);
void GPS_Read(void){
	pinDirection(PD0,INPUT);
	u8 i=0;
	u8 longitude[10], latitude[10], gpsTime[10], altidude[10], buffer[100], temp;
	u8 gpgga[]="$GPGGA",gpggaTemp[7];
	temp=UART_RX();

		while(temp != '\n');
		while(temp!=',')
		{
			gpggaTemp[i]=temp;
			i++;
		}
		i=0;
		if((strcmp(gpgga,gpggaTemp))==0){
			while(temp != '\n')
			{
				buffer[i]=temp;
				i++;
			}
		}
	disp_strXY(1,1,buffer);
	
	
}
int main(void)
{
	_delay_ms(12000);
	while(1){
	
   GPS_Read();	
	
	
	}
		
}

