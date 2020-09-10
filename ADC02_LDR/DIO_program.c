/*
 * DIO_program.c
 *
 *  Created on: May 24, 2020
 *      Author: my
 */

/*Types*/
#include "STD_TYPES.h"

/*Dependences*/
#include "BIT_MATH.h"
#include "AVR_DIO_REG.h"

/*Module*/
#include "DIO_interface.h"

/* Description	: To Set Direction for the whole Port (Input, Output)
 * Input		: Port Number, Direction
 * Output		: Error State -> 0 No Error
 * 								 1 Error
 */
u8 DIO_u8SetPortDirection(u8 Copy_u8PortNB, u8 Copy_u8Dir)
{
	/*Local Error Variable*/
	u8 Local_u8Error = 0;

	/*Check if the Direction is Input or Output Else return Local Error with one*/
	if(Copy_u8Dir > DIO_MAX_PORT_VALUE)
	{
		Local_u8Error = 1;
	}

	else
		{
			/*Switch for the PORT Number if it 0 -> 3 it is OK else return Error*/
			switch(Copy_u8PortNB)
			{
			case DIO_PORT_0:
				DDRA = Copy_u8Dir;
				break;

			case DIO_PORT_1:
				DDRB = Copy_u8Dir;
				break;

			case DIO_PORT_2:
				DDRC = Copy_u8Dir;
				break;

			case DIO_PORT_3:
				DDRD = Copy_u8Dir;
				break;

			default:
				Local_u8Error = 1;
				break;
			}
		}

	return Local_u8Error;
}

/* Description	: To Set Value for the whole Port (High, Low)
 * Input		: Port Number, Value
 * Output		: Error State -> 0 No Error
 * 								 1 Error
 */
u8 DIO_u8SetPortValue(u8 Copy_u8PortNB, u8 Copy_u8Value)
{
	/*Local Error Variable*/
	u8 Local_u8Error = 0;

	if(Copy_u8Value > DIO_MAX_PORT_VALUE)
	{
		Local_u8Error = 1;
	}
	else
		{
			/*Switch for the PORT Number if it 0 -> 3 it is OK else return Error*/
			switch(Copy_u8PortNB)
			{
			case DIO_PORT_0:
				PORTA = Copy_u8Value;
				break;

			case DIO_PORT_1:
				PORTB = Copy_u8Value;
				break;

			case DIO_PORT_2:
				PORTC = Copy_u8Value;
				break;

			case DIO_PORT_3:
				PORTD = Copy_u8Value;
				break;

			default:
				Local_u8Error = 1;
				break;
			}
		}

	return Local_u8Error;
}



/* Description	: To Set Direction for a Pin (Input, Output)
 * Input		: Port Number, Pin Number, Direction
 * Output		: Error State -> 0 No Error
 * 								 1 Error
 */
u8 DIO_u8SetPinDirection(u8 Copy_u8PortNB, u8 Copy_u8PinNB, u8 Copy_u8Dir)
{
	/*Local Error Variable*/
	u8 Local_u8Error = 0;

	/*Check that the PIN Number is between 0 -> 7 else Return Local Error with ONE*/
	if(Copy_u8PinNB > DIO_PIN_7)
	{
		Local_u8Error = 1;
	}

	/*Check if the Direction is Input or Output Else return Local Error with one*/
	if((Copy_u8Dir != DIO_INPUT) && (Copy_u8Dir != DIO_OUTPUT))
	{
		Local_u8Error = 1;
	}

	/*Else Check for the PORT number is between 0 -> 3*/
	else
	{
		switch(Copy_u8PortNB)
		{
		case DIO_PORT_0:
			ASSIGN_BIT(DDRA, Copy_u8PinNB, Copy_u8Dir);
			break;

		case DIO_PORT_1:
			ASSIGN_BIT(DDRB, Copy_u8PinNB, Copy_u8Dir);
			break;

		case DIO_PORT_2:
			ASSIGN_BIT(DDRC, Copy_u8PinNB, Copy_u8Dir);
			break;

		case DIO_PORT_3:
			ASSIGN_BIT(DDRD, Copy_u8PinNB, Copy_u8Dir);
			break;

		default:
			Local_u8Error = 1;
			break;
		}
	}
	return Local_u8Error;
}

/* Description	: To Set Value for Pin (High, Low)
 * Input		: Port Number, Pin Number, Value
 * Output		: Error State -> 0 No Error
 * 								 1 Error
 */
