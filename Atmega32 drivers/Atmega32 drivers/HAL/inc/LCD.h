/*
 * LCD.h
 *
 * Created: 8/19/2021 5:30:31 PM
 *  Author: Mahmoud-PC
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "includes.h"
			/*	LCD PINS LOCATION	*/
#define data_pins (0xF0)
#define ctr_pin   (0x0E)
			/*	LCD PORTS	*/
#define data_port PORTA
#define ctr_port  PORTB
#define data_ddr  DDRA
#define ctr_ddr   DDRB
			/* LCD CONTROL PINS */
#define LCD_RS	  PB1
#define LCD_RW    PB2
#define LCD_E	  PB3
			/* COMMAND LIST */
#define CMD_CLR			0X01
#define CMD_RET			0X02
#define CMD_CUR_INC		0X06	/*CURSER DIRECTION LEFT TO RIGHT */ 
#define CMD_CUR_DEC		0X04	/*CURSER DIRECTION RIGHT TO LEFT */ 
#define CMD_CUR_SIT		0X0F	/* DISPLAY (ON) CURSER (ON  &  BLINKING)*/
#define CMD_SHIFT		0X10	/*SHIFTING IS DISABLED*/
#define CMD_FUN_SET		0X28	/*SET AS (4_BITS,2_LINES,5X8 CHARACTER) MODE*/
#define CGRAM_ADD		0X40	/*BASE ADDRESS OF CGRAM*/
#define DDRAM_ADD		0X80	/*BASE ADDRESS OF DDRAM*/



void LCD_init(void);
void LCD_SEND(u8 send);
void LCD_send_cmd(u8 command);
void LCD_send_data(u8 data);
void LCD_DISP_char(u8 character);
void LCD_latch(void);
void LCD_CLEAR (void);
<<<<<<< Updated upstream
void disp_char(u8 letter);
=======
void LCD_RETURN(void);
>>>>>>> Stashed changes
#endif /* LCD_H_ */