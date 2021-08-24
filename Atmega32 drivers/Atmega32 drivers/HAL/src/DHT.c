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
	_delay_ms(20);						
	writePin(DHT_PIN,HIGH);				//apply 0 to start the sensor
}

u8 DHT_read(void)
{
	u8 bitLogic=0 ,i=0;
	for (i=0;i<8;i++)
	{		while (readPin(DHT_PIN)==0);		_delay_us(30);		if (readPin(DHT_PIN)==0)		{			bitLogic=bitLogic<<1;		}		else		{			bitLogic=((bitLogic<<1)|0x01);		}				while(readPin(DHT_PIN));			}
	return bitLogic;
}

void DHT_Response(void)
{
	pinDirection(DHT_PIN,INPUT);
	while(readPin(DHT_PIN));
	while(!readPin(DHT_PIN));
	while(readPin(DHT_PIN));
}

BOOL DHT_Represent(u8* hum,u8* temp)
{
	u16 temp_1=0,hum_1=0;
	float temp_2=0,hum_2=0;
	u8 humidity_I = 0 , humidity_D = 0, temp_I = 0, temp_D = 0 , sumCheck = 0;
	DHT_start();
	DHT_Response();
	humidity_I=DHT_read();
	humidity_D=DHT_read();
	temp_I=DHT_read();
	temp_D=DHT_read();
	sumCheck=DHT_read();
	if( (humidity_I+humidity_D+temp_I+temp_D) == sumCheck )
	{
		hum_1=((humidity_I<<8)|humidity_D);
		temp_1=((temp_I<<8)|temp_D);
// 		*hum=((float)(hum_1)/10);
// 		*temp=((float)(temp_1)/10);
		sprintf(temp,"%0.1f",((float)(temp_1)/10));
		sprintf(hum,"%0.1f",((float)(hum_1)/10));
		return TRUE;
	}
	return FALSE;
}