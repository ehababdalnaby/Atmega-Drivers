/*
 * KEYPAD.c
 *
 * Created: 8/20/2021 6:03:58 PM
 *  Author: ehab2_phjirwi
 */ 
#include "KEYPAD.h"



u8 key_CHAR[4][4]=
{
	{'7','8','9','/'},
	{'4','5','6','*'},
	{'1','2','3','-'},
	{'=','0','.','+'}		
};


void KEYPAD_Init(void)
{
	pinsDirection(&ROW_DDR,ROW_PINS,OUTPUT);
	writePins(&ROW_PORT,ROW_PINS,HIGH);	
	pinsDirection(&COL_DDR,COL_PINS,INPUT);
	writePins(&COL_PORT,COL_PINS,HIGH);
	
}



u8 GetKey(void)
{
	u8 key1=0;
	u8 row=0,col=0;
	
	for (row=PD4;row<=PD7;row++)
	{
		writePin(row,LOW);
		for (col=PC3;col<=PC6;col++)
		{
			if (!readPin(col))
			{
				while(!readPin(col));
				key1=key_CHAR[row-28][col-19];
				return key1;
			}	
		}
		_delay_ms(10);
		writePin(row,HIGH);
	}	
	return key1;
}