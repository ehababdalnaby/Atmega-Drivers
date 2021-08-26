/*
 * I2C.c
 *
 * Created: 8/25/2021 5:55:26 PM
 *  Author: Mahmoud-PC
 */ 
#include "I2C.h"

void I2C_Init(void)
{				
	TWBR=32;				//set clk prescaler
	SETBit(TWCR,TWEN);		//TWI enable 
}

BOOL I2C_start(void)
{
	
}

BOOL I2C_Check_status(u8 status_code)
{
	
}
