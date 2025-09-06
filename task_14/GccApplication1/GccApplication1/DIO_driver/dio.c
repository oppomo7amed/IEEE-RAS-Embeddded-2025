/*
 *
 *
 *
 */ 


#include "dio.h"

void DIO_init(uint8_t port , uint8_t pinnumber , uint8_t direction ){
	
	 switch(port) {
		 case PORT_A :
		      if (direction== OUTPUT) SET_BIT (DDRA,pinnumber);
		      else if ( direction == INPUT) CLEAR_BIT (DDRA , pinnumber);
		 break;
		case PORT_B :
			  if (direction== OUTPUT) SET_BIT (DDRB,pinnumber);
			  else if ( direction == INPUT) CLEAR_BIT (DDRB , pinnumber);
			  break;
		case PORT_C :
		      if (direction== OUTPUT) SET_BIT (DDRC,pinnumber);
		      else if ( direction == INPUT) CLEAR_BIT (DDRC, pinnumber);
		      break;  
	   case PORT_D :
	         if (direction== OUTPUT) SET_BIT (DDRD,pinnumber);
	         else if ( direction == INPUT) CLEAR_BIT (DDRD , pinnumber);
	         break; 
	 }
	
}




void DIO_write(uint8_t port , uint8_t pinnumber , uint8_t value){
	
      switch(port) {
	      case PORT_A :
	      if (value== HIGH) SET_BIT (PORTA,pinnumber);
	      else if ( value == LOW) CLEAR_BIT (PORTA , pinnumber);
	      break;
	      case PORT_B :
	      if (value== HIGH) SET_BIT (PORTB,pinnumber);
	      else if ( value == LOW) CLEAR_BIT (PORTB , pinnumber);
	      break;
	      case PORT_C :
	      if (value== HIGH) SET_BIT (PORTC,pinnumber);
	      else if ( value == LOW) CLEAR_BIT (PORTC, pinnumber);
	      break;
	      case PORT_D :
	      if (value== HIGH) SET_BIT (PORTD,pinnumber);
	      else if ( value == LOW) CLEAR_BIT (PORTD , pinnumber);
	      break;
      }
      	
}



void DIO_read(uint8_t port , uint8_t pinnumber , uint8_t *value){
	    switch (port) {
		    case PORT_A: *value = READ_BIT(PINA, pinnumber); break;
		    case PORT_B: *value = READ_BIT(PINB, pinnumber); break;
		    case PORT_C: *value = READ_BIT(PINC, pinnumber); break;
		    case PORT_D: *value = READ_BIT(PIND, pinnumber); break;
	    }
}



  