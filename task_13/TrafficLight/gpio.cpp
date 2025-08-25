#include "gpio.h"

void GPIO_SetPinDirection(volatile uint8_t *ddr, uint8_t pin, uint8_t dir) {
    if(dir == OUTPUT) (*ddr) |= (1 << pin);
    else (*ddr) &= ~(1 << pin);
}

void GPIO_WritePin(volatile uint8_t *port, uint8_t pin, uint8_t value) {
    if(value) (*port) |= (1 << pin);
    else (*port) &= ~(1 << pin);
}
