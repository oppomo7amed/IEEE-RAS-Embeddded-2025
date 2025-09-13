#define F_CPU 8000000UL
#include <util/delay.h>

#include "utilities/STD_TYPES.h"
#include "utilities/BIT_MATH.h"

#include "DIO_driver/DIO_interface.h"
#include "LCD_driver/CLCD_interface.h"

#include "EXTI0_driver/EXTI0.h"
#include "EXTI1_driver/EXTI1.h"

/* Seven-seg digit patterns for common cathode on PORTC (0..9)
   bit7..bit0 -> PC7..PC0; we use lower 7 bits (a..g).
   Modify this array if wiring differs.
*/
const u8 SevenSegDigits[10] = {
    0b00111111, /* 0 */
    0b00000110, /* 1 */
    0b01011011, /* 2 */
    0b01001111, /* 3 */
    0b01100110, /* 4 */
    0b01101101, /* 5 */
    0b01111101, /* 6 */
    0b00000111, /* 7 */
    0b01111111, /* 8 */
    0b01101111  /* 9 */
};

/* Shared state */
volatile u8 gCounter = 1;

/* ---------- Callbacks ---------- */
void ToggleLED_Callback(void)
{
    /* Toggle LED on PD0 */
    DIO_enumTogglePinValue(DIO_PORTB, DIO_PIN0);
}

void ResetCounter_Callback(void)
{
    /* Reset counter to 1 */
    gCounter = 0;
	
}

/* ---------- Main ---------- */
int main(void)
{
    u8 local_digit;

    /* --- LED --- */
    DIO_enumSetPinDirection(DIO_PORTB, DIO_PIN0, DIO_PIN_OUTPUT);
    DIO_enumSetPinValue(DIO_PORTB, DIO_PIN0, DIO_PIN_LOW);

    /* --- Buttons (INT0 -> PD2, INT1 -> PD3) --- */
    DIO_enumSetPinDirection(DIO_PORTD, DIO_PIN2, DIO_PIN_INPUT);
    DIO_enumSetPinDirection(DIO_PORTD, DIO_PIN3, DIO_PIN_INPUT);
    /* Enable internal pull-ups */
    DIO_enumConnectPullup(DIO_PORTD, DIO_PIN2, DIO_PIN_HIGH);
    DIO_enumConnectPullup(DIO_PORTD, DIO_PIN3, DIO_PIN_HIGH);

    /* --- Seven segment on PORTC --- */
    DIO_enumSetPortDirection(DIO_PORTC, DIO_PORT_OUTPUT);
    DIO_enumSetPortValue(DIO_PORTC, DIO_PORT_LOW);

    /* --- LCD --- */
    CLCD_voidInit();
    CLCD_voidClearScreen();
    CLCD_voidSetPosition(CLCD_ROW_1, CLCD_COL_1);
    CLCD_voidSendString((const u8*)"Counter:");

    /* --- External Interrupts --- */
    EXTI0_voidInit(EXTI_FALLING_EDGE);
    EXTI0_voidSetCallBack(ToggleLED_Callback);
    EXTI0_voidEnable();

    EXTI1_voidInit(EXTI_FALLING_EDGE);
    EXTI1_voidSetCallBack(ResetCounter_Callback);
    EXTI1_voidEnable();

    /* Main loop */
    while(1)
    {
        /* Keep counter in range */
        if (gCounter > 9) gCounter = 1;

        /* Display on 7-seg */
        local_digit = gCounter % 10;
        DIO_enumSetPortValue(DIO_PORTC, SevenSegDigits[local_digit]);

        /* Display on LCD (line 2) */
        CLCD_voidSetPosition(CLCD_ROW_2, CLCD_COL_1);
        CLCD_voidSendString((const u8*)"Value: ");
        CLCD_voidSendNumber((u64)gCounter);

        /* Wait (no timers) */
        _delay_ms(500);

        /* Increment */
        gCounter++;
        if (gCounter > 9) gCounter = 1;
    }

    return 0;
}
