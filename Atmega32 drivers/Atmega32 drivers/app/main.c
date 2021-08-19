/*
 * Atmega32 drivers.c
 *
 * Created: 8/18/2021 9:30:05 PM
 * Author : ehab &muhammed& mahmoud
 */ 

#include "includes.h"

int main(void)
{
	pinsDirection(&DDRC,0x84,OUTPUT);
	writePins(&PORTC,0x84,HIGH);
    /* Replace with your application code */
    while (1) 
    {

		
    }
}

