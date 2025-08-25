#ifndef SEG7_H
#define SEG7_H

#include "gpio.h"

// Common Anode: 0 = ON, 1 = OFF
extern uint8_t digit_patterns[10];

void SEG7_Init(void);
void SEG7_DisplayNumber(uint8_t num);

#endif
