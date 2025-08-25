#include "seg7.h"
extern "C" {
  #include <util/delay.h>
}


// Segment patterns for 0-9 (assuming common anode)
uint8_t digit_patterns[10] = {
    0b11000000, // 0
    0b11111001, // 1
    0b10100100, // 2
    0b10110000, // 3
    0b10011001, // 4
    0b10010010, // 5
    0b10000010, // 6
    0b11111000, // 7
    0b10000000, // 8
    0b10010000  // 9
};

void SEG7_Init(void) {
    DDRD = 0xFF;   // PORTD → output for segments
    DDRB |= (1<<PB0) | (1<<PB1); // Digit control pins
}

void SEG7_DisplayNumber(uint8_t num) {
    uint8_t tens = num / 10;
    uint8_t ones = num % 10;

    // Show tens
    PORTD = digit_patterns[tens];
    PORTB |= (1<<PB0);
    _delay_ms(5);
    PORTB &= ~(1<<PB0);

    // Show ones
    PORTD = digit_patterns[ones];
    PORTB |= (1<<PB1);
    _delay_ms(5);
    PORTB &= ~(1<<PB1);
}
