/*
 * HDT.c
 *
 * Created: 8/24/2021 10:27:13 AM
 *  Author: Mahmoud-PC
 */ 
#include "ADC.h"

void DHT_start(void)
{
	pinDirection(DHT_BIT,OUTPUT);		
	writePin(DHT_BIT,LOW);				//apply 0 to start the sensor
	_delay_ms(1);						
	writePin(DHT_BIT,HIGH);				//apply 0 to start the sensor
	_delay_us(40);						//wait to ensure sensors response signals
}

s8 DHT_read(void)
{
	
}

