/*
 * EXT_INT.c
 *
 * Created: 8/21/2021 6:01:45 PM
 *  Author: ehab2_phjirwi
 */ 
#include "EXT_INT.h"

void INT_init(u8 int_num , u8 sense_control)
{
	GICR|=(1<<int_num);
	if(int_num == INT_2)
	{
		MCUCSR|=((sense_control & 0x01)<<6);
	}
	else
	MCUCR|=(sense_control<<(int_num*2));
}

void GLOBAL_INT_EN(void)
{
	writePins( &SREG,0x80,HIGH );
}

void GLOBAL_INT_DE(void)
{
	writePins( &SREG,0x80,LOW );
}
