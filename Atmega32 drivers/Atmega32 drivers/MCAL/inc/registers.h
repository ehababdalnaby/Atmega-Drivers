/*
 * registers.h
 *
 * Created: 8/18/2021 10:14:58 PM
 *  Author: Mohamed
 */ 


#ifndef REGISTERS_H_
#define REGISTERS_H_

#include "includes.h"
/*A general function to provide the address*/
#define SELECTOR(ADDRESS) (*((volatile u8*)ADDRESS))
#define SELECTOR_16(ADDRESS) (*((volatile u16*)ADDRESS))
/*Port A Register*/ 

/*if the DDRx is set to be output and we write High to the PORTx 
* this will activate the internal Pull up resistor.
*/
#define PORTA  SELECTOR(0x3B)    //1->high output				0->low output  
#define DDRA   SELECTOR(0x3A)   //1->to make it output			0->to make it input    
#define PINA   SELECTOR(0x39)  //this register to read a value from a pin 

/*Port B Register*/
#define PORTB  SELECTOR(0x38)
#define DDRB  SELECTOR(0x37)
#define PINB  SELECTOR(0x36)

/*Port C Register*/
#define PORTC  SELECTOR(0x35)
#define DDRC   SELECTOR(0x34)
#define PINC  SELECTOR(0x33)

/*Port D Register*/
#define PORTD  SELECTOR(0x32)
#define DDRD   SELECTOR(0x31)
#define PIND  SELECTOR(0x30)

/*ADC registers*/

#define ADMUX	 SELECTOR(0x27)
#define ADCSRA	 SELECTOR(0x26)

#define ADCH	 SELECTOR(0x25)
#define ADCL	 SELECTOR(0x24)
#define ADC		 SELECTOR_16(0x24)
/*EXTERNAL INTERRUPT REGESTERS*/

#define MCUCR  SELECTOR(0X55)
#define MCUCSR SELECTOR(0X54)
#define GICR   SELECTOR(0X5B)
#define	GIFR   SELECTOR(0X5A)
#define SREG   SELECTOR(0x5F)



#endif /* REGISTERS_H_ */