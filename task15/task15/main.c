

#include "utilities/STD_TYPES.h"
#include "utilities/BIT_MATH.h"

#include "DIO_DRIVER/DIO_interface.h"
#include "LCD_DRIVER/CLCD_interface.h"
#include "KPD_DRIVER/KPD_interface.h"

#include <util/delay.h>

int main(void)
{
	/* Initialization */
	CLCD_voidInit();
	KPD_Init();

	u8 key;
	s32 operand1 = 0, operand2 = 0, result = 0;
	u8 operator = 0;
	u8 enteringSecondOperand = 0;

	CLCD_voidSendString((u8*)"Calculator ^__^");
	_delay_ms(1000);
	CLCD_voidClearScreen();

	while (1)
	{
		key = KPD_u8GetPressed();

		if (key != NOTPRESSED)
		{
			/* === Digits === */
			if (key >= '0' && key <= '9')
			{
				CLCD_voidSendData(key);

				if (!enteringSecondOperand)
				{
					operand1 = operand1 * 10 + (key - '0');
				}
				else
				{
					operand2 = operand2 * 10 + (key - '0');
				}
			}

			/* === Operators === */
			else if (key == '+' || key == '-' || key == '*' || key == '/')
			{
				if (operator == 0) // prevent double operator press
				{
					CLCD_voidSendData(key);
					operator = key;
					enteringSecondOperand = 1;
				}
			}

			/* === Equal (=) === */
			else if (key == '=')
			{
				CLCD_voidSendData('=');

				switch (operator)
				{
					case '+': result = operand1 + operand2; break;
					case '-': result = operand1 - operand2; break;
					case '*': result = operand1 * operand2; break;
					case '/':
					if (operand2 != 0) result = operand1 / operand2;
					else {
						CLCD_voidClearScreen();
						CLCD_voidSendString((u8*)"Error: Div 0");
						_delay_ms(2000);
						CLCD_voidClearScreen();
						operand1 = operand2 = result = 0;
						operator = 0;
						enteringSecondOperand = 0;
						continue;
					}
					break;
				}

				CLCD_voidSendNumber(result);

				/* reset for next calculation */
				operand1 = result;
				operand2 = 0;
				operator = 0;
				enteringSecondOperand = 0;
			}

			/* === Clear (C) === */
			else if (key == 'C')
			{
				CLCD_voidClearScreen();
				operand1 = operand2 = result = 0;
				operator = 0;
				enteringSecondOperand = 0;
			}
		}
	}
}
