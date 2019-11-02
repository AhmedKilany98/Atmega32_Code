/*
 * main.c
 *
 *  Created on: Oct 07, 2019
 *      Author: Ahmed Kilany
 */

#include "BIT_MATH.h"
#include "STD_Types.h"

#include <util/delay.h>

#include "DIO_int.h"
#include "LCD_int.h"
#include "KeyPad_int.h"

/* Function use in App 	*/

void app_vid_Calculator(sint32 num1, sint32 num2, uint8 opr);
void app_vid_PrintResult(sint64);
/*  matrix */

uint8 KeyPad[4][4] = { { '1', '2', '3', '+' }, { '4', '5', '6', '-' }, { '7',
		'8', '9', '*' }, { '#', '0', '=', '/' } };

void main() {
	uint8 Local_uint8_InputArray[20]={0};
	uint8 Local_uint8_flag = 0;
	uint8 Local_uint8Index = 0;
	uint8 Local_uint8_LastIndex = 0;
	uint8 Local_uint8Value = 0;
	uint16 Local_uint16RetValue =0;

	DIO_vid_Init();
	LCD_vidInit();
	KeyPad_voidInit();

	LCD_vidWriteString("2 No. in Range");
	LCD_vidGoToRowCol(1, 0);
	LCD_vidWriteString("-50000 to 50000");
	_delay_ms(2000);
	LCD_vidClearScreen();

	while (1) {
		Local_uint16RetValue = KeyPad_uint16GetStatus();
		_delay_ms(150);

		for (Local_uint8Index = 0; Local_uint8Index < 16; Local_uint8Index++)
		{
			if (GET_BIT(Local_uint16RetValue, Local_uint8Index))
			{
				Local_uint8Value = KeyPad[Local_uint8Index / 4][Local_uint8Index% 4];


				if (Local_uint8Value != '#')
				{
					Local_uint8_InputArray[Local_uint8_LastIndex] = Local_uint8Value;
					LCD_vidGoToRowCol(0, Local_uint8_LastIndex);
					LCD_vidWriteCharacter(Local_uint8Value);
					_delay_ms(500);
					Local_uint8_LastIndex ++;
				}
				else if (Local_uint8Value == '#')
				{
					LCD_vidGoToRowCol(0, Local_uint8_LastIndex - 1);
					LCD_vidWriteCharacter(' ');
					_delay_ms(500);
					Local_uint8_InputArray[Local_uint8_LastIndex - 1] = 0;
					Local_uint8_LastIndex--;
				}
				if(Local_uint8Value == '=')
				{
					uint8 Local_uint8Equal = 0;
					uint8 Local_uint8Flag = 0;
					sint32 Local_sint32_Num1 = 0;
					sint32 Local_sint32_Num2 = 0;
					uint8 Local_uint8_operation = 0;

					if(Local_uint8_InputArray[Local_uint8Equal] == '-')
					{
						Local_uint8Equal ++;
						Local_uint8Flag = 1;
					}
					while(Local_uint8_InputArray[Local_uint8Equal]>='0' && Local_uint8_InputArray[Local_uint8Equal] <='9')
					{
						Local_sint32_Num1 = (Local_sint32_Num1 * 10) + (Local_uint8_InputArray[Local_uint8Equal] - '0');
						Local_uint8Equal ++;
					}
					if(Local_uint8Flag==1)
					{
						Local_sint32_Num1 = (Local_sint32_Num1 * Local_sint32_Num1) / (-Local_sint32_Num1);
					}
					Local_uint8_operation = Local_uint8_InputArray[Local_uint8Equal++];
					while(Local_uint8_InputArray[Local_uint8Equal]>='0' && Local_uint8_InputArray[Local_uint8Equal] <='9')
					{
						Local_sint32_Num2 = (Local_sint32_Num2 * 10) + (Local_uint8_InputArray[Local_uint8Equal] - '0');
						Local_uint8Equal ++;
					}

					if(Local_uint8_InputArray[Local_uint8Equal] == '=')
					{
						 app_vid_Calculator(Local_sint32_Num1, Local_sint32_Num2,Local_uint8_operation);

//						LCD_vidGoToRowCol(1,0);
//						LCD_vidWriteString("                ");
//						_delay_ms(500);
//						uint8 i=0;
//						app_vid_PrintResult((sint64)Local_sint32_Num1);
//						_delay_ms(3000);
//						app_vid_PrintResult((sint64)Local_sint32_Num2);
//						_delay_ms(3000);

					}
					else
					{
						LCD_vidClearScreen();
						LCD_vidWriteString("INVALID Operation");
						_delay_ms(2000);
						LCD_vidClearScreen();
						uint8 Local_uint8Idx = 0;
						while(Local_uint8Idx < 20)
						{
							Local_uint8_InputArray[Local_uint8Idx ++] = 0;
						}
						Local_uint8_LastIndex = 0;
					}
				}	// if ==
			}	// if get
		} // for
	} // while 1
} // main

void app_vid_Calculator(sint32 num1, sint32 num2, uint8 opr)
{
	sint64 Local_sint64_Result = 0;
	if (opr == '+')
	{
		Local_sint64_Result = num1 + num2;
		app_vid_PrintResult(Local_sint64_Result );
//		app_vid_PrintResult((sint64)num1);
//		_delay_ms(2000);
//		app_vid_PrintResult((sint64)num2);
//		_delay_ms(2000);
	}
	else if (opr == '-')
	{
		Local_sint64_Result = num1 - num2;
		app_vid_PrintResult(Local_sint64_Result );
	}
	else if (opr == '*')
	{
		Local_sint64_Result = num1 * num2;
		app_vid_PrintResult(Local_sint64_Result );
	}
	else if (opr == '/')
	{
		if (num2 == 0)
		{

			LCD_vidGoToRowCol(1,0);
			LCD_vidWriteString("               ");
			_delay_ms(200);
			LCD_vidGoToRowCol(1,0);
			LCD_vidWriteString("INVALID VALUE");
			_delay_ms(1000);
			Local_sint64_Result = 0;
		}
		else
		{
			Local_sint64_Result = num1 / num2;
			app_vid_PrintResult(Local_sint64_Result );
		}
	}
}

void app_vid_PrintResult(sint64 num3)
{
	uint8 Local_uint8_OutputArray[20]={0};
	uint8 Local_uint8_idx=0 , Local_uint8_LastIndexLine2=0 , Local_uint8_chk=0;
	LCD_vidGoToRowCol(1,0);
	LCD_vidWriteString("                ");
	_delay_ms(500);

	if(num3 < 0)
	{
		num3 = (num3 * num3)/(-num3);
		Local_uint8_chk = 1;
	}
	_delay_ms(150);
	while(num3)
	{
		Local_uint8_OutputArray[Local_uint8_idx++] = 48 + (num3%10);
		num3 /= 10;
	}
	if(Local_uint8_chk == 1)
	{
		LCD_vidGoToRowCol(1, Local_uint8_LastIndexLine2++);
		LCD_vidWriteCharacter('-');
		_delay_ms(300);
	}
	while(Local_uint8_idx > 0)
	{
		LCD_vidGoToRowCol(1, Local_uint8_LastIndexLine2++);
		LCD_vidWriteCharacter(Local_uint8_OutputArray[Local_uint8_idx -1]);
		_delay_ms(200);
//		Local_uint8_LastIndexLine2 ++;
		Local_uint8_idx --;
	}
}
