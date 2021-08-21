/*
 * UART.c
 *
 * Created: 8/21/2021 10:16:09 PM
 *  Author: ehab2_phjirwi
 */ 
#include "includes.h"

void UART_INIT(u16 BaudRate)
{
	SETBit(UCSRB,TXEN);
	SETBit(UCSRB,RXEN);
	UCSRC = (1 << URSEL) | (1 << UCSZ1) | (1 << UCSZ0);
	u16 BAUD_TEMP=(F_CPU/(16*BaudRate))	-1;	
	UBRRL=BAUD_TEMP;
	UBRRH=(BAUD_TEMP>>8);
	

	
}

void UART_TX(u8 data)
{
	UDR=data;
	while(!GETBit(UCSRA,UDRE));		
}

u8 UART_RX(void)
{
	while(!GETBit(UCSRA,RXC));
	return UDR;	
}