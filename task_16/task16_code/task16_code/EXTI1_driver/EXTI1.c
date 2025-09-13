#include "EXTI1.h"
#include "EXTI1_REGISTER.h"
#include "../utilities/BIT_MATH.h"
#include <avr/interrupt.h>

static void (*EXTI1_PfCallback)(void) = 0;

void EXTI1_voidInit(u8 Copy_u8SenseMode)
{
	/* ISC11 ISC10 bits are MCUCR bits 3:2 */
	MCUCR &= ~( (1<<ISC10) | (1<<ISC11) );
	switch(Copy_u8SenseMode)
	{
		case EXTI_LOW_LEVEL:    break;
		case EXTI_ANY_CHANGE:   MCUCR |= (1<<ISC10); break; /* 01 */
		case EXTI_FALLING_EDGE: MCUCR |= (1<<ISC11); break; /* 10 */
		case EXTI_RISING_EDGE:  MCUCR |= (1<<ISC11)|(1<<ISC10); break; /* 11 */
		default: MCUCR |= (1<<ISC11); break;
	}
	/* clear pending flag */
	GIFR |= (1<<INTF1);
}

void EXTI1_voidEnable(void)
{
	GICR |= (1<<INT1);
	sei();
}

void EXTI1_voidDisable(void)
{
	GICR &= ~(1<<INT1);
}

void EXTI1_voidSetCallBack(void (*pf)(void))
{
	EXTI1_PfCallback = pf;
}

ISR(INT1_vect)
{
	if (EXTI1_PfCallback) EXTI1_PfCallback();
}
