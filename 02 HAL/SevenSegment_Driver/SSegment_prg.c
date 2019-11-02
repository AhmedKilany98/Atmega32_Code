/*
 * SSegment_prg.c
 *
 *  Created on: Feb 21, 2018
 *      Author: Mohamed Sobhy
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_int.h"
#include "SSegment_int.h"
#include "SSegment_priv.h"
#include "SSegment_config.h"

#define ARR_SIZE		10

static uint8 Ssegment_uint8Array[ARR_SIZE] = {ZERO , ONE , TWO , THREE , FOUR , FIVE , SIX , SEVEN , EIGHT , NINE };

void Ssegment_void_WriteNum(uint8 Copy_uint8_SsegmentNum , uint8 Copy_uint8_Num)
{
	//uint8 Local_uint8_LoopIndex ;
#ifdef FIRST_SEGMENT

	if(Copy_uint8_SsegmentNum == SSEGMENT_RIGHT)
	{
		if( GET_BIT(Ssegment_uint8Array[Copy_uint8_Num] , BIT_0) )
		{
			DIO_vid_SetPinValue(SSEGMENT_ONE_PIN_A , DIO_uint8_HIGH);
		}
		else
		{
			DIO_vid_SetPinValue(SSEGMENT_ONE_PIN_A , DIO_uint8_LOW);
		}
		if( GET_BIT(Ssegment_uint8Array[Copy_uint8_Num] , BIT_1) )
		{
			DIO_vid_SetPinValue(SSEGMENT_ONE_PIN_B , DIO_uint8_HIGH);
		}
		else
		{
			DIO_vid_SetPinValue(SSEGMENT_ONE_PIN_B , DIO_uint8_LOW);
		}
		if( GET_BIT(Ssegment_uint8Array[Copy_uint8_Num] , BIT_2) )
		{
			DIO_vid_SetPinValue(SSEGMENT_ONE_PIN_C , DIO_uint8_HIGH);
		}
		else
		{
			DIO_vid_SetPinValue(SSEGMENT_ONE_PIN_C , DIO_uint8_LOW);
		}
		if( GET_BIT(Ssegment_uint8Array[Copy_uint8_Num] , BIT_3) )
		{
			DIO_vid_SetPinValue(SSEGMENT_ONE_PIN_D , DIO_uint8_HIGH);
		}
		else
		{
			DIO_vid_SetPinValue(SSEGMENT_ONE_PIN_D , DIO_uint8_LOW);
		}
		if( GET_BIT(Ssegment_uint8Array[Copy_uint8_Num] , BIT_4) )
		{
			DIO_vid_SetPinValue(SSEGMENT_ONE_PIN_E , DIO_uint8_HIGH);
		}
		else
		{
			DIO_vid_SetPinValue(SSEGMENT_ONE_PIN_E , DIO_uint8_LOW);
		}
		if( GET_BIT(Ssegment_uint8Array[Copy_uint8_Num] , BIT_5) )
		{
			DIO_vid_SetPinValue(SSEGMENT_ONE_PIN_F , DIO_uint8_HIGH);
		}
		else
		{
			DIO_vid_SetPinValue(SSEGMENT_ONE_PIN_F , DIO_uint8_LOW);
		}
		if( GET_BIT(Ssegment_uint8Array[Copy_uint8_Num] , BIT_6) )
		{
			DIO_vid_SetPinValue(SSEGMENT_ONE_PIN_G , DIO_uint8_HIGH);
		}
		else
		{
			DIO_vid_SetPinValue(SSEGMENT_ONE_PIN_G , DIO_uint8_LOW);
		}

		/*
		for(Local_uint8_LoopIndex = START_VALUE ; Local_uint8_LoopIndex < END_VALUE ; Local_uint8_LoopIndex++)
		{
			if(GET_BIT(Ssegment_uint8Array[Copy_uint8_Num] , Local_uint8_LoopIndex))
			{
				DIO_vid_SetPinValue(SSEGMENT_ONE_PIN_A+Local_uint8_LoopIndex , DIO_uint8_HIGH);
			}
			else
			{
				DIO_vid_SetPinValue(SSEGMENT_ONE_PIN_A+Local_uint8_LoopIndex , DIO_uint8_LOW);
			}
		}
		 */

	}
