/*
 * Timers.h
 *
 * Created: 8/21/2021 7:35:31 PM
 *  Author: Mohamed
 */ 

#ifndef TIMERS_H_
#define TIMERS_H_

#include "includes.h"
typedef enum{NORMAL,Phase_PWM,CTC,FPWM}timer_modes;
typedef enum{STOP,NO_PRESC,_8_PRESC,_16_PRESC,_64_PRESC,_256_PRESC,_1024_PRESC}Prescaler;	
/*this bits define the prescaler*/	
#define CS00 0
#define CS01 1
#define CS02 2	
/*this bits define compare output mode*/
#define COM00 4
#define COM01 5	

/*this bits define compare output mode*/
#define WGM00 6
#define WGM01 3
	

void Timer0_Init(timer_modes Tmode);
void Timer_start(void);
void set_dutycycle(u8 duty);


#endif




