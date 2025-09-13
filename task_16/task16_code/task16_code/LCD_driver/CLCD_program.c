
/***************************************************************************************/
#define F_CPU 8000000UL
#include <util/delay.h>

#include "../utilities/STD_TYPES.h"
#include "../utilities/BIT_MATH.h"

#include "../DIO_DRIVER/DIO_interface.h"

#include "CLCD_interface.h"
#include "CLCD_private.h"
#include "CLCD_config.h"


/***************************************************************************************/

/*

###########  8 Bits Mode
 -----------                   ----------
 | ATmega32  |                 |   LCD    |
 |           |                 |          |
 |        PA7|---------------->|D7        |
 |        PA6|---------------->|D6        |
 |        PA5|---------------->|D5        |
 |        PA4|---------------->|D4        |
 |        PA3|---------------->|D3        |
 |        PA2|---------------->|D2        |
 |        PA1|---------------->|D1        |
 |        PA0|---------------->|D0        |
 |           |                 |          |
 |        PC2|---------------->|E         |
 |        PC1|---------------->|RW        |
 |        PC0|---------------->|RS        |
 -----------                   ----------
 */
/***************************************************************************************/


//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
* Breif : This Function Apply initialization sequence for LCD module
* Parameters : nothing
* return : nothing 
*/
void CLCD_voidInit        ( void ){

	
	
	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<      8 Bits Mode       >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	
	#if   CLCD_MODE == 8
	
	// 1- must wait more than 30 ms before any action (VDD rises to 4.5 v)
	_delay_ms(50);
	
	// All Pins as OutPut pins
	DIO_enumSetPortDirection ( CLCD_DATA_PORT    , DIO_PORT_OUTPUT           );
	DIO_enumSetPinDirection  ( CLCD_CONTROL_PORT , CLCD_RS , DIO_PIN_OUTPUT  );
	DIO_enumSetPinDirection  ( CLCD_CONTROL_PORT , CLCD_RW , DIO_PIN_OUTPUT  );
	DIO_enumSetPinDirection  ( CLCD_CONTROL_PORT , CLCD_EN , DIO_PIN_OUTPUT  );
	
	/* Return cursor to the first position on the first line  */
	CLCD_voidSendCommand(lcd_Home);
	_delay_ms(1);
	
	/*FUNCTION SET Command : 2 lines , 5*8 font size */
	CLCD_voidSendCommand( EIGHT_BITS ); // 8 Bit Mode ==> 0x38
	_delay_ms(1); // wait more than 39 Ms
	
	/* DISPLAY & Cursor (ON / OFF) Control */
	CLCD_voidSendCommand( lcd_DisplayOn_CursorOff );
	_delay_ms(1);
	
	/* DISPLAY CLEAR */
	CLCD_voidClearScreen();
	
	/* ENTRY MODE  SET*/
	CLCD_voidSendCommand( lcd_EntryMode );
	_delay_ms(1);
	
	
	
	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<      4 Bits Mode       >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

	#elif   CLCD_MODE == 4
	
	DIO_enumSetPinDirection      (CLCD_DATA_PORT,DIO_PIN4,DIO_PIN_OUTPUT);
	DIO_enumSetPinDirection      (CLCD_DATA_PORT,DIO_PIN5,DIO_PIN_OUTPUT);
	DIO_enumSetPinDirection      (CLCD_DATA_PORT,DIO_PIN6,DIO_PIN_OUTPUT);
	DIO_enumSetPinDirection      (CLCD_DATA_PORT,DIO_PIN7,DIO_PIN_OUTPUT);
	DIO_enumSetPinDirection  ( CLCD_CONTROL_PORT , CLCD_RS , DIO_PIN_OUTPUT  );
	DIO_enumSetPinDirection  ( CLCD_CONTROL_PORT , CLCD_RW , DIO_PIN_OUTPUT  );
	DIO_enumSetPinDirection  ( CLCD_CONTROL_PORT , CLCD_EN , DIO_PIN_OUTPUT  );
	_delay_ms(50);
	
	 
	/*return home*/
	CLCD_voidSendCommand( lcd_Home ); 
	_delay_ms(10);
	
	/*FUNCTION SET Command*/
	CLCD_voidSendCommand( FOUR_BITS ); // 4 Bit Mode
	_delay_ms(1);
	
	/* DISPLAY & Cursor (ON / OFF) Control */
	CLCD_voidSendCommand( lcd_DisplayOn_CursorOff );
	_delay_ms(1);
	
	/* DISPLAY CLEAR */
	CLCD_voidClearScreen();
	
	/* ENTRY MODE  Set*/
	CLCD_voidSendCommand( lcd_EntryMode );
	_delay_ms(1);
	
	
	#endif


	

}

//----------------------------------------------------------------------------------------------------------------------------------------------------

