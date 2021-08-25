/*
 * GPS.c
 *
 * Created: 25/08/2021 11:15:44 ص
 *  Author: Administrator
 */ 
#include "GPS.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "LCD.h"
void strfToint(u8* strf) //{"12312.1234"} // {"1212.1234"}
{
	u8 i=0;
	u8 dotIndex;
	u32 Num;
	while (strf[i]!='.')
		i++;
	dotIndex=i;
	i=i-2;
	Num=atoi(&strf[i])*(10000UL);
	Num=Num+atoi(&strf[dotIndex+1]); /// 121234
	Num=(Num*10)/60UL;
	strf[dotIndex-2]='.';
	sprintf(&strf[dotIndex-1],"%u",Num);
	//disp_strXY(1,1,strf);

}