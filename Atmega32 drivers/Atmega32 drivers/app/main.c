/*
 * Atmega32 drivers.c
 *
 * Created: 8/18/2021 9:30:05 PM
 * Author : Ehab & Mohamed & Mahmoud muhammed
 */ 

#include "includes.h"
#include "LCD.h"
#include <math.h>
void main(void)
{
	LCD_init();	
	
    /* Replace with your application code */
	 pinDirection(PB4,INPUT);
	 
	u32 count=0,i=0;
	u32 delay =1000,row=1;
	disp_strXY(1,1,"counter = ");
	//disp_intXY(2,3,2021);
    while (1) 
    {
		delay =1000;
		if (readPin(PB4))
		{
			row++;
			delay=delay/(row*0.2);
			if (delay<20)
			{
				delay=20;
			}
			disp_strXY(1,11,"    ");
			disp_intXY(1,11,count++);
			for (i=0;i<=delay;i++)
			{
				_delay_ms(1);
			}
			
		}
		else
		{
			row=1;
			delay =1000;
			disp_strXY(1,11,"    ");
			disp_intXY(1,11,count++);
			for (i=0;i<=delay;i++)
			{
				_delay_ms(1);
			}
			
		}
		
	
	
    }
}

