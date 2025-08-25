#ifndef LED_H
#define LED_H

#include "gpio.h"

// LED Pin Definitions
#define RED_LED_PIN    PC0
#define YELLOW_LED_PIN PC1
#define GREEN_LED_PIN  PC2

void LED_Init(void);
void LED_On(uint8_t pin);
void LED_Off(uint8_t pin);

#endif
