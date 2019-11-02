/*
 * Author : Ahmed Kilany
 * Description : interface file of ADC module
 *
 */


#ifndef ADC_INT_H_
#define ADC_INT_H_

#define NOK 0
#define OK 1



void ADC_voidInit(void);

void ADC_voidEnableInt(void);

void ADC_voidDisableInt(void);

void ADC_voidSetCallBack( void (*Copy_Ptr) (void) );

void ADC_voidEnableADC(void);

void ADC_voidDisableADC(void);

#if ADC_Mode == Eight_Bit_Mode
uint8 ADC_uint8GetConversionValue(uint8 Channel, uint8 * Result);
uint8 ADC_uint8GetLastValue(void);

#else
uint16 ADC_uint16GetConversionValue(uint8 Channel, uint16 * Result);
uint16 ADC_uint16GetLastValue(void) ;

#endif





#endif
