/*
 * DIO_prg.c
 *
 *  Created on: Dec 22, 2018
 *      Author: Mohamed Sobhy
 */

#include "BIT_MATH.h"
#include "STD_Types.h"
#include "DIO_int.h"
#include "DIO_priv.h"
#include "DIO_config.h"


void DIO_vid_Init(void)
{
	DDRA = DIO_uint8_PORTA_DIRECTION ;
	DDRB = DIO_uint8_PORTB_DIRECTION ;
	DDRC = DIO_uint8_PORTC_DIRECTION ;
	DDRD = DIO_uint8_PORTD_DIRECTION ;

}

void DIO_vid_SetPinValue(uint8 Copy_uint8_PinNo , uint8 Copy_uint8_Value)
{
	if( (Copy_uint8_PinNo >=DIO_uint8_PORTA_START) && (Copy_uint8_PinNo <=DIO_uint8_PORTA_END) )
			{
				/*Get Valid Range for PORTB pins */
				//Copy_uint8PinNum = Copy_uint8PinNum - DIO_uint8_PORTA_SIZE ;
				if(Copy_uint8_Value == DIO_uint8_HIGH)
				{
					SET_BIT(PORTA , Copy_uint8_PinNo);
				}
				else
				{
					CLEAR_BIT(PORTA , Copy_uint8_PinNo);
				}
			}
	if( (Copy_uint8_PinNo >= DIO_uint8_PORTB_START) && (Copy_uint8_PinNo <= DIO_uint8_PORTB_END) )
		{
			/*Get Valid Range for PORTB pins */
			Copy_uint8_PinNo = Copy_uint8_PinNo - DIO_uint8_PORTA_SIZE ;
			if(Copy_uint8_Value == DIO_uint8_HIGH)
			{
				SET_BIT(PORTB , Copy_uint8_PinNo);
			}
			else
			{
					CLEAR_BIT(PORTB , Copy_uint8_PinNo);
			}
		}

		if( (Copy_uint8_PinNo >=DIO_uint8_PORTC_START) && (Copy_uint8_PinNo <=DIO_uint8_PORTC_END) )
		{
			/*Get Valid Range for PORTC pins */
			Copy_uint8_PinNo = Copy_uint8_PinNo - (DIO_uint8_PORTA_SIZE  + DIO_uint8_PORTB_SIZE ) ;
			if(Copy_uint8_Value == DIO_uint8_HIGH)
			{
				SET_BIT(PORTC , Copy_uint8_PinNo);
			}
			else
			{
					CLEAR_BIT(PORTC , Copy_uint8_PinNo);
			}
		}

		if( (Copy_uint8_PinNo >=DIO_uint8_PORTD_START) && (Copy_uint8_PinNo <=DIO_uint8_PORTD_END) )
		{
			/*Get Valid Range for PORTD pins */
			Copy_uint8_PinNo = Copy_uint8_PinNo - (DIO_uint8_PORTA_SIZE + DIO_uint8_PORTB_SIZE + DIO_uint8_PORTC_SIZE) ;
			if(Copy_uint8_Value == DIO_uint8_HIGH)
			{
				SET_BIT(PORTD , Copy_uint8_PinNo);
			}
			else
			{
					CLEAR_BIT(PORTD , Copy_uint8_PinNo);
			}
		}

}

uint8 DIO_uint8_GetPinValue(uint8 Copy_uint8_PinNo)
{
	uint8 Local_uint8Result;

		/* Find PORTA Pins                        */
		if( (Copy_uint8_PinNo >=DIO_uint8_PORTA_START) && (Copy_uint8_PinNo <=DIO_uint8_PORTA_END) )
		{
			/*Get Valid Range for PORTA pins */
			//Copy_uint8_PinNo = Copy_uint8_PinNo - DIO_uint8_PORTA_SIZE ;
			Local_uint8Result = GET_BIT(PINA , Copy_uint8_PinNo);
			if(Local_uint8Result == 1)
			{
				Local_uint8Result = DIO_uint8_HIGH ;
			}
			else
			{
				Local_uint8Result = DIO_uint8_LOW ;
			}
		}

		if( (Copy_uint8_PinNo >=DIO_uint8_PORTB_START) && (Copy_uint8_PinNo <=DIO_uint8_PORTB_END) )
		{
			/*Get Valid Range for PORTB pins */
			Copy_uint8_PinNo = Copy_uint8_PinNo - DIO_uint8_PORTA_SIZE ;
			Local_uint8Result = GET_BIT(PINB , Copy_uint8_PinNo);
			if(Local_uint8Result == 1)
			{
				Local_uint8Result = DIO_uint8_HIGH ;
			}
			else
			{
				Local_uint8Result = DIO_uint8_LOW ;
			}
		}

		if( (Copy_uint8_PinNo >=DIO_uint8_PORTC_START) && (Copy_uint8_PinNo <=DIO_uint8_PORTC_END) )
		{
			/*Get Valid Range for PORTC pins */
			Copy_uint8_PinNo = Copy_uint8_PinNo - (DIO_uint8_PORTA_SIZE  + DIO_uint8_PORTB_SIZE ) ;
			Local_uint8Result = GET_BIT(PINC , Copy_uint8_PinNo);
			if(Local_uint8Result == 1)
			{
				Local_uint8Result = DIO_uint8_HIGH ;
			}
			else
			{
				Local_uint8Result = DIO_uint8_LOW ;
			}
		}

		if( (Copy_uint8_PinNo >=DIO_uint8_PORTD_START) && (Copy_uint8_PinNo <=DIO_uint8_PORTD_END) )
		{
			/*Get Valid Range for PORTD pins */
			Copy_uint8_PinNo = Copy_uint8_PinNo - (DIO_uint8_PORTA_SIZE + DIO_uint8_PORTB_SIZE + DIO_uint8_PORTC_SIZE) ;
			Local_uint8Result = GET_BIT(PIND , Copy_uint8_PinNo);
			if(Local_uint8Result == 1)
			{
				Local_uint8Result = DIO_uint8_HIGH ;
			}
			else
			{
				Local_uint8Result = DIO_uint8_LOW ;
			}
		}

		return Local_uint8Result ;


}
