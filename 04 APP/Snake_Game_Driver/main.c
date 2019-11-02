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

/*  matrix */

uint8 KeyPad[4][4] =
		{
				{ '1', '2', '3', '+' },
				{ '4', '5', '6', '-' },
				{ '7', '8', '9', '*' },
				{ '#', '0', '=', '/' }
		};

uint8 Dot_Location[5][2] = {{0,5},{0,8},{1,2},{1,11},{0,15}};
uint8 Snake_Location[5][2] = {{1,0},{1,15},{0,15},{0,3},{1,0}};

void main() {

	uint8 Local_uint8_NumTries =0;
	uint8 Local_uint8_DotRow = 0;
	uint8 Local_uint8_DotCol = 0;
	uint8 Local_uint8_SnkRow = 0;
	uint8 Local_uint8_SnkCol = 0;
	uint8 Local_uint8_flag = 0;
	uint8 Local_uint8_Index = 0;
	uint8 Local_uint8_DSIndex = 0;
	uint8 Local_uint8_Value = 0;
	sint8 Local_uint8_Counter = 0;
	uint16 Local_uint16_RetValue =0;

	DIO_vid_Init();
	LCD_vidInit();
	KeyPad_voidInit();

	LCD_vidGoToRowCol(0, 0);
	LCD_vidWriteString("Start Game:");
	for(Local_uint8_Counter = 5 ; Local_uint8_Counter >= 0 ; Local_uint8_Counter--)
	{
		LCD_vidGoToRowCol(0, 12);
		LCD_vidWriteCharacter(Local_uint8_Counter + 48);
		_delay_ms(1000);
	}
	LCD_vidClearScreen();

	while (1) {

		if(Local_uint8_flag == 0)
		{
			if(Local_uint8_DSIndex == 5)
			{
				if(Local_uint8_NumTries >= 3)
				{
					LCD_vidClearScreen();
					LCD_vidGoToRowCol(0,3);
					LCD_vidWriteString("You Win...");
					LCD_vidGoToRowCol(1,0);
					LCD_vidWriteString("Congratulation!");
					_delay_ms(2000);
					Local_uint8_DSIndex = 0;
					Local_uint8_flag = 0;
					Local_uint8_NumTries = 0;
				}
				else
				{
					LCD_vidClearScreen();
					LCD_vidGoToRowCol(0,3);
					LCD_vidWriteString("You Lose...");
					LCD_vidGoToRowCol(1,0);
					LCD_vidWriteString("Hard Luck!");
					_delay_ms(2000);
					LCD_vidClearScreen();
					LCD_vidGoToRowCol(0,0);
					LCD_vidWriteString("Will Play Again...");
					_delay_ms(2000);
					Local_uint8_DSIndex = 0;
					Local_uint8_flag = 0;
					Local_uint8_NumTries = 0;
				}
			}

			else
			{
				Local_uint8_DotRow = Dot_Location[Local_uint8_DSIndex][0];
				Local_uint8_DotCol = Dot_Location[Local_uint8_DSIndex][1];
				Local_uint8_SnkRow = Snake_Location[Local_uint8_DSIndex][0];
				Local_uint8_SnkCol = Snake_Location[Local_uint8_DSIndex][1];

				LCD_vidClearScreen();
				LCD_vidGoToRowCol(Local_uint8_DotRow, Local_uint8_DotCol);
				LCD_vidWriteCharacter('.');
				LCD_vidGoToRowCol(Local_uint8_SnkRow, Local_uint8_SnkCol);
				LCD_vidWriteCharacter('*');
				_delay_ms(500);
				Local_uint8_flag = 1;
				Local_uint8_DSIndex ++;
			}

		}
		Local_uint16_RetValue =0;
		Local_uint16_RetValue = KeyPad_uint16GetStatus();
		_delay_ms(150);

		for (Local_uint8_Index = 0; Local_uint8_Index < 16; Local_uint8_Index++)
		{
			if (GET_BIT(Local_uint16_RetValue, Local_uint8_Index))
			{
				Local_uint8_Value = KeyPad[Local_uint8_Index / 4][Local_uint8_Index% 4];

				if(Local_uint8_Value == '2')
				{
					if(Local_uint8_SnkRow == 1)
					{
						Local_uint8_SnkRow = 0;
					}
					else
					{
						Local_uint8_flag = 0;
						LCD_vidClearScreen();
						LCD_vidGoToRowCol(0,3);
						LCD_vidWriteString("You Lose...");
						LCD_vidGoToRowCol(1,0);
						LCD_vidWriteString("Hard Luck!");
						_delay_ms(1000);
						break;
					}
				} // if 2
				else if(Local_uint8_Value == '8')
				{
					if(Local_uint8_SnkRow == 0)
					{
						Local_uint8_SnkRow = 1;
					}
					else
					{
						Local_uint8_flag = 0;
						LCD_vidClearScreen();
						LCD_vidGoToRowCol(0,3);
						LCD_vidWriteString("You Lose...");
						LCD_vidGoToRowCol(1,0);
						LCD_vidWriteString("Hard Luck!");
						_delay_ms(1000);
						break;
					}
				}  // if 8
				else if(Local_uint8_Value == '4')
				{
					if(Local_uint8_SnkCol >= 0 && Local_uint8_SnkCol < 15)
					{
						Local_uint8_SnkCol ++;
					}
					else
					{
						Local_uint8_flag = 0;
						LCD_vidClearScreen();
						LCD_vidGoToRowCol(0,3);
						LCD_vidWriteString("You Lose...");
						LCD_vidGoToRowCol(1,0);
						LCD_vidWriteString("Hard Luck!");
						_delay_ms(1000);
						break;
					}
				}// if 4
				else if(Local_uint8_Value == '6')
				{
					if(Local_uint8_SnkCol > 0 && Local_uint8_SnkCol <= 15)
					{
						Local_uint8_SnkCol --;
					}
					else
					{
						Local_uint8_flag = 0;
						LCD_vidClearScreen();
						LCD_vidGoToRowCol(0,3);
						LCD_vidWriteString("You Lose...");
						LCD_vidGoToRowCol(1,0);
						LCD_vidWriteString("Hard Luck!");
						_delay_ms(1000);
						break;
					}
				}// if 6

			}	// if get
		} // for
		if(Local_uint8_flag == 1)
		{
			LCD_vidClearScreen();
			LCD_vidGoToRowCol(Local_uint8_DotRow, Local_uint8_DotCol);
			LCD_vidWriteCharacter('.');
			LCD_vidGoToRowCol(Local_uint8_SnkRow, Local_uint8_SnkCol);
			LCD_vidWriteCharacter('*');
			_delay_ms(100);

			if(Local_uint8_DotRow == Local_uint8_SnkRow && Local_uint8_DotCol == Local_uint8_SnkCol)
			{
				Local_uint8_flag = 0;
				Local_uint8_NumTries++;
			}
		}
	} // while 1
} // main
