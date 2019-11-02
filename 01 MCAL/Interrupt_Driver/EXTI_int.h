#ifndef _EXTI_INT_H_

#define _EXTI_INT_H_


void EXTI_voidInit(void);

void EXTI_voidSetCallBack(void (*Copy_ptr) (void));

void EXTI_voidEnable(void);

void EXTI_voidDisable(void);

void EXTI_GIE_Enable(void);

void EXTI_GIE_Disable(void);

#endif
