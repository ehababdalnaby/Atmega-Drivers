/*
 * GPS.h
 *
 * Created: 8/24/2021 10:09:11 PM
 *  Author: Mohamed
 */ 


#ifndef GPS_H_
#define GPS_H_
#include "includes.h"





void GPS_Read(void);
void strfToint(u8* strf);
void convert_to_degrees(u8 *raw);
void convert_time_to_UTC(u8 *time);

#endif /* GPS_H_ */