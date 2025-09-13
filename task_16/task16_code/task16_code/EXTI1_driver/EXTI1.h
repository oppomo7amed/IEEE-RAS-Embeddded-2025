#ifndef EXTI1_H_
#define EXTI1_H_

#include "../utilities/STD_TYPES.h"

/* Sense control options (same as EXTI0) */
#define EXTI_LOW_LEVEL     0
#define EXTI_ANY_CHANGE    1
#define EXTI_FALLING_EDGE  2
#define EXTI_RISING_EDGE   3

/* API */
void EXTI1_voidInit      (u8 Copy_u8SenseMode);
void EXTI1_voidEnable    (void);
void EXTI1_voidDisable   (void);
void EXTI1_voidSetCallBack(void (*pf)(void));

#endif /* EXTI1_H_ */
