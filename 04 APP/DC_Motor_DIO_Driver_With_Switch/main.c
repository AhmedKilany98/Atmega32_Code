/*
 * main.c
 *
 *  Created on: Oct 07, 2019
 *  Author: Ahmed Kilany
 *  Version: v1.0
 */

#include "BIT_MATH.h"
#include "STD_Types.h"

#include <util/delay.h>

#include "DIO_int.h"

// confige keys
uint8 GetKey(void);
#define key_uint8_ROW1	 DIO_uint8_PIN_0
#define key_uint8_COL1		 DIO_uint8_PIN_1
#define key_uint8_COL2	 DIO_uint8_PIN_2
#define key_uint8_COL3	 DIO_uint8_PIN_3


void main() {
	uint8 val = 0;
	DIO_vid_Init();
	// Key init
	DIO_vid_SetPinValue(key_uint8_ROW1,DIO_uint8_HIGH);
	while (1)
	{
		val = GetKey();
		if(GET_BIT(val,0) == DIO_uint8_HIGH)
		{
			DIO_vid_SetPinValue(DIO_uint8_PIN_24,DIO_uint8_HIGH);
			DIO_vid_SetPinValue(DIO_uint8_PIN_25,DIO_uint8_LOW);
		}
		if(GET_BIT(val,1) == DIO_uint8_HIGH)
		{
			DIO_vid_SetPinValue(DIO_uint8_PIN_24,DIO_uint8_LOW);
			DIO_vid_SetPinValue(DIO_uint8_PIN_25,DIO_uint8_LOW);
		}
		if(GET_BIT(val,2) == DIO_uint8_HIGH)
		{
			DIO_vid_SetPinValue(DIO_uint8_PIN_24,DIO_uint8_LOW);
			DIO_vid_SetPinValue(DIO_uint8_PIN_25,DIO_uint8_HIGH);
		}
	} // while 1
} // main

uint8 GetKey(void)
{
	uint8 key = 0;
	// sequence 0
	DIO_vid_SetPinValue(key_uint8_COL1,DIO_uint8_LOW);
	DIO_vid_SetPinValue(key_uint8_COL2,DIO_uint8_HIGH);
	DIO_vid_SetPinValue(key_uint8_COL3,DIO_uint8_HIGH);

	if(DIO_uint8_GetPinValue(key_uint8_ROW1) == DIO_uint8_LOW)
	{
		SET_BIT(key,0);
	}
	// sequence 1
		DIO_vid_SetPinValue(key_uint8_COL1,DIO_uint8_HIGH);
		DIO_vid_SetPinValue(key_uint8_COL2,DIO_uint8_LOW);
		DIO_vid_SetPinValue(key_uint8_COL3,DIO_uint8_HIGH);

		if(DIO_uint8_GetPinValue(key_uint8_ROW1) == DIO_uint8_LOW)
		{
			SET_BIT(key,1);
		}
		// sequence 2
			DIO_vid_SetPinValue(key_uint8_COL1,DIO_uint8_HIGH);
			DIO_vid_SetPinValue(key_uint8_COL2,DIO_uint8_HIGH);
			DIO_vid_SetPinValue(key_uint8_COL3,DIO_uint8_LOW);

			if(DIO_uint8_GetPinValue(key_uint8_ROW1) == DIO_uint8_LOW)
			{
				SET_BIT(key,2);
			}
			return key;
}


