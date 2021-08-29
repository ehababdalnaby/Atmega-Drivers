/*
* Atmega32 drivers.c
*
* Created: 8/18/2021 9:30:05 PM
* Author : Ehab & Mohamed & Mahmoud Muhammed
*/

#include "includes.h"
#include "GPS.h"


#ifndef INCLUDES_H_
#error define includes.h file
#endif

extern volatile u32 overflow;



#include "smile.h"
#include "wink.h"


void servo_rotate(u32 angel)
{
	angel= 1000+(1000UL*angel/180UL);
	writePin(PD7,HIGH);
	timer_delay_us(angel);
	writePin(PD7,LOW);
	timer_delay_us(20000-angel);
}
int main(void)
{	
	Clock_APP();
	//GPS_APP();
	//GLCD_init();
}

