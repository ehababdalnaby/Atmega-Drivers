/*
 * GLCD.c
 *
 * Created: 8/28/2021 1:01:22 PM
 *  Author: ehab2_phjirwi
 */ 

#include "GLCD.h"




void GLCD_init(void)
{
	pinsDirection(&GLCD_DATA_DDR,0xFF,OUTPUT);
	pinsDirection(&GLCD_CTRL_DDR,CTRL_MASK,OUTPUT);
	GLCD_Send_CMD(DISPLAYON);
}
void GLCD_Send_CMD(u8 CMD)
{
	GLCD_DATA_PORT=CMD;
	writePin(RS,LOW);
	GLCD_Latch();
	_delay_us(1);
}
void GLCD_Send_data(u8 data)
{
	GLCD_DATA_PORT=data;
	writePin(RS,HIGH);
	GLCD_Latch();
	_delay_us(1);
}
void GLCD_Latch(void)
{
	writePin(EN,HIGH);
	_delay_ms(1);
	writePin(EN,LOW);
}
void GLCD_GOTOXY(u8 x,u8 y)
{
	
	if (y>64)
	{
		writePin(CS1,LOW);
		writePin(CS2,HIGH);
		y=y-64;
	}
	else
	{
		writePin(CS1,HIGH);
		writePin(CS2,LOW);
	}
	GLCD_Send_CMD(FIRSTLINE+(x-1));
	GLCD_Send_CMD(FIRSTADD+(y-1));
}
void GLCD_Disp_Char_XY(u8 x,u8 y,u8 data)
{
	GLCD_GOTOXY(x,y);
	GLCD_Send_data(data);
}