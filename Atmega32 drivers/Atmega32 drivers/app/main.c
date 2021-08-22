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
	 // 	UART_INIT(9600);
	SPI_Init(SPI_MASTER);
 	LCD_init();
	u8 col=1;
	u8 h7mbozo='a';
	u8 receive;
	
	disp_charXY(1,col,h7mbozo);
	while(1)
	{	disp_charXY(1,col,h7mbozo);

	 //	UART_TX(x+1);
	// 	x= UART_RX();
		receive=SPI_Transceive(h7mbozo);
		_delay_ms(1000);
 	
		 if(receive!=0xff)
 		disp_charXY(2,col,receive);
		 h7mbozo++;
		 col++;
	}

	 
	
}

