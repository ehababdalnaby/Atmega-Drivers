/*
 * ExtEEPROM.h
 *
 * Created: 8/22/2021 6:17:30 PM
 *  Author: Mohamed
 */ 


#ifndef EXTEEPROM_H_
#define EXTEEPROM_H_

 
#include "includes.h"
 #define EROM_COM_WRITE			0x02
 #define EROM_COM_READ			0x03 

void writeEEPROM(u16 location,u8 data);
u8 readEEPROM(u16 location);
//void writePageEEPROM(u16 address,u8* str);


 


#endif /* EXTEEPROM_H_ */