/*
 * button.c
 */ 


#include "button.h"

void BUTTON_INIT(uint8_t port , uint8_t pinnumber)//BUTTON IS INPUT 
{
	DIO_init(port,pinnumber,INPUT);
	DIO_write(port,pinnumber,HIGH);
}

void BUTTON_READ(uint8_t port , uint8_t pinnumber  , uint8_t *value)
{
	DIO_read(port,pinnumber,value);
}