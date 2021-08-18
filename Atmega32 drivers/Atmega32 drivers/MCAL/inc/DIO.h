/*
 * DIO.h
 *
 * Created: 8/18/2021 11:18:14 PM
 *  Author: Mohamed
 */ 


#ifndef DIO_H_
#define DIO_H_
#include "includes.h"

typedef enum{PA0,PA1,PA2,PA3,PA4,PA5,PA6,PA7}PortA;
typedef enum{PB0,PB1,PB2,PB3,PB4,PB5,PB6,PB7}PortB;
typedef enum{PC0,PC1,PC2,PC3,PC4,PC5,PC6,PC7}PortC;
typedef enum{PD0,PD1,PD2,PD3,PD4,PD5,PD6,PD7}PortD;
typedef enum{LOW,HIGH}LOGIC;
typedef enum{INPUT,OUTPUT}DIRECTION;
	
void writePin(u8 pinNo, u8 logic);
void pinDirection(u8 pinNo, u8 direction);
u8 readPin(u8 pinNo);

	




#endif /* DIO_H_ */