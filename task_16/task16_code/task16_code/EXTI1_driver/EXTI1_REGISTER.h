#ifndef EXTI1_REGISTER_H_
#define EXTI1_REGISTER_H_

#include "../utilities/STD_TYPES.h"

/* We reuse same register definitions as EXTI0_REGISTER for convenience */
#define MCUCR   *((volatile u8*)0x55)
#define MCUCSR  *((volatile u8*)0x54)
#define GICR    *((volatile u8*)0x5B)
#define GIFR    *((volatile u8*)0x5A)
#define SREG    *((volatile u8*)0x5F)

#endif /* EXTI1_REGISTER_H_ */
