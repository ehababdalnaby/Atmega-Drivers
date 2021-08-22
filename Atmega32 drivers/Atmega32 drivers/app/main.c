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

// ISR(INT0_vect)
// {
// 	TGLBit(PORTC,2);
// }




int main(void)
{
	 //CLockAPP();
	 //KeyPadAPP();
	 //ADCAPP();
	//counterAPP();
	UART_INIT(9600);
	
	u8 x='a';
	
	while(1)
	{
		UART_TX(x+1);
		x= UART_RX();
		
	}

	 
	
}

