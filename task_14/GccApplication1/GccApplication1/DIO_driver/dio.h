/*
 * dio.h
 *
 */ 


#ifndef DIO_H_
#define DIO_H_

 #include "../utilities/types.h"
 #include "../utilities/bit_manipulation.h"
 #include "../utilities/registers.h"
 
 void DIO_init(uint8_t port , uint8_t pinnumber , uint8_t direction );
  
 void DIO_write(uint8_t port , uint8_t pinnumber , uint8_t value);

 void DIO_read(uint8_t port , uint8_t pinnumber , uint8_t *value);



#endif /* DIO_H_ */