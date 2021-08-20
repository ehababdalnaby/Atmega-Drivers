/*
 * APPS.c
 *
 * Created: 8/20/2021 6:36:16 PM
 *  Author: ehab2_phjirwi
 */ 
#include "APPS.h"


void counterAPP(void)
{
	LCD_init();
	
	/* Replace with your application code */
	pinDirection(PB0,INPUT);
	
	u32 count=0,i=0;
	u32 delay =1000,row=1;
	disp_strXY(1,1,(u8 *)"counter = ");
	//disp_intXY(2,3,2021);
	while (1)
	{
		delay =1000;
		if (readPin(PB0))
		{
			row++;
			delay=delay/(row*0.5);
			if (delay<100)
			{
				delay=100;
			}
			disp_strXY(1,11,(u8 *)"    ");
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
			disp_strXY(1,11,(u8 *)"    ");
			disp_intXY(1,11,count++);
			for (i=0;i<=delay;i++)
			{
				_delay_ms(1);
			}
			
		}
	
	}
}



void KeyPadAPP(void)
{
	LCD_init();
	KEYPAD_Init();
	disp_charXY(1,1,'x');
	u8 key=0;
	while(1)
	{
		key=GetKey();
		if (key!=0)
		{
			disp_charXY(1,1,key);
			key=0;
		}	
	}
}