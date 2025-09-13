#include "EXTI0.h"
#include "EXTI0_REGISTER.h"
#include "../utilities/BIT_MATH.h"
#include <avr/interrupt.h> /* for ISR macro and sei/cli */

/* Internal callback pointer */
static void (*EXTI0_PfCallback)(void) = 0;

/* Initialize sense control for INT0
   Expects one of EXTI_LOW_LEVEL, EXTI_ANY_CHANGE, EXTI_FALLING_EDGE, EXTI_RISING_EDGE
   This function DOES NOT set the GICR enable bit; call EXTI0_voidEnable() to enable.
*/
void EXTI0_voidInit(u8 Copy_u8SenseMode)
{
    /* clear ISC01, ISC00 bits (bits 1:0 in MCUCR) then set accordingly */
    MCUCR &= ~( (1<<ISC00) | (1<<ISC01) ); /* ISC00 = bit0, ISC01 = bit1 */
    switch(Copy_u8SenseMode)
    {
        case EXTI_LOW_LEVEL:    /* ISC01:0 = 00 */ break;
        case EXTI_ANY_CHANGE:   MCUCR |=  (1<<ISC00); break; /* 01 */
        case EXTI_FALLING_EDGE: MCUCR |=  (1<<ISC01); break; /* 10 */
        case EXTI_RISING_EDGE:  MCUCR |=  (1<<ISC01)|(1<<ISC00); break; /* 11 */
        default: /* invalid - default to falling */ MCUCR |= (1<<ISC01); break;
    }
    /* clear any pending flag */
    GIFR |= (1<<INTF0);
}

/* Enable/Disable INT0 in GICR */
void EXTI0_voidEnable(void)
{
    GICR |= (1<<INT0);
    sei(); /* ensure global interrupts enabled */
}

void EXTI0_voidDisable(void)
{
    GICR &= ~(1<<INT0);
}

/* register callback */
void EXTI0_voidSetCallBack(void (*pf)(void))
{
    EXTI0_PfCallback = pf;
}

/* ISR - calls user callback if registered */
ISR(INT0_vect)
{
    if (EXTI0_PfCallback) EXTI0_PfCallback();
}
