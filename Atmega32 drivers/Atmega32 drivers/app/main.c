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
	pinDirection(PD5,OUTPUT);
	u32 angel=0;
	LCD_init();
	
	//Clock_APP();
	//GPS_APP();
	//GLCD_init();
	Timer1_Init(FPWM);
	ADC_init();
	while(1)
	{
		angel= read_analog(ADC0);
		angel=(angel*180)/1023UL;
		disp_strXY(1,1,"angel = ");
		disp_str("    ");
		disp_intXY(1,9,angel);
		servo_Angel(angel);
	}
	
// 	Timer0_Init(NORMAL);
// 	pinDirection(PD7,OUTPUT);
// 	writePin(PD7,LOW);
// 	LCD_init();
// 	ADC_init();
// 	
// 	//tempsensorAPP();
// 	u32 Pot_read=0;
// 	while(1)
// 	{
// 		GLCD_Disp_customsize(64,64,smile);
// 		_delay_ms(250);
// 		GLCD_Disp_customsize(64,64,wink);
// 		_delay_ms(250);
// 	}
}

