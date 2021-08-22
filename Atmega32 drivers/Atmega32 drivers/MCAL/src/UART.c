/*
 * UART.c
 *
 * Created: 8/21/2021 10:16:09 PM
 *  Author: ehab2_phjirwi
 */ 
#include "includes.h"
#define  F_CPU 8000000UL
void UART_INIT(u16 BaudRate)
{
	u16 BAUD_TEMP=0;
	BAUD_TEMP=((F_CPU/(16UL*BaudRate))-1);	
	UBRRH=(BAUD_TEMP>>8);
	UBRRL=BAUD_TEMP;
	SETBit(UCSRB,TXEN);
	SETBit(UCSRB,RXEN);
	UCSRC = (1 << URSEL) | (1 << UCSZ1) | (1 << UCSZ0);
}

void UART_TX(u8 data)
{
	UDR=data;
	while(GETBit(UCSRA,UDRE)!=1);	
		
}

u8 UART_RX(void)
{
	while(!GETBit(UCSRA,RXC));
	return UDR;	
}