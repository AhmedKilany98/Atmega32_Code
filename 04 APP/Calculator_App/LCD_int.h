/*
 * LCD_int.h
 *
 *  Created on: Dec 28, 2018
 *      Author: Mohamed Sobhy
 */

#ifndef LCD_INT_H_
#define LCD_INT_H_


void LCD_vidInit(void);

void LCD_vidWriteCharacter(uint8 Copy_uint8data);

void LCD_vidWriteCommand(uint8 Copy_uint8cmd);

void LCD_vidWriteString(uint8 * Copy_pString);

void LCD_vidGoToRowCol(uint8 Copy_uint8Row , uint8 Copy_uint8Col );

void LCD_vidClearScreen(void);

#endif /* LCD_INT_H_ */
