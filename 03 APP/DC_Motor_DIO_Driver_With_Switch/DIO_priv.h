
#ifndef DIO_PRIV_H_
#define DIO_PRIV_H_

#define DDRA    (*((volatile uint8 *)0x3A))
#define DDRB    (*((volatile uint8 *)0x37))
#define DDRC    (*((volatile uint8 *)0x34))
#define DDRD    (*((volatile uint8 *)0x31))

#define PORTA   (*((volatile uint8 *)0x3B))
#define PORTB   (*((volatile uint8 *)0x38))
#define PORTC   (*((volatile uint8 *)0x35))
#define PORTD   (*((volatile uint8 *)0x32))

#define PINA    (*((volatile uint8 *)0x39))
#define PINB    (*((volatile uint8 *)0x36))
#define PINC    (*((volatile uint8 *)0x33))
#define PIND    (*((volatile uint8 *)0x30))


#define DIO_uint8_PORTA_DIRECTION  CONC_BIT(DIO_uint8_DIR_PIN_7 , DIO_uint8_DIR_PIN_6 , DIO_uint8_DIR_PIN_5 , DIO_uint8_DIR_PIN_4 , DIO_uint8_DIR_PIN_3 , DIO_uint8_DIR_PIN_2 , DIO_uint8_DIR_PIN_1 , DIO_uint8_DIR_PIN_0)
#define DIO_uint8_PORTB_DIRECTION  CONC_BIT(DIO_uint8_DIR_PIN_15 , DIO_uint8_DIR_PIN_14 , DIO_uint8_DIR_PIN_13 , DIO_uint8_DIR_PIN_12 , DIO_uint8_DIR_PIN_11 , DIO_uint8_DIR_PIN_10 , DIO_uint8_DIR_PIN_9 , DIO_uint8_DIR_PIN_8)
#define DIO_uint8_PORTC_DIRECTION  CONC_BIT(DIO_uint8_DIR_PIN_23 , DIO_uint8_DIR_PIN_22 , DIO_uint8_DIR_PIN_21 , DIO_uint8_DIR_PIN_20 , DIO_uint8_DIR_PIN_19 , DIO_uint8_DIR_PIN_18 , DIO_uint8_DIR_PIN_17 , DIO_uint8_DIR_PIN_16)
#define DIO_uint8_PORTD_DIRECTION  CONC_BIT(DIO_uint8_DIR_PIN_31 , DIO_uint8_DIR_PIN_30 , DIO_uint8_DIR_PIN_29 , DIO_uint8_DIR_PIN_28 , DIO_uint8_DIR_PIN_27 , DIO_uint8_DIR_PIN_26 , DIO_uint8_DIR_PIN_25 , DIO_uint8_DIR_PIN_24)

#define DIO_uint8_PORTA_START		0
#define DIO_uint8_PORTA_END		    7
#define DIO_uint8_PORTA_SIZE		8

#define DIO_uint8_PORTB_START		8
#define DIO_uint8_PORTB_END		    15
#define DIO_uint8_PORTB_SIZE		8

#define DIO_uint8_PORTC_START		16
#define DIO_uint8_PORTC_END		    23
#define DIO_uint8_PORTC_SIZE		8

#define DIO_uint8_PORTD_START		24
#define DIO_uint8_PORTD_END		    31
#define DIO_uint8_PORTD_SIZE		8

#define DIO_uint8_OUTPUT  1
#define DIO_uint8_INPUT  0



#endif /* DIO_PRIV_H_ */
