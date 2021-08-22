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

	while(1)
	{
		u8 data='A';
		u8 receive;
		u8 col=1;
	// 	UART_TX(x+1);
	// 	x= UART_RX();
		receive=SPI_Transceive(data);
		_delay_ms(1000);
		disp_charXY(1,col,data);
		disp_charXY(2,col,receive);
		data++;
		col++;
	}

	 
	
}

