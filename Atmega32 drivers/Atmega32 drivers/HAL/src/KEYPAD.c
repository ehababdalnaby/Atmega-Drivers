/*
 * KEYPAD.c
 *
 * Created: 8/20/2021 6:03:58 PM
 *  Author: ehab2_phjirwi
 */ 
#include "KEYPAD.h"



u8 keys[][4]=
{
	{'7','8','9','/'},
	{'4','5','6','*'},
	{'1','2','3','-'},
	{'=','0','.','+'}		
};


void KEYPAD_Init(void)
{
	pinsDirection(&ROW_DDR,ROW_PINS,OUTPUT);
	pinsDirection(&COL_DDR,COL_PINS,INPUT);
	writePins(&COL_PORT,COL_PINS,HIGH);
}



u8 GetKey(void)
{
	u8 key=0;
	u8 row=0,col=0;
	writePins(&ROW_PORT,ROW_PINS,HIGH);	
	for (row=PD4;row<=PD7;row++)
	{
		writePin(row,LOW);
		for (col=PC3;col<=PC6;col++)
		{
			if (!readPin(col))
			{
				key=keys[row-4][col-3];
			}	
		}
		writePin(row,HIGH);
	}	
	return key;
}