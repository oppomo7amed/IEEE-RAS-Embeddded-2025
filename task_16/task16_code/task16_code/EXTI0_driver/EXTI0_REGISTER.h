#ifndef EXTI0_REGISTER_H_
#define EXTI0_REGISTER_H_

#include "../utilities/STD_TYPES.h"

/* ATmega32 I/O register addresses (I/O space 0x20..0x5F) */
#define MCUCR   *((volatile u8*)0x55)   /* MCU Control Register (ISC01,ISC00...) */
#define MCUCSR  *((volatile u8*)0x54)   /* MCU Control and Status Register (for INT2) */
#define GICR    *((volatile u8*)0x5B)   /* General Interrupt Control Register (INT0/1/2 enable) */
#define GIFR    *((volatile u8*)0x5A)   /* General Interrupt Flag Register (INT0/1/2 flags) */
#define SREG    *((volatile u8*)0x5F)   /* Status Register (I-bit is bit7) */

#endif /* EXTI0_REGISTER_H_ */
