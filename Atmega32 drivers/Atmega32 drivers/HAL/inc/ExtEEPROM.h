/*
 * ExtEEPROM.h
 *
 * Created: 8/22/2021 6:17:30 PM
 *  Author: Mohamed
 */ 


#ifndef EXTEEPROM_H_
#define EXTEEPROM_H_
#include "includes.h"
void writeEEPROM(u16 address,u8 data);
u8 readEEPROM(u16 address);
void writePageEEPROM(u16 address,u8* str);





#endif /* EXTEEPROM_H_ */