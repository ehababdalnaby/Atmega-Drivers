/*
 * DIO.c
 *
 * Created: 8/18/2021 11:18:29 PM
 *  Author: Mohamed
 */ 
#include "includes.h"

/*for single bit*/
void writePin(u8 pinNo,u8 logic){
	if((pinNo>=PA0)&&(pinNo<=PA7)){
		if(logic==HIGH)
			SETBit(PORTA,pinNo);
		else if(logic==LOW)
			CLRBit(PORTA,pinNo);
		else{}
}

	else if((pinNo>=PB0)&&(pinNo<=PB7)){
		if(logic==HIGH)
			SETBit(PORTB,(pinNo-8));
		else if(logic==LOW)
			CLRBit(PORTB,(pinNo-8));
		else{}
	}
	
	else if((pinNo>=PC0)&&(pinNo<=PC7)){
		if(logic==HIGH)
			SETBit(PORTC,(pinNo-16));
		else if(logic==LOW)
			CLRBit(PORTC,(pinNo-16));
		else{}
	}
	
	else if((pinNo>=PD0)&&(pinNo<=PD7)){
		if(logic==HIGH)
			SETBit(PORTD,(pinNo-24));
		else if(logic==LOW)
			CLRBit(PORTD,(pinNo-24));
		else{}
	}
	else{}
}
void pinDirection(u8 pinNo, u8 direction){
	if((pinNo >= PA0) && (pinNo <= PA7)){
		if(direction == OUTPUT)
			SETBit(DDRA,pinNo);
		else if(direction == INPUT)
			CLRBit(DDRA,pinNo);
		else{}
	}
	else if((pinNo >= PB0) && (pinNo <= PB7)){
		if(direction == OUTPUT)
			SETBit(DDRB,(pinNo-8));
		else if(direction == LOW)
			CLRBit(DDRB,(pinNo-8));
		else{}
	}
	else if((pinNo >= PC0) && (pinNo <= PC7)){
		if(direction == OUTPUT)
			SETBit(DDRC,(pinNo-16));
		else if(direction==INPUT)
			CLRBit(DDRC,(pinNo-16));
		else{}
	}
	else if((pinNo >= PD0) && (pinNo <= PD7)){
		if(direction == OUTPUT)
			SETBit(DDRD,(pinNo-24));
		else if(direction == INPUT)
			CLRBit(DDRD,(pinNo-24));
		else{}
	}
	else{}
}

u8 readPin(u8 pinNo){
	u8 result=0;
	if((pinNo>=PA0)&&(pinNo<=PA7))
		result=GETBit(PINA,pinNo);
	else if((pinNo>=PB0)&&(pinNo<=PB7))
		result=GETBit(PINB,pinNo-8);
	else if((pinNo>=PC0)&&(pinNo<=PC7))
		result=GETBit(PINC,pinNo-16);
	else if((pinNo>=PD0)&&(pinNo<=PD7))
		result=GETBit(PIND,pinNo-24);
	else{}
	return result;
}
	
/*for custom number of bits*/
void writePins(volatile u8* port, u8 mask, u8 logic){
	if(logic==HIGH)
		SETBits(*port,mask);
	else if(logic==LOW)
		CLRBits(*port,mask);
	else{}
}
void pinsDirection(volatile u8* ddr, u8 mask, u8 direction){
	if(direction == OUTPUT)
		SETBits(*ddr,mask);
	else if(direction == INPUT)
		CLRBits(*ddr,mask);
	else{}
}

/*for all bits*/
void writeAllPin(volatile u8* port,u8 logic){
	if(logic==HIGH)
		SETALLBits(*port);
	else if(logic==LOW)
		CLRALLBits(*port);
	else{}
}
void allPinsDirection(volatile u8* ddr, u8 direction){
	if(direction == OUTPUT)
		SETALLBits(*ddr);
	else if(direction == INPUT)
		CLRALLBits(*ddr);
	else{}	
}
