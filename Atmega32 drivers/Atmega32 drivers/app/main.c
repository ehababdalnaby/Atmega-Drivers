/*
 * Atmega32 drivers.c
 *
 * Created: 8/18/2021 9:30:05 PM
 * Author : Ehab & Mohamed & Mahmoud
 */ 

#include "includes.h"
#include "LCD.h"

int main(void)
{
<<<<<<< Updated upstream
	LCD_init();	
=======
// 	pinsDirection(&DDRB,0x11,INPUT);
// 	pinsDirection(&DDRC,0x84,OUTPUT);
// 	writePins(&PORTC,0x84,LOW);
	LCD_init();
	LCD_DISP_char('a');
>>>>>>> Stashed changes
    /* Replace with your application code */
    while (1) 
    {
	disp_char('a');
	while(1);
    }
}

