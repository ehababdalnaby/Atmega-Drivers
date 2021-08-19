/*
 * LCD.c
 *
 * Created: 8/19/2021 5:29:51 PM
 *  Author: Mahmoud-PC
 */ 

#include "includes.h"


void LCD_init(void)
{
	pinsDirection(&data_ddr, data_pins, OUTPUT);
	pinsDirection(&ctr_ddr, ctr_pin, OUTPUT);
	writePin(LCD_RW , LOW);
	LCD_CLEAR();
	LCD_send_cmd(CMD_RET);
	LCD_send_cmd(CMD_CUR_INC);
	LCD_send_cmd(CMD_CUR_SIT);
	LCD_send_cmd(CMD_SHIFT);
	LCD_send_cmd(CMD_FUN_SET);
}

void LCD_CLEAR(void)
{
	LCD_send_cmd(CMD_CLR);
	_delay_ms(2);
}


void LCD_send_cmd(u8 command)
{
	writePin(LCD_RS,LOW);
	writePins(&PORTA,data_pins,LOW);
	writePins(&PORTA,command,HIGH);	
	LCD_latch();
	writePins(&PORTA,data_pins,LOW);
	writePins(&PORTA,(command<<4),HIGH);
	LCD_latch();
	_delay_us(40);
}

void LCD_send_data(u8 data)
{
	writePin(LCD_RS,HIGH);
	writePins(&PORTA,data_pins,LOW);
	writePins(&PORTA,data,HIGH);
	LCD_latch();
	writePins(&PORTA,data_pins,LOW);
	writePins(&PORTA,(data<<4),HIGH);
	LCD_latch();
	_delay_us(40);
}

void LCD_latch(void)
{
	writePin(LCD_E,HIGH);
	_delay_us(40);
	writePin(LCD_E,LOW);
	_delay_us(40);
}