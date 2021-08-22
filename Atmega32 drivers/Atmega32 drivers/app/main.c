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
	write_EEPROM_auto("mahmoud el sayed gadallah darwish abdelhamid es7ak ya3koub");
	u8 name_modified[16];
	ReadEEPROMSTR(0x05,4,name_modified);
	disp_strXY(1,1,name_modified);
	
// 		while(1)
// 		{
// 			
// 		
// 		}

	 
	
}

