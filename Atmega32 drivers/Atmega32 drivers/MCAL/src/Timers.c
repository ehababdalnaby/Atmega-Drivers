/*
 * Timers.c
 *
 * Created: 8/21/2021 7:35:54 PM
 *  Author: Mohamed
 */

 
#include "Timers.h"
#include <avr/interrupt.h>
#include "DIO.h"
volatile static  u32 overflow=0;


ISR(TIMER0_OVF_vect)
{
	overflow++;	
}






void Timer0_Init(timer_modes Tmode)
{
	switch(Tmode)
	{
		case NORMAL:
		CLRBit(TCCR0,WGM01);
		CLRBit(TCCR0,WGM00);
		
		CLRBit(TCCR0,CS00);
		SETBit(TCCR0,CS01);
		CLRBit(TCCR0,CS02);
		
		SETBit(TIMSK,TOIE0);
		sei();
		break;
		case CTC:
		
		break;	
		case FPWM:
		SETBit(TCCR0,WGM01);
		SETBit(TCCR0,WGM00);
		
		SETBit(TCCR0,COM01);
		CLRBit(TCCR0,COM00);
		
		SETBit(TCCR0,CS00);
		CLRBit(TCCR0,CS01);
		SETBit(TCCR0,CS02);
		break;
	}
}
void Timer_start(void)
{
	
}

void ResetTimer(void)
{
	TCNT0=0x00;
	overflow=0;
}
void timer_delay_us(u32 delay)
{
	ResetTimer();
	while(delay > ((TCNT0+1+overflow*256UL)/2UL));	
}
void set_dutycycle(u8 duty)
{
	OCR0=(duty*255UL)/100;
}

