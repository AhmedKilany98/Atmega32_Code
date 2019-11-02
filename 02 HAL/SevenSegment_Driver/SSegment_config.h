/*
 * SSegment_config.h
 *
 *  Created on: Feb 21, 2018
 *      Author: Mohamed Sobhy
 */

#ifndef SSEGMENT_CONFIG_H_
#define SSEGMENT_CONFIG_H_

/* Seven segment one connected to port A and is far away from the LCD */
#define FIRST_SEGMENT

#ifdef FIRST_SEGMENT

#define SSEGMENT_ONE_PIN_A	DIO_uint8_PIN_0
#define SSEGMENT_ONE_PIN_B  DIO_uint8_PIN_1
#define SSEGMENT_ONE_PIN_C	DIO_uint8_PIN_2
#define SSEGMENT_ONE_PIN_D	DIO_uint8_PIN_3
#define SSEGMENT_ONE_PIN_E	DIO_uint8_PIN_4
#define SSEGMENT_ONE_PIN_F	DIO_uint8_PIN_5
#define SSEGMENT_ONE_PIN_G	DIO_uint8_PIN_6



#endif


/* Seven segment two connected to port B and is near from the LCD */

#define SECOND_SEGMENT

#ifdef SECOND_SEGMENT

#define SSEGMENT_TWO_PIN_A	DIO_uint8_PIN_8
#define SSEGMENT_TWO_PIN_B  DIO_uint8_PIN_9
#define SSEGMENT_TWO_PIN_C	DIO_uint8_PIN_10
#define SSEGMENT_TWO_PIN_D	DIO_uint8_PIN_11
#define SSEGMENT_TWO_PIN_E	DIO_uint8_PIN_12
#define SSEGMENT_TWO_PIN_F	DIO_uint8_PIN_13
#define SSEGMENT_TWO_PIN_G	DIO_uint8_PIN_14



#endif











#endif /* SSEGMENT_CONFIG_H_ */
