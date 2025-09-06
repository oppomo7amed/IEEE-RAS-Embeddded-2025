/*
 * GccApplication1.c
 */ 


#include "button_driver/button.h"
#include "DIO_driver/dio.h"
#include "Motor_driver/motor.h"

int main(void)
{
	
     uint8_t value = 0;

    // Init motors
    Motor_init();

    // Init all buttons
    BUTTON_INIT(STOP_BUTTON_PORT, STOP_BUTTON_PIN);
    BUTTON_INIT(FORWARD_BUTTON_PORT, FORWARD_BUTTON_PIN);
    BUTTON_INIT(BACKWARD_BUTTON_PORT, BACKWARD_BUTTON_PIN);
    BUTTON_INIT(LEFT_BUTTON_PORT, LEFT_BUTTON_PIN);
    BUTTON_INIT(RIGHT_BUTTON_PORT, RIGHT_BUTTON_PIN);

    /* Replace with your application code */
    while (1) 
    { 
		        BUTTON_READ(STOP_BUTTON_PORT, STOP_BUTTON_PIN, &value);
		        if(value == 0) { Motor_stop(); continue; }

		        BUTTON_READ(FORWARD_BUTTON_PORT, FORWARD_BUTTON_PIN, &value);
		        if(value == 0) { Motor_set(MOTOR_FORWARD); continue; }

		        BUTTON_READ(BACKWARD_BUTTON_PORT, BACKWARD_BUTTON_PIN, &value);
		        if(value == 0) { Motor_set(MOTOR_BACKWARD); continue; }

		        BUTTON_READ(LEFT_BUTTON_PORT, LEFT_BUTTON_PIN, &value);
		        if(value == 0) { Motor_set(MOTOR_TURN_LEFT); continue; }

		        BUTTON_READ(RIGHT_BUTTON_PORT, RIGHT_BUTTON_PIN, &value);
		        if(value == 0) { Motor_set(MOTOR_TURN_RIGHT); continue; }
	       
				}
				}

