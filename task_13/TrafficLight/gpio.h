#ifndef GPIO_H
#define GPIO_H

#include <avr/io.h>

#define OUTPUT 1
#define INPUT  0

void GPIO_SetPinDirection(volatile uint8_t *ddr, uint8_t pin, uint8_t dir);
void GPIO_WritePin(volatile uint8_t *port, uint8_t pin, uint8_t value);

#endif
