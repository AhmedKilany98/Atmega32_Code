#ifndef DIO_INT_H_
#define DIO_INT_H_
/*
 *  DIO_int.h
 *  Created on: Dec 22, 2018
 *  Author: Mohamed Sobhy
 *  Version : v01
 */

#define DIO_uint8_PIN_0		0
#define DIO_uint8_PIN_1		1
#define DIO_uint8_PIN_2		2
#define DIO_uint8_PIN_3		3
#define DIO_uint8_PIN_4		4
#define DIO_uint8_PIN_5		5
#define DIO_uint8_PIN_6		6
#define DIO_uint8_PIN_7		7
#define DIO_uint8_PIN_8		8
#define DIO_uint8_PIN_9		9
#define DIO_uint8_PIN_10	10
#define DIO_uint8_PIN_11	11
#define DIO_uint8_PIN_12	12
#define DIO_uint8_PIN_13	13
#define DIO_uint8_PIN_14	14
#define DIO_uint8_PIN_15	15
#define DIO_uint8_PIN_16	16
#define DIO_uint8_PIN_17	17
#define DIO_uint8_PIN_18	18
#define DIO_uint8_PIN_19	19
#define DIO_uint8_PIN_20	20
#define DIO_uint8_PIN_21	21
#define DIO_uint8_PIN_22	22
#define DIO_uint8_PIN_23	23
#define DIO_uint8_PIN_24	24
#define DIO_uint8_PIN_25	25
#define DIO_uint8_PIN_26	26
#define DIO_uint8_PIN_27	27
#define DIO_uint8_PIN_28	28
#define DIO_uint8_PIN_29	29
#define DIO_uint8_PIN_30	30
#define DIO_uint8_PIN_31	31


#define DIO_uint8_HIGH		1
#define DIO_uint8_LOW 		0


void DIO_vid_Init(void);

void DIO_vid_SetPinValue(uint8 Copy_uint8_PinNo , uint8 Copy_uint8_Value);

uint8 DIO_uint8_GetPinValue(uint8 Copy_uint8_PinNo);

#endif /* DIO_INT_H_ */
