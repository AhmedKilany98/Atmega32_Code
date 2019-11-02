/*
 * S_Segment_main.c
 *
 *  Created on: Feb 17, 2018
 *      Author: Mohamed Sobhy
 */


#include <util/delay.h>

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "DIO_int.h"
#include "SSegment_int.h"


#define START 0
#define END 9

int main(void)
{
	//uint8 Local_uint8_LoopIndex ;
    DIO_vid_Init();
    uint8 up=START, down=END;

	while(1)
	{
		 Ssegment_void_WriteNum(SSEGMENT_RIGHT , up++);
		 Ssegment_void_WriteNum(SSEGMENT_LEFT ,down--);
		 _delay_ms(500);
		 if(up > END)
		 {
			 up=START;
		 }
		 if(down > END)
		 {
			 down = END;
		 }
	}


	return 0 ;
}


