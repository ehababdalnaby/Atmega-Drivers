/*
 * KEYPAD.h
 *
 * Created: 8/20/2021 6:03:43 PM
 *  Author: ehab2_phjirwi
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_
#include "includes.h"


#define ROW_PINS	0xF0
#define COL_PINS	0x78
#define COL_PORT	PORTC
#define ROW_PORT	PORTD

#define COL_DDR		DDRC
#define ROW_DDR     DDRD

#define COLPINREG   PINC


void KEYPAD_Init(void);
u8 GetKey(void);






#endif /* KEYPAD_H_ */