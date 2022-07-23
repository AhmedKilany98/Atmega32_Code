/*
 * main.c
 *
 *  Created on: Oct 4, 2019
 *      Author: Kilany
 */

#include "util/delay.h"
#include "BIT_MATH.h"
#include "STD_Types.h"

#include "DIO_int.h"

void main()
{
	uint8 i=0;
	DIO_vid_Init();
	DIO_vid_SetPinValue(DIO_uint8_PIN_0,DIO_uint8_HIGH);
	while(1)
	{
		if( (DIO_uint8_GetPinValue(DIO_uint8_PIN_0)==0) &&( i==0))
		{
			_delay_ms(250);
			DIO_vid_SetPinValue(DIO_uint8_PIN_1,DIO_uint8_HIGH);
			i=1;
		}
		else if( (DIO_uint8_GetPinValue(DIO_uint8_PIN_0)==0) && (i==1))
		{
			_delay_ms(250);
			DIO_vid_SetPinValue(DIO_uint8_PIN_1,DIO_uint8_LOW);
			i=0;
		}



	}
}
