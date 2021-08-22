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
	SPI_Init(SPI_MASTER);
	LCD_init();
	u8 col=1;
	// writeEEPROM(0x00,'A');
	u8 name[]="ehab abdo mahmoud";
	writePageEEPROM(0x00,name);
	u8 data= 0;
	for (col=1;col<=16;col++)
	{
		disp_charXY(1,col,readEEPROM(0x00+col));
	}
	
// 		while(1)
// 		{
// 			
// 		
// 		}

	 
	
}

