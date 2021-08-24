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
	u8 bitLogic=0 ,i;
	pinDirection(DHT_BIT,INPUT);
	for (i=7;i>=0;i--)
	{				while (!readPin(DHT_BIT));		delay(30us);		if (PIND==0)		{			read_bit=0;		}		else		{			read_bit=1;		}		while(PIND);	}

}

