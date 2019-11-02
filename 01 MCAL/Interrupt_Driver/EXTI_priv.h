#ifndef _EXTI_PRIV_H_
#define _EXTI_PRIV_H_


#define SREG 	(*((volatile uint8 *)0x5F ) )
#define GICR 	(*((volatile uint8 *)0x5B ) )
#define GIFR 	(*((volatile uint8 *)0x5A ) )
#define MCUCSR 	(*((volatile uint8 *)0x54 ) )
#define MCUCR 	(*((volatile uint8 *)0x55 ) )

#define EXTI_uint8_LOW_LEVEL		 	0
#define EXTI_uint8_IOC						 	 	1
#define EXTI_uint8_RISING_EDGE 		2
#define EXTI_uint8_FALLING_EDGE 	3

#define EXTI_INT0  	6
#define ISC0 				0
#define ISC1 					1


#endif



