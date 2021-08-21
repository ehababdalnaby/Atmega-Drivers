/*
 * UART.c
 *
 * Created: 8/21/2021 10:16:09 PM
 *  Author: ehab2_phjirwi
 */ 
#include "UART.h"




void UART_INIT(u16 BaudRate)
{
	u16 BAUD_TEMP=(F_CPU/(16*BaudRate))	-1;	
	UBRRL=BAUD_TEMP;
	UBRRH=(BAUD_TEMP>>8);
	
}

void UART_TX(u8 data)
{
	SETBit(UCSRB,TXEN);
	UDR=data;
	while(!GETBit(UCSRA,UDRE));		
}

u8 UART_RX(void)
{
	SETBit(UCSRB,RXEN);
	while(!GETBit(UCSRA,RXC));
	return UDR;	
}