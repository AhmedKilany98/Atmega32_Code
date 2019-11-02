

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_int.h"
#include "KeyPad_int.h"
#include "KeyPad_priv.h"
#include "KeyPad_config.h"

uint16 KeyPad_uint16_Status  ;

/* Connect pull up resistor or not */
void KeyPad_voidInit(void)
{
#if ( KEYPAD_UINT8_PULLUP == KEYPAD_UINT8_INTERNAL)

	DIO_vid_SetPinValue(KEYPAD_uint8_ROW1 , DIO_uint8_HIGH);
	DIO_vid_SetPinValue(KEYPAD_uint8_ROW2 , DIO_uint8_HIGH);
	DIO_vid_SetPinValue(KEYPAD_uint8_ROW3 , DIO_uint8_HIGH);
	DIO_vid_SetPinValue(KEYPAD_uint8_ROW4 , DIO_uint8_HIGH);

#endif

}

/*This function shall return 16 bit variable
		indicating the status of each key */

uint16 KeyPad_uint16GetStatus(void)
{
	KeyPad_uint16_Status = 0 ;

	/*Apply sequence 0 */
	DIO_vid_SetPinValue(KEYPAD_uint8_COL1 , DIO_uint8_LOW);
	DIO_vid_SetPinValue(KEYPAD_uint8_COL2 , DIO_uint8_HIGH);
	DIO_vid_SetPinValue(KEYPAD_uint8_COL3 , DIO_uint8_HIGH);
	DIO_vid_SetPinValue(KEYPAD_uint8_COL4 , DIO_uint8_HIGH);

	KeyPad_voidCheckRow(0);

	/*Apply sequence 1 */
	DIO_vid_SetPinValue(KEYPAD_uint8_COL1 , DIO_uint8_HIGH);
	DIO_vid_SetPinValue(KEYPAD_uint8_COL2 , DIO_uint8_LOW);
	DIO_vid_SetPinValue(KEYPAD_uint8_COL3 , DIO_uint8_HIGH);
	DIO_vid_SetPinValue(KEYPAD_uint8_COL4 , DIO_uint8_HIGH);

	KeyPad_voidCheckRow(1);

	/*Apply sequence 2 */
	DIO_vid_SetPinValue(KEYPAD_uint8_COL1 , DIO_uint8_HIGH);
	DIO_vid_SetPinValue(KEYPAD_uint8_COL2 , DIO_uint8_HIGH);
	DIO_vid_SetPinValue(KEYPAD_uint8_COL3 , DIO_uint8_LOW);
	DIO_vid_SetPinValue(KEYPAD_uint8_COL4 , DIO_uint8_HIGH);

	KeyPad_voidCheckRow(2);

	/*Apply sequence 3 */
	DIO_vid_SetPinValue(KEYPAD_uint8_COL1 , DIO_uint8_HIGH);
	DIO_vid_SetPinValue(KEYPAD_uint8_COL2 , DIO_uint8_HIGH);
	DIO_vid_SetPinValue(KEYPAD_uint8_COL3 , DIO_uint8_HIGH);
	DIO_vid_SetPinValue(KEYPAD_uint8_COL4 , DIO_uint8_LOW);

	KeyPad_voidCheckRow(3);


	return KeyPad_uint16_Status ;

}


static void KeyPad_voidCheckRow(uint8 Copy_Number)
{


	if(DIO_uint8_GetPinValue(KEYPAD_uint8_ROW1) == DIO_uint8_LOW)
	{
		SET_BIT(KeyPad_uint16_Status , ( (0*4)+ Copy_Number ) );
	}
	if(DIO_uint8_GetPinValue(KEYPAD_uint8_ROW2) == DIO_uint8_LOW)
	{
		SET_BIT(KeyPad_uint16_Status , ( (1*4)+ Copy_Number ) );
	}
	if(DIO_uint8_GetPinValue(KEYPAD_uint8_ROW3) == DIO_uint8_LOW)
	{
		SET_BIT(KeyPad_uint16_Status , ( (2*4)+ Copy_Number ) );
	}
	if(DIO_uint8_GetPinValue(KEYPAD_uint8_ROW4) == DIO_uint8_LOW)
	{
		SET_BIT(KeyPad_uint16_Status , ( (3*4)+ Copy_Number ) );
	}


}
