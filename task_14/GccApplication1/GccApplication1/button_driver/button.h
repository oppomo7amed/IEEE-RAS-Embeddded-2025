/*
 * button.h
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include "../DIO_driver/dio.h"

#define STOP_BUTTON_PORT PORT_A
#define STOP_BUTTON_PIN  0

#define FORWARD_BUTTON_PORT PORT_A
#define FORWARD_BUTTON_PIN 1

#define BACKWARD_BUTTON_PORT PORT_A 
#define BACKWARD_BUTTON_PIN 2

#define LEFT_BUTTON_PORT PORT_A 
#define LEFT_BUTTON_PIN 3

#define RIGHT_BUTTON_PORT PORT_A
#define RIGHT_BUTTON_PIN 4



void BUTTON_INIT(uint8_t port , uint8_t pinnumber);

void BUTTON_READ(uint8_t port , uint8_t pinnumber, uint8_t *value);

#endif /* BUTTON_H_ */