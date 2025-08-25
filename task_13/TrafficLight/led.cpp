#include "led.h"

void LED_Init(void) {
    GPIO_SetPinDirection(&DDRC, RED_LED_PIN, OUTPUT);
    GPIO_SetPinDirection(&DDRC, YELLOW_LED_PIN, OUTPUT);
    GPIO_SetPinDirection(&DDRC, GREEN_LED_PIN, OUTPUT);
}

void LED_On(uint8_t pin) { GPIO_WritePin(&PORTC, pin, 1); }
void LED_Off(uint8_t pin) { GPIO_WritePin(&PORTC, pin, 0); }
