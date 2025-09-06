/*
 * motor.h
 */ 


#ifndef MOTOR_H_
#define MOTOR_H_

#include "../DIO_driver/dio.h"

// Motor pins (adjust if wiring differs)
#define L_IN1_PORT   PORT_D
#define L_IN1_PIN    2
#define L_IN2_PORT   PORT_D
#define L_IN2_PIN    3

#define R_IN1_PORT   PORT_D
#define R_IN1_PIN    4
#define R_IN2_PORT   PORT_D
#define R_IN2_PIN    5

typedef enum {
	MOTOR_STOP = 0,
	MOTOR_FORWARD,
	MOTOR_BACKWARD,
	MOTOR_TURN_LEFT,
	MOTOR_TURN_RIGHT
} motor_state_t;

void Motor_init();
void Motor_set(motor_state_t state);
void Motor_stop();
void Motor_forward();
void Motor_backward();
void Motor_turn_left();
void Motor_turn_right();


#endif /* MOTOR_H_ */