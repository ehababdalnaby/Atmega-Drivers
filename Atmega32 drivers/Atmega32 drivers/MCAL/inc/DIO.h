/*
 * DIO.h
 *
 * Created: 8/18/2021 11:18:14 PM
 *  Author: Mohamed
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "includes.h"

#define porta_offset  0
#define portb_offset  8
#define portc_offset  16
#define portd_offset  24

typedef enum{PA0=porta_offset,PA1,PA2,PA3,PA4,PA5,PA6,PA7}PortA;
typedef enum{PB0=portb_offset,PB1,PB2,PB3,PB4,PB5,PB6,PB7}PortB;
typedef enum{PC0=portc_offset,PC1,PC2,PC3,PC4,PC5,PC6,PC7}PortC;
typedef enum{PD0=portd_offset,PD1,PD2,PD3,PD4,PD5,PD6,PD7}PortD;
	
	
typedef enum{LOW,HIGH}LOGIC;
typedef enum{INPUT,OUTPUT}DIRECTION;

	
/*for single bit in the port*/
void writePin(u8 pinNo, u8 logic);
void pinDirection(u8 pinNo, u8 direction);
BOOL readPin(u8 pinNo);

/*for custom number of bits*/
void writePins(volatile u8* port,u8 mask, u8 logic);
void pinsDirection(volatile u8* ddr,u8 mask, u8 direction);
/*for all bits in the port*/
void writeAllPin(volatile u8* port,u8 logic);
void allPinsDirection(volatile u8* ddr, u8 direction);

	
#endif /* DIO_H_ */