/*
 * bit_manipulation.h
 *
 */ 


#ifndef BIT_MANIPULATION_H_
#define BIT_MANIPULATION_H_


  // -------------------------------
  // Bit Manipulation Macros
  // -------------------------------
  #define SET_BIT(REG, BIT)     ((REG) |=  (1 << (BIT)))   // set bit to 1
  #define CLEAR_BIT(REG, BIT)   ((REG) &= ~(1 << (BIT)))   // clear bit to 0
  #define TOGGLE_BIT(REG, BIT)  ((REG) ^=  (1 << (BIT)))   // flip bit
  #define READ_BIT(REG, BIT)    (((REG) >> (BIT)) & 0x01)  // read single bit

  // -------------------------------
  // Direction Macros
  // -------------------------------
  #define INPUT   0
  #define OUTPUT  1

  // -------------------------------
  // Pin Value Macros
  // -------------------------------
  #define LOW     0
  #define HIGH    1


#endif /* BIT_MANIPULATION_H_ */