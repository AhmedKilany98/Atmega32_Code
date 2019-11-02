/*
 * LCD_config.h
 */

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

#define LCD_uint8_PIN_RS    DIO_uint8_PIN_8
#define LCD_uint8_PIN_RW    DIO_uint8_PIN_9
#define LCD_uint8_PIN_E     DIO_uint8_PIN_10

#define LCD_uint8_PIN_D0 	DIO_uint8_PIN_24
#define LCD_uint8_PIN_D1    DIO_uint8_PIN_25
#define LCD_uint8_PIN_D2    DIO_uint8_PIN_26
#define LCD_uint8_PIN_D3    DIO_uint8_PIN_27
#define LCD_uint8_PIN_D4    DIO_uint8_PIN_28
#define LCD_uint8_PIN_D5    DIO_uint8_PIN_29
#define LCD_uint8_PIN_D6    DIO_uint8_PIN_30
#define LCD_uint8_PIN_D7    DIO_uint8_PIN_31


/* LCD_MODE = LCD_uint8_4BitMode OR  LCD_uint8_8BitMode
 * #define LCD_MODE		LCD_uint8_8BitMode
* #define LCD_MODE		LCD_uint8_4BitMode
 * */

#define LCD_MODE		LCD_uint8_4BitMode



#endif /* LCD_CONFIG_H_ */
