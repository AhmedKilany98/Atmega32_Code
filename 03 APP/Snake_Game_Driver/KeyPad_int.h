/*
 * KeyPad_int.h
 *
 *  Created on: Dec 29, 2018
 *      Author: Mohamed Sobhy
 */

#ifndef KEYPAD_INT_H_
#define KEYPAD_INT_H_

/* Connect pull up resistor or not */
void KeyPad_voidInit(void);

/*This function shall return 16 bit variable
		indicating the status of each key */

uint16 KeyPad_uint16GetStatus(void);

#endif /* KEYPAD_INT_H_ */
