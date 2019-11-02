


#include "BIT_MATH.h"
#include "STD_Types.h"

#include <util/delay.h>

/*
#define F_CPU 8000000UL

#include "util/delay.h"
 */

#include "DIO_int.h"
#include "LCD_int.h"
#include "KeyPad_int.h"

void main()
{

	uint8 Local_uint8Index ;
	uint16 Local_uint16RetValue = 0 ;
	uint8 Local_ones ;
	uint8 Local_tens ;
	DIO_vid_Init();
	LCD_vidInit();
	KeyPad_voidInit();

	LCD_vidWriteString("HELLO WORLD");

	_delay_ms(2000);
	LCD_vidClearScreen();




	while(1)
	{
		Local_uint16RetValue = KeyPad_uint16GetStatus();
		_delay_ms(150);
		for(Local_uint8Index = 0 ; Local_uint8Index < 16 ; Local_uint8Index++)
		{
			if( GET_BIT(Local_uint16RetValue , Local_uint8Index) )
			{
				if(Local_uint8Index <= 9)
				{
					LCD_vidGoToRowCol(0 , 0);
					LCD_vidWriteCharacter(Local_uint8Index+ '0');
					LCD_vidWriteCharacter(' ');
					_delay_ms(500);
				}
				else if(Local_uint8Index >= 10 && Local_uint8Index <= 15)
				{
					Local_ones = Local_uint8Index % 10 ;
					Local_tens = Local_uint8Index / 10 ;
					LCD_vidGoToRowCol(0 , 0);
					LCD_vidWriteCharacter(Local_tens + 48);
					LCD_vidWriteCharacter(Local_ones + '0' );
					_delay_ms(500);
				}
			}

		}


	}


}
