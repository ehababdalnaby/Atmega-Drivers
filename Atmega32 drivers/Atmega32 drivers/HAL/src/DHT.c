/*
 * HDT.c
 *
 * Created: 8/24/2021 10:27:13 AM
 *  Author: Mahmoud-PC
 */ 
#include "DHT.h"

void DHT_start(void)
{
	pinDirection(DHT_PIN,OUTPUT);		
	writePin(DHT_PIN,LOW);				//apply 0 to start the sensor
	_delay_ms(1);						
	writePin(DHT_PIN,HIGH);				//apply 0 to start the sensor
	_delay_us(40);						//wait to ensure sensors response signals
}

s8 DHT_read(void)
{
	u8 bitLogic=0 ,i;
	pinDirection(DHT_PIN,INPUT);
	for (i=7;i>=0;i--)
	{

}
