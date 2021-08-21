/*
 * Atmega32 drivers.c
 *
 * Created: 8/18/2021 9:30:05 PM
 * Author : Ehab & Mohamed & Mahmoud muhammed
 */ 

#include "includes.h"
#include <avr/interrupt.h>
#ifndef INCLUDES_H_
#error define includes.h file
#endif

int main(void)
{
	 //CLockAPP();
	//KeyPadAPP();
	ADC_init();
	LCD_init();
	while(1)
	{
		u16 aDCvalue=read_analog(ADC0);
		disp_strXY(1,1,(u8 *)"    ");
		disp_intXY(1,1,aDCvalue);
		u16 aDCvalue1=read_analog(ADC1);
		disp_strXY(2,1,(u8 *)"    ");
		disp_intXY(2,1,aDCvalue1);
		u16 aDCvalue2=read_analog(ADC2);
		disp_strXY(2,8,(u8 *)"    ");
		disp_intXY(2,8,aDCvalue2);
		_delay_ms(1000);
	}
	
}

