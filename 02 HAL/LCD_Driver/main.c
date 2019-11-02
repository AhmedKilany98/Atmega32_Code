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
#include "LCD_int.h"


void main()
{
	DIO_vid_Init();
	LCD_vidInit();
	uint8 Local_uint8Idx1=0 , Local_uint8idx2=11 , Local_uint8_flag=0;
	while(1)
	{
		LCD_vidClearScreen();
		if(Local_uint8_flag ==0)
		{
			LCD_vidGoToRowCol(0,Local_uint8Idx1);  // Move Right
			LCD_vidWriteString("Ahmed");
			LCD_vidGoToRowCol(1,Local_uint8idx2);		// Move Left
			LCD_vidWriteString("Sayed");
			_delay_ms(500);
			if(Local_uint8Idx1 == 11 && Local_uint8idx2 == 0)
			{
				Local_uint8_flag = 1;
			}
			else
			{
				Local_uint8Idx1++; Local_uint8idx2--;
			}
		}
		else if(Local_uint8_flag ==1)
		{
			LCD_vidGoToRowCol(0,Local_uint8Idx1);
			LCD_vidWriteString("Ahmed");  // Move Left
			LCD_vidGoToRowCol(1,Local_uint8idx2);
			LCD_vidWriteString("Sayed"); // Move Right
			_delay_ms(500);
			if(Local_uint8Idx1 ==0 && Local_uint8idx2 ==11)
			{
				Local_uint8_flag = 0;
			}
			else
			{
				Local_uint8Idx1--; Local_uint8idx2++;
			}
		}
	}
}