#endif

#ifdef SECOND_SEGMENT
	if(Copy_uint8_SsegmentNum == SSEGMENT_LEFT)
	{
		if( GET_BIT(Ssegment_uint8Array[Copy_uint8_Num] , BIT_0) )
		{
			DIO_vid_SetPinValue(SSEGMENT_TWO_PIN_A , DIO_uint8_HIGH);
		}
		else
		{
			DIO_vid_SetPinValue(SSEGMENT_TWO_PIN_A , DIO_uint8_LOW);
		}
		if( GET_BIT(Ssegment_uint8Array[Copy_uint8_Num] , BIT_1) )
		{
			DIO_vid_SetPinValue(SSEGMENT_TWO_PIN_B , DIO_uint8_HIGH);
		}
		else
		{
			DIO_vid_SetPinValue(SSEGMENT_TWO_PIN_B , DIO_uint8_LOW);
		}
		if( GET_BIT(Ssegment_uint8Array[Copy_uint8_Num] , BIT_2) )
		{
			DIO_vid_SetPinValue(SSEGMENT_TWO_PIN_C , DIO_uint8_HIGH);
		}
		else
		{
			DIO_vid_SetPinValue(SSEGMENT_TWO_PIN_C , DIO_uint8_LOW);
		}
		if( GET_BIT(Ssegment_uint8Array[Copy_uint8_Num] , BIT_3) )
		{
			DIO_vid_SetPinValue(SSEGMENT_TWO_PIN_D , DIO_uint8_HIGH);
		}
		else
		{
			DIO_vid_SetPinValue(SSEGMENT_TWO_PIN_D , DIO_uint8_LOW);
		}
		if( GET_BIT(Ssegment_uint8Array[Copy_uint8_Num] , BIT_4) )
		{
			DIO_vid_SetPinValue(SSEGMENT_TWO_PIN_E , DIO_uint8_HIGH);
		}
		else
		{
			DIO_vid_SetPinValue(SSEGMENT_TWO_PIN_E , DIO_uint8_LOW);
		}
		if( GET_BIT(Ssegment_uint8Array[Copy_uint8_Num] , BIT_5) )
		{
			DIO_vid_SetPinValue(SSEGMENT_TWO_PIN_F , DIO_uint8_HIGH);
		}
		else
		{
			DIO_vid_SetPinValue(SSEGMENT_TWO_PIN_F , DIO_uint8_LOW);
		}
		if( GET_BIT(Ssegment_uint8Array[Copy_uint8_Num] , BIT_6) )
		{
			DIO_vid_SetPinValue(SSEGMENT_TWO_PIN_G , DIO_uint8_HIGH);
		}
		else
		{
			DIO_vid_SetPinValue(SSEGMENT_TWO_PIN_G , DIO_uint8_LOW);
		}

		/*
		for(Local_uint8_LoopIndex = START_VALUE ; Local_uint8_LoopIndex < END_VALUE ; Local_uint8_LoopIndex++)
		{
			if(GET_BIT(Ssegment_uint8Array[Copy_uint8_Num] , Local_uint8_LoopIndex))
			{
				DIO_vid_SetPinValue(SSEGMENT_TWO_PIN_A+Local_uint8_LoopIndex , DIO_uint8_HIGH);
			}
			else
			{
				DIO_vid_SetPinValue(SSEGMENT_TWO_PIN_A+Local_uint8_LoopIndex , DIO_uint8_LOW);
			}
		}
		 */

	}
#endif


} // end of function


