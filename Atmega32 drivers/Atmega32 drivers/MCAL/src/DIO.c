/*
 * DIO.c
 *
 * Created: 8/18/2021 11:18:29 PM
 *  Author: Mohamed
 */ 
#include "includes.h"

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

// u8 readPin(u8 pinNo){}
	