u8 DIO_u8SetPinValue(u8 Copy_u8PortNB, u8 Copy_u8PinNB, u8 Copy_u8Value)
{
	/*Local Error Variable*/
	u8 Local_u8Error = 0;

	/*Check that the PIN Number is between 0 -> 7 else Return Local Error with ONE*/
	if(Copy_u8PinNB > DIO_PIN_7)
	{
		Local_u8Error = 1;
	}

	/*Check if the Direction is Input or Output Else return Local Error with one*/
	if((Copy_u8Value != DIO_HIGH) && (Copy_u8Value != DIO_LOW))
	{
		Local_u8Error = 1;
	}

	/*Else Check for the PORT number is between 0 -> 3*/
	else
	{
		switch(Copy_u8PortNB)
		{
		case DIO_PORT_0:
			ASSIGN_BIT(PORTA, Copy_u8PinNB, Copy_u8Value);
			break;

		case DIO_PORT_1:
			ASSIGN_BIT(PORTB, Copy_u8PinNB, Copy_u8Value);
			break;

		case DIO_PORT_2:
			ASSIGN_BIT(PORTC, Copy_u8PinNB, Copy_u8Value);
			break;

		case DIO_PORT_3:
			ASSIGN_BIT(PORTD, Copy_u8PinNB, Copy_u8Value);
			break;

		default:
			Local_u8Error = 1;
			break;
		}
	}
	return Local_u8Error;
}



/* Description	: To Get a Value for a whole Port
 * Input		: Port Number, Pointer for a Value
 * Output		: Error State -> 0 No Error
 * 								 1 Error
 */
u8 DIO_u8GetPortValue(u8 Copy_u8PortNB, u8 * Copy_u8Value)
{
	/*Local Error Variable*/
	u8 Local_u8Error = 0;

	if(Copy_u8Value == NULL_POINTER)
	{
		Local_u8Error = 1;
	}

	else
	{
		/*Switch for the PORT Number if it 0 -> 3 it is OK else return Error*/
		switch(Copy_u8PortNB)
		{
		case DIO_PORT_0:
			*Copy_u8Value = PINA;
			break;

		case DIO_PORT_1:
			*Copy_u8Value = PINB;
			break;

		case DIO_PORT_2:
			*Copy_u8Value = PINC;
			break;

		case DIO_PORT_3:
			*Copy_u8Value = PIND;
			break;

		default:
			Local_u8Error = 1;
			break;
		}

	}
	return Local_u8Error;
}

/* Description	: To Get Value for a Pin
 * Input		: Port Number, Pin Number, Pointer for a Value
 * Output		: Error State -> 0 No Error
 * 								 1 Error
 */
u8 DIO_u8GetPinValue(u8 Copy_u8PortNB, u8 Copy_u8PinNB, u8 * Copy_u8Value)
{
	/*Local Error Variable*/
	u8 Local_u8Error = 0;

	/*Check that the PIN Number is between 0 -> 7 else Return Local Error with ONE*/
	if(Copy_u8Value == NULL_POINTER)
	{
		Local_u8Error = 1;
	}
	if(Copy_u8PinNB > DIO_PIN_7)
	{
		Local_u8Error = 1;
	}

	else
	{
		switch(Copy_u8PortNB)
		{
		case DIO_PORT_0:
			*Copy_u8Value = GET_BIT(PINA, Copy_u8PinNB);
			break;

		case DIO_PORT_1:
			*Copy_u8Value = GET_BIT(PINB, Copy_u8PinNB);
			break;

		case DIO_PORT_2:
			*Copy_u8Value = GET_BIT(PINC, Copy_u8PinNB);
			break;

		case DIO_PORT_3:
			*Copy_u8Value = GET_BIT(PIND, Copy_u8PinNB);
			break;

		default:
			Local_u8Error = 1;
			break;
		}
	}

	return Local_u8Error;
}

/* Description	: To Toggle Pin Value(High, Low)
 * Input		: Port Number, Pin Number
 * Output		: Error State -> 0 No Error
 * 								 1 Error
 */
u8 DIO_u8TogglePinValue(u8 Copy_u8PortNB, u8 Copy_u8PinNB)
{
	/*Local Error Variable*/
	u8 Local_u8Error = 0;

	/*Check that the PIN Number is between 0 -> 7 else Return Local Error with ONE*/
	if(Copy_u8PinNB > DIO_PIN_7 || Copy_u8PortNB > 3)
	{
		Local_u8Error = 1;
	}

	/*Else Check for the PORT number is between 0 -> 3*/
	else
	{
		switch(Copy_u8PortNB)
		{
		case DIO_PORT_0:
			TOGGLE_BIT(PORTA, Copy_u8PinNB);
			break;

		case DIO_PORT_1:
			TOGGLE_BIT(PORTB, Copy_u8PinNB);
			break;

		case DIO_PORT_2:
			TOGGLE_BIT(PORTC, Copy_u8PinNB);
			break;

		case DIO_PORT_3:
			TOGGLE_BIT(PORTD, Copy_u8PinNB);
			break;

		default:
			Local_u8Error = 1;
			break;
		}
	}
	return Local_u8Error;
}
