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
    CLR_EEPROM();
	u8 name[]="NTI Group -- External EEPROM Task With Automated Filling -- Thank you Dr mahmoud for you efforts ";
	write_EEPROM_auto(name);
	u8 name_modified[16];
	u8 i=0;
	u8 up,down;
	while(1)
	{
		i=0;
		while((i+31)!=autoAddress)
		{
			up=i;
			down=i+16;
			ReadEEPROMSTR(up++,16,name_modified);
			disp_strXY(1,1,name_modified);
			ReadEEPROMSTR(down++,16,name_modified);
			disp_strXY(2,1,name_modified);
			_delay_ms(200);
			i++;i++;
		}
	}
			
// 		while(1)
// 		{
// 			
// 		
// 		}

	 
	
}

