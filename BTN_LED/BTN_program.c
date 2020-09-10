/*
 * BTN_program.c
 *
 *  Created on: Jun 23, 2020
 *      Author: Phlimon.fahim
 */

/*Standard Types*/
#include "STD_TYPES.h"

/*Module*/
#include "DIO_interface.h"
#include "BTN_interface.h"

/* Description	: Initialize the button
 * Input		: Port Number, Pin Number
 * Output		: Error State -> 0 No Error
 * 								 1 Error
 */
u8 BTN_u8Initialization(u8 Copy_u8BTNPort, u8 Copy_u8BTNPin)
{
	u8 Local_u8Error = 0;

	if(Copy_u8BTNPort > 3 || Copy_u8BTNPin > 7)
	{
		Local_u8Error = 1;
	}
	else
	{
		/*Button pin as input*/
		DIO_u8SetPinDirection(Copy_u8BTNPort, Copy_u8BTNPin, DIO_INPUT);
		/*Make an internal Pull up resistor*/
		DIO_u8SetPinValue(Copy_u8BTNPort, Copy_u8BTNPin, DIO_HIGH);
	}
	return Local_u8Error;
}

/* Description	: state of the button
 * Input		: Port Number, Pin Number, pointer for the Value
 * Output		: Error State -> 0 No Error
 * 								 1 Error
 */
u8 BTN_u8Pressed(u8 Copy_u8BTNPort, u8 Copy_u8BTNPin, u8 *Copy_u8Value)
{
	u8 Local_u8Error = 0;
	u8 Local_u8BtnValue = 0;

	if(Copy_u8BTNPort > 3 || Copy_u8BTNPin > 7)
	{
		Local_u8Error = 1;
	}
	else
	{
		DIO_u8GetPinValue(Copy_u8BTNPort, Copy_u8BTNPin, &Local_u8BtnValue);

		if(Local_u8BtnValue == DIO_LOW)
		{
			_delay_ms(10);

			while(Local_u8BtnValue != DIO_HIGH)
			{
				DIO_u8GetPinValue(Copy_u8BTNPort, Copy_u8BTNPin, &Local_u8BtnValue);
			}
			_delay_ms(10);
			*Copy_u8Value = DIO_LOW;
		}
		else
		{
			*Copy_u8Value = DIO_HIGH;
		}
		//*Copy_u8Value = Local_u8BtnValue;
	}

	return Local_u8Error;
}
