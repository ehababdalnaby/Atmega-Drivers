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
extern u16 autoAddress ;



int main(void)
{
	SPI_Init(SPI_MASTER);
	LCD_init();
    //((sizeof(name)/32)+1)	// writeEEPROM(0x00,'A');
	u8 name[]="7MBOZO TEAM WORK : SA2ET & LA7EQ & M7MA MA7Rooooooo3";
	write_EEPROM_auto(name);
	u8 name_modified[16];
	u8 i=0;
	
	u8 name2[]="ANY BAZENJAN";
	writePageEEPROM(autoAddress,name2);
	u8 up,down;
	for(i=0;i<2;i++)
{
	up=((i*32));
	down=((i*32)+16);
	ReadEEPROMSTR(up++,16,name_modified);
	disp_strXY(1,1,name_modified);
	ReadEEPROMSTR(down++,16,name_modified);
	disp_strXY(2,1,name_modified);
	_delay_ms(1000);
}
		
			
// 		while(1)
// 		{
// 			
// 		
// 		}

	 
	
}

