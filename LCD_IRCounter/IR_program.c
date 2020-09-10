/*
 * IR_program.c
 *
 *  Created on: May 26, 2020
 *      Author: my
 */

#include "STD_TYPES.h"

/*Module*/
#include "DIO_interface.h"
#include "IR_interface.h"
#include <util/delay.h>

/* Description	: Initializing the IR Sensor *IR Infrared 2 - 30cm Obstacle Detaction Sensor Module FC-51*
 * 				  By get the PORT and The PIN and make the an INPUT
 * Input		: Non
 * Output		: Error State -> 0 No Error
 * 								 1 Error
 */
u8 IR_u8Initialize(void)
{
	u8 Local_u8Error = 0;

	/*As PORT A is for Analog Sensors so better to use any other PORT for Digital Ones*/
	if(IR_PORT == 0)
	{
		Local_u8Error = 1;
	}
	DIO_u8SetPinDirection(IR_PORT, IR_PIN, DIO_INPUT);

	return Local_u8Error;
}

/* Description	: To get the IR sensor Read (TRUE, FALSE)
 * Input		: Address of the variable to put the result in
 * Output		: Error State -> 0 No Error
 * 								 1 Error
 */
u8 IR_u8GetValue(u8 * Copy_u8IRValue)
{
	/*Local Variables*/
	u8 Local_u8Error = 0, Local_u8IRValue = 0, Local_u8Read = 0;

	/*Getting the Sensor read*/
	DIO_u8GetPinValue(IR_PORT, IR_PIN, &Local_u8IRValue);

	/*IR Sensor is Active LOW means if it read an Obstacle it will send ZERO and if it read non will send ONE*/
	if(Local_u8IRValue == DIO_LOW)
	{
		/*Delay to make sure it is not an AIR Signal*/
		_delay_ms(10);

		/*If the read still Low That is Mean it is the Sensor signal not an Air Signal*/
		if(Local_u8IRValue == DIO_LOW)
		{
			Local_u8Read = TRUE;
		}

		/*This is Debouncing to make sure it read one time not multiple at once*/
		while(Local_u8IRValue != DIO_HIGH)
		{
			DIO_u8GetPinValue(IR_PORT, IR_PIN, &Local_u8IRValue);
			_delay_ms(10);
		}
	}
	else
	{
		Local_u8Read = FALSE;
	}

	*Copy_u8IRValue = Local_u8Read;

	return Local_u8Error;
}
