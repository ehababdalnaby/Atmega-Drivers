/*
 * Timers.c
 *
 * Created: 8/21/2021 7:35:54 PM
 *  Author: Mohamed
 */

 
#include "Timers.h"


void Timer0_Init(timer_modes Tmode)
{
// 	switch(Tmode)
// 	{
// 		case FPWM:
		SETBit(TCCR0,WGM01);
		SETBit(TCCR0,WGM00);
		
		SETBit(TCCR0,COM01);
		CLRBit(TCCR0,COM00);
		
		
		CLRBit(TCCR0,CS00);
		SETBit(TCCR0,CS01);
		SETBit(TCCR0,CS02);

		//TCCR0|=_1024_PRESC|(1<<WGM01)|(1<<WGM00)|(1<<COM01);
		
// 		break;
// 	}
}
void Timer_start(void)
{
	
}
void set_dutycycle(u8 duty)
{
	OCR0=(duty*255UL)/100;
}