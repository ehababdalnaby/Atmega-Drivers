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

ISR(INT0_vect)
{
	TGLBit(PORTC,2);
}

int main(void)
{
	 //CLockAPP();
	//KeyPadAPP();
	 //ADCAPP();
	 counterAPP();
	 
	
}

