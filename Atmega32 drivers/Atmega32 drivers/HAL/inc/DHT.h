/*
 * HDT.h
 *
 * Created: 8/24/2021 10:25:37 AM
 *  Author: Mahmoud-PC
 */ 



#ifndef DHT_H_
#define DHT_H_

#include "includes.h"


#define DHT_BIT		PD7
#define DHT_PORT	PORTD
#define DHT_DDR		DDRD
#define DHT_PIN		PIND

void DHT_start(void);
s8 DHT_read(void);



#endif /* HDT_H_ */