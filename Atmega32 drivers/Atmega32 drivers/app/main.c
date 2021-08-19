/*
 * Atmega32 drivers.c
 *
 * Created: 8/18/2021 9:30:05 PM
 * Author : Ehab & Mohamed & Mahmoud muhammed
 */ 

#include "includes.h"
#include "LCD.h"

int main(void)
{
	LCD_init();	
    /* Replace with your application code */
    while (1) 
    {
	disp_char('a');
	_delay_ms(100);
    }
}

