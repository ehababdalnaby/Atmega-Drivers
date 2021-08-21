/*
 * ADC.h
 *
 * Created: 8/21/2021 11:01:05 AM
 *  Author: ehab2_phjirwi
 */ 


#ifndef ADC_H_
#define ADC_H_
#include "includes.h"

enum {ADC0,ADC1,ADC2,ADC3,ADC4,ADC5,ADC6,ADC7}ADC_SELECT;
enum {AREF,AVCC,Internal_2=3}voltageRef;
enum{DIV_2=1,DIV_4,DIV_8,DIV_16,DIV_32,DIV_64,DIV_128}prescaler;	
#define ADLAR 0     //0 for right adjustment   1  for left adjustment	

//#define MUXSELCREG  ADMUX|(AVCC<<6)|(ADLAR<<5)

#define ADEN  1
#define ADATE 0
#define ADIE  0
#define SELEPRESC  DIV_128

void ADC_init(void);
u16 read_analog(u16 ADC_NUM);

#endif /* ADC_H_ */