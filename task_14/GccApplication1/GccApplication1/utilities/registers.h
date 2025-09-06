/*
 * registers.h
 */ 


#ifndef REGISTERS_H_
#define REGISTERS_H_

 #include "types.h"
 
 
 #define  PORT_A 'A'
 #define  PORT_B 'B'
 #define  PORT_C 'C'
 #define  PORT_D 'D'
 
 
   //PORTA REGISTERS
   #define PORTA  *((volatile uint8_t*)0x3B) 
   #define DDRA   *((volatile uint8_t*) 0X3A)
   #define PINA   *((volatile uint8_t *)0x39)
 
   // PORTB REGISTERS
   #define PORTB  *((volatile uint8_t*)0x38)
   #define DDRB   *((volatile uint8_t*) 0X37)
   #define PINB   *((volatile uint8_t *)0x36)
  
   // PORTC REGISTERS
   #define PORTC  *((volatile uint8_t*)0x35)
   #define DDRC   *((volatile uint8_t*) 0X34)
   #define PINC   *((volatile uint8_t *)0x33)
   
   // PORTA REGISTERS
   #define PORTD  *((volatile uint8_t*)0x32)
   #define DDRD   *((volatile uint8_t*) 0X31)
   #define PIND   *((volatile uint8_t *)0x30)

#endif /* REGISTERS_H_ */