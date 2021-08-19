/*
 * Atmega32 drivers.c
 *
 * Created: 8/18/2021 9:30:05 PM
 * Author : ehab &muhammed& mahmoud
 */ 

#include "includes.h"

int main(void)
{
	pinsDirection(&DDRB,0x11,INPUT);
	pinsDirection(&DDRC,0x84,OUTPUT);
	writePins(&PORTC,0x84,LOW);
	
	
    /* Replace with your application code */
    while (1) 
    {
	writePins(&PORTC,0x84,LOW);
	if (readPin(PB0))
	{
		writePins(&PORTC,0x84,HIGH);
		while(readPin(PB0));
		
	}
    }
}

