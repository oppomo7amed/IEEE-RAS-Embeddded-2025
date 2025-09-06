

#include "motor.h"

void Motor_init(){
	DIO_init(L_IN1_PORT, L_IN1_PIN, OUTPUT);
	DIO_init(L_IN2_PORT, L_IN2_PIN, OUTPUT);
	DIO_init(R_IN1_PORT, R_IN1_PIN, OUTPUT);
	DIO_init(R_IN2_PORT, R_IN2_PIN, OUTPUT);
	Motor_stop();
}

void Motor_set(motor_state_t state) {
    switch(state){
	    case MOTOR_FORWARD:    Motor_forward();    break;
	    case MOTOR_BACKWARD:   Motor_backward();   break;
		case MOTOR_TURN_LEFT:  Motor_turn_left();  break;
		case MOTOR_TURN_RIGHT: Motor_turn_right(); break;
		default:               Motor_stop();       break;
		}
}
void Motor_stop(){
	 DIO_write(L_IN1_PORT, L_IN1_PIN, LOW);
	 DIO_write(L_IN2_PORT, L_IN2_PIN, LOW);
	 DIO_write(R_IN1_PORT, R_IN1_PIN, LOW);
	 DIO_write(R_IN2_PORT, R_IN2_PIN, LOW);
}
void Motor_forward(){
	 DIO_write(L_IN1_PORT, L_IN1_PIN, HIGH);
	 DIO_write(L_IN2_PORT, L_IN2_PIN, LOW);
	 DIO_write(R_IN1_PORT, R_IN1_PIN, HIGH);
	 DIO_write(R_IN2_PORT, R_IN2_PIN, LOW);
}

void Motor_backward(){
	 DIO_write(L_IN1_PORT, L_IN1_PIN, LOW);
	 DIO_write(L_IN2_PORT, L_IN2_PIN, HIGH);
	 DIO_write(R_IN1_PORT, R_IN1_PIN, LOW);
	 DIO_write(R_IN2_PORT, R_IN2_PIN, HIGH);
	
}

void Motor_turn_left(){
	 DIO_write(L_IN1_PORT, L_IN1_PIN, LOW);
	 DIO_write(L_IN2_PORT, L_IN2_PIN, LOW);
	 DIO_write(R_IN1_PORT, R_IN1_PIN, HIGH);
	 DIO_write(R_IN2_PORT, R_IN2_PIN, LOW);
	
}
void Motor_turn_right(){
	DIO_write(L_IN1_PORT, L_IN1_PIN, HIGH);
	DIO_write(L_IN2_PORT, L_IN2_PIN, LOW);
	DIO_write(R_IN1_PORT, R_IN1_PIN, LOW);
	DIO_write(R_IN2_PORT, R_IN2_PIN, LOW);

}