void CLCD_voidSendData    ( u8 Copy_u8Data ){

	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<      8 Bits Mode       >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	#if   CLCD_MODE == 8

	DIO_enumSetPortValue ( CLCD_DATA_PORT    , Copy_u8Data        );
	DIO_enumSetPinValue  ( CLCD_CONTROL_PORT , CLCD_RS , DIO_PIN_HIGH );
	DIO_enumSetPinValue  ( CLCD_CONTROL_PORT , CLCD_RW , DIO_PIN_LOW  );
	CLCD_voidSendFallingEdge();
	
	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<      4 Bits Mode       >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	#elif   CLCD_MODE == 4

	DIO_voidWriteHighNibbles (CLCD_DATA_PORT ,Copy_u8Data>>4);            // send the most 4 bits of data to high nibbles
	DIO_enumSetPinValue  ( CLCD_CONTROL_PORT , CLCD_RS , DIO_PIN_HIGH );
	DIO_enumSetPinValue  ( CLCD_CONTROL_PORT , CLCD_RW , DIO_PIN_LOW  );
	CLCD_voidSendFallingEdge();
	DIO_voidWriteHighNibbles (CLCD_DATA_PORT ,Copy_u8Data);               // send the least 4 bits of data to high nibbles
	DIO_enumSetPinValue  ( CLCD_CONTROL_PORT , CLCD_RS , DIO_PIN_HIGH );
	DIO_enumSetPinValue  ( CLCD_CONTROL_PORT , CLCD_RW , DIO_PIN_LOW  );
	CLCD_voidSendFallingEdge();
	
	#endif
	
	_delay_ms(1);

}

//----------------------------------------------------------------------------------------------------------------------------------------------------

void CLCD_voidSendCommand ( u8 Copy_u8Command ){

	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<      8 Bits Mode       >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	#if   CLCD_MODE == 8

	DIO_enumSetPortValue ( CLCD_DATA_PORT    , Copy_u8Command     );
	DIO_enumSetPinValue  ( CLCD_CONTROL_PORT , CLCD_RS , DIO_PIN_LOW  );
	// RW always connect to GND to Write
	DIO_enumSetPinValue          (CLCD_CONTROL_PORT,CLCD_RW , DIO_PIN_LOW    );
	CLCD_voidSendFallingEdge();

	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<      4 Bits Mode       >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	#elif   CLCD_MODE == 4	
	
	DIO_voidWriteHighNibbles (CLCD_DATA_PORT ,Copy_u8Command>>4);             // send the most 4 bits of data to high nibbles
	DIO_enumSetPinValue  ( CLCD_CONTROL_PORT , CLCD_RS , DIO_PIN_LOW  );
	DIO_enumSetPinValue  ( CLCD_CONTROL_PORT , CLCD_RW , DIO_PIN_LOW  );
	CLCD_voidSendFallingEdge();
	DIO_voidWriteHighNibbles (CLCD_DATA_PORT ,Copy_u8Command);                // send the least 4 bits of data to high nibbles
	DIO_enumSetPinValue  ( CLCD_CONTROL_PORT , CLCD_RS , DIO_PIN_LOW  );
	DIO_enumSetPinValue  ( CLCD_CONTROL_PORT , CLCD_RW , DIO_PIN_LOW  );
	CLCD_voidSendFallingEdge();
	
	#endif
	
	_delay_ms(1);

}

//----------------------------------------------------------------------------------------------------------------------------------------------------

void CLCD_voidSendString  ( const u8 * Copy_u8ptrString ){

	u8 LOC_u8Iterator = 0 ;

	while( Copy_u8ptrString[LOC_u8Iterator] != '\0' ){

		CLCD_voidSendData( Copy_u8ptrString[LOC_u8Iterator] );
		LOC_u8Iterator++ ;

	}
	
}


void CLCD_voidSendNumber   ( u64 Copy_u64Number    ){

	u64 LOC_u64Reversed = 1 ;

	if( Copy_u64Number == 0 ){ CLCD_voidSendData('0'); }

	else{

		while( Copy_u64Number != 0 ){

			LOC_u64Reversed = ( LOC_u64Reversed * 10 ) + ( Copy_u64Number % 10 );
			Copy_u64Number /= 10 ;

		}
		while( LOC_u64Reversed != 1 ){

			CLCD_voidSendData( ( LOC_u64Reversed % 10 ) + 48 );
			LOC_u64Reversed /= 10 ;

		}

	}

}

//----------------------------------------------------------------------------------------------------------------------------------------------------

void CLCD_voidSetPosition ( u8 Copy_u8Row , u8 Copy_u8Col ){

	u8 LOC_u8data ;
	
	/* In These cases will set at (0,0) ==> if the user enter invalid location */
	if(Copy_u8Row>2||Copy_u8Row<1||Copy_u8Col>16||Copy_u8Col<1)  //check
	{
		LOC_u8data = lcd_SetCursor ;   // first location 
	}
	
	else if( Copy_u8Row == CLCD_ROW_1 ){

		LOC_u8data = ( ( lcd_SetCursor ) + ( Copy_u8Col - 1 ) );              //Row1 -> 0x80+col-1

	}
	
	else if( Copy_u8Row == CLCD_ROW_2 ){

		LOC_u8data = ( ( lcd_SetCursor ) + (64) + ( Copy_u8Col - 1 ) );       //Row2 -> 0xc0+col-1

	}
	CLCD_voidSendCommand ( LOC_u8data );
	_delay_ms(1);

}


//----------------------------------------------------------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------------------------------------------------------

void CLCD_voidClearScreen(void)
{
	CLCD_voidSendCommand(lcd_Clear);
	_delay_ms(10); //wait more than 1.53 ms
}

//----------------------------------------------------------------------------------------------------------------------------------------------------

static void CLCD_voidSendFallingEdge(void)
{
	DIO_enumSetPinValue  ( CLCD_CONTROL_PORT , CLCD_EN , DIO_PIN_HIGH );
	_delay_ms(1);
	DIO_enumSetPinValue  ( CLCD_CONTROL_PORT , CLCD_EN , DIO_PIN_LOW  );
	_delay_ms(1);
}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    END    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

