/*
 * LCD_prg.c
 */

#include "BIT_MATH.h"
#include "STD_Types.h"

#include <util/delay.h>

#include "DIO_int.h"
#include "LCD_int.h"
#include "LCD_config.h"
#include "LCD_priv.h"

void LCD_vidInit(void)
{
#if LCD_MODE == LCD_uint8_8BitMode
	_delay_ms(35);
	LCD_vidWriteCommand(0b00111000); // Function Set
	_delay_ms(1);
	LCD_vidWriteCommand(0b00001110); // Display On/Off
	_delay_ms(1);
	LCD_vidWriteCommand(0b00000001); // Clear Display
	_delay_ms(2);
	LCD_vidWriteCommand(0b00000110);
#elif LCD_MODE == LCD_uint8_4BitMode
	_delay_ms(35);
	LCD_vidWriteCommand(0x33);
	_delay_ms(1);
	LCD_vidWriteCommand(0x32);
	_delay_ms(1);
	LCD_vidWriteCommand(0x28);
	_delay_ms(1);
	LCD_vidWriteCommand(0b00001110);
	_delay_ms(1);
	LCD_vidWriteCommand(0b00000001); // Clear Display
	_delay_ms(2);
	LCD_vidWriteCommand(0b00000110);
#endif
}

void LCD_vidWriteCharacter(uint8 Copy_uint8data)
{

#if LCD_MODE == LCD_uint8_8BitMode
	DIO_vid_SetPinValue( LCD_uint8_PIN_RS ,  DIO_uint8_HIGH);
	LCD_SvidExecute(Copy_uint8data);
#elif LCD_MODE == LCD_uint8_4BitMode
	DIO_vid_SetPinValue( LCD_uint8_PIN_RS ,  DIO_uint8_HIGH);
	LCD_SvidExecute(Copy_uint8data &0xF0);
	DIO_vid_SetPinValue( LCD_uint8_PIN_RS ,  DIO_uint8_HIGH);
	LCD_SvidExecute((Copy_uint8data & 0x0F)<< 4);
#endif
}

void LCD_vidWriteCommand(uint8 Copy_uint8cmd)
{
#if LCD_MODE == LCD_uint8_8BitMode
	DIO_vid_SetPinValue( LCD_uint8_PIN_RS ,  DIO_uint8_LOW);
	LCD_SvidExecute(Copy_uint8cmd);
#elif LCD_MODE == LCD_uint8_4BitMode
	DIO_vid_SetPinValue( LCD_uint8_PIN_RS ,  DIO_uint8_LOW);
	LCD_SvidExecute(Copy_uint8cmd & 0xF0);
	DIO_vid_SetPinValue( LCD_uint8_PIN_RS ,  DIO_uint8_LOW);
	LCD_SvidExecute((Copy_uint8cmd & 0x0F)<< 4);
#endif
}

void LCD_vidWriteString(uint8 * Copy_pString)
{
	uint8 Local_uint8Index = 0 ;
	while(Copy_pString[Local_uint8Index]  != '\0' )
	{
		LCD_vidWriteCharacter(Copy_pString[Local_uint8Index]);
		Local_uint8Index++ ;
	}

}

void LCD_vidGoToRowCol(uint8 Copy_uint8Row , uint8 Copy_uint8Col )
{
	uint8 Local_uint8Address ;
	switch(Copy_uint8Row)
	{
	case 0 :
		Local_uint8Address = 0x00 + Copy_uint8Col ;
		break ;
	case 1 :
		Local_uint8Address = 0x40 + Copy_uint8Col ;
		break ;
	}
	LCD_vidWriteCommand(0x80 | Local_uint8Address );
}

void LCD_vidClearScreen(void)
{
	LCD_vidWriteCommand(0b00000001);
}

void LCD_vid_AutoscrollLeft(void)
{
	LCD_vidWriteCommand(0x18);
}

void LCD_vid_AutoscrollRight(void)
{
	LCD_vidWriteCommand(0x1C);
}

static void LCD_SvidExecute(uint8 Copy_uint8DataCmd)
{

	DIO_vid_SetPinValue( LCD_uint8_PIN_RW ,  DIO_uint8_LOW );
	_delay_ms(1);
	DIO_vid_SetPinValue( LCD_uint8_PIN_E ,  DIO_uint8_HIGH);
	_delay_ms(1);

	#if LCD_MODE == LCD_uint8_8BitMode
	/*PIN7*/
	if( GET_BIT(Copy_uint8DataCmd , 7)  )
	{
		DIO_vid_SetPinValue( LCD_uint8_PIN_D7 ,  DIO_uint8_HIGH);
	}
	else
	{
		DIO_vid_SetPinValue( LCD_uint8_PIN_D7 ,  DIO_uint8_LOW);
	}
	/*PIN6*/
	if( GET_BIT(Copy_uint8DataCmd , 6) )
	{
		DIO_vid_SetPinValue( LCD_uint8_PIN_D6 ,  DIO_uint8_HIGH);
	}
	else
	{
		DIO_vid_SetPinValue( LCD_uint8_PIN_D6 ,  DIO_uint8_LOW);
	}
	/*PIN5*/
	if( GET_BIT(Copy_uint8DataCmd , 5) )
	{
		DIO_vid_SetPinValue( LCD_uint8_PIN_D5 ,  DIO_uint8_HIGH);
	}
	else
	{
		DIO_vid_SetPinValue( LCD_uint8_PIN_D5 ,  DIO_uint8_LOW);
	}
	/*PIN4*/
	if( GET_BIT(Copy_uint8DataCmd , 4) )
	{
		DIO_vid_SetPinValue( LCD_uint8_PIN_D4 ,  DIO_uint8_HIGH);
	}
	else
	{
		DIO_vid_SetPinValue( LCD_uint8_PIN_D4 ,  DIO_uint8_LOW);
	}

	/*PIN3*/
	if( GET_BIT(Copy_uint8DataCmd , 3) )
	{
		DIO_vid_SetPinValue( LCD_uint8_PIN_D3 ,  DIO_uint8_HIGH);
	}
	else
	{
		DIO_vid_SetPinValue( LCD_uint8_PIN_D3 ,  DIO_uint8_LOW);
	}
	/*PIN2*/
	if( GET_BIT(Copy_uint8DataCmd , 2) )
	{
		DIO_vid_SetPinValue( LCD_uint8_PIN_D2 ,  DIO_uint8_HIGH);
	}
	else
	{
		DIO_vid_SetPinValue( LCD_uint8_PIN_D2 ,  DIO_uint8_LOW);
	}
	/*PIN1*/
	if( GET_BIT(Copy_uint8DataCmd , 1) )
	{
		DIO_vid_SetPinValue( LCD_uint8_PIN_D1 ,  DIO_uint8_HIGH);
	}
	else
	{
		DIO_vid_SetPinValue( LCD_uint8_PIN_D1 ,  DIO_uint8_LOW);
	}
	/*PIN0*/
	if( GET_BIT(Copy_uint8DataCmd , 0) )
	{
		DIO_vid_SetPinValue( LCD_uint8_PIN_D0 ,  DIO_uint8_HIGH);
	}
	else
	{
		DIO_vid_SetPinValue( LCD_uint8_PIN_D0 ,  DIO_uint8_LOW);
	}

	#elif LCD_MODE == LCD_uint8_4BitMode
	/*PIN7*/
		if( GET_BIT(Copy_uint8DataCmd , 7)  )
		{
			DIO_vid_SetPinValue( LCD_uint8_PIN_D7 ,  DIO_uint8_HIGH);
		}
		else
		{
			DIO_vid_SetPinValue( LCD_uint8_PIN_D7 ,  DIO_uint8_LOW);
		}
		/*PIN6*/
		if( GET_BIT(Copy_uint8DataCmd , 6) )
		{
			DIO_vid_SetPinValue( LCD_uint8_PIN_D6 ,  DIO_uint8_HIGH);
		}
		else
		{
			DIO_vid_SetPinValue( LCD_uint8_PIN_D6 ,  DIO_uint8_LOW);
		}
		/*PIN5*/
		if( GET_BIT(Copy_uint8DataCmd , 5) )
		{
			DIO_vid_SetPinValue( LCD_uint8_PIN_D5 ,  DIO_uint8_HIGH);
		}
		else
		{
			DIO_vid_SetPinValue( LCD_uint8_PIN_D5 ,  DIO_uint8_LOW);
		}
		/*PIN4*/
		if( GET_BIT(Copy_uint8DataCmd , 4) )
		{
			DIO_vid_SetPinValue( LCD_uint8_PIN_D4 ,  DIO_uint8_HIGH);
		}
		else
		{
			DIO_vid_SetPinValue( LCD_uint8_PIN_D4 ,  DIO_uint8_LOW);
		}

	#endif
	_delay_ms(1);
	DIO_vid_SetPinValue( LCD_uint8_PIN_E ,  DIO_uint8_LOW);
	_delay_ms(2);


}
