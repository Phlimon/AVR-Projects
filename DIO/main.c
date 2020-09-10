/*
 * main.c
 *
 *  Created on: May 24, 2020
 *      Author: my
 */

#include "STD_TYPES.h"

/*Module*/
#include "DIO_interface.h"
#include "SEG_interface.h"
#include <avr/delay.h>

#define TRUE 1

#define FALSE 0

u8 IR_u8Read();

void main(void)
{
	DIO_u8SetPortDirection(DIO_PORT_0, 255);
	//DIO_u8SetPinDirection(DIO_PORT_0, DIO_PIN_0, DIO_OUTPUT);

	while(1)
	{
		u8 Local_u8PINValue = 0, Local_7SEGError = 0;
		u8 static Local_u8Counter = 0;

//		DIO_u8SetPortValue(DIO_PORT_2, 0b10101010);
//		_delay_ms(1000);
//
//		DIO_u8SetPortValue(DIO_PORT_2, 0b01010101);
//		_delay_ms(1000);

//		DIO_u8SetPinValue(DIO_PORT_0, DIO_PIN_0, DIO_HIGH);
//		_delay_ms(1000);
//
//		DIO_u8SetPinValue(DIO_PORT_0, DIO_PIN_0, DIO_LOW);
//		_delay_ms(1000);

		Local_u8PINValue = IR_u8Read();

		if(Local_u8PINValue == TRUE)
		{
			Local_u8Counter ++;
		}

		Local_7SEGError = _7SEG_u8DoubleDigits(Local_u8Counter);

//		if(Local_u8Counter == 10)
//		{
//			DIO_u8SetPinValue(DIO_PORT_0, DIO_PIN_0, DIO_HIGH);
//		}
	}
}


u8 IR_u8Read()
{
	u8 Local_u8IRValue = 0, Local_u8Read = 0;

	DIO_u8GetPinValue(DIO_PORT_1, DIO_PIN_0, &Local_u8IRValue);

	if(Local_u8IRValue == DIO_LOW)
	{
		Local_u8Read = TRUE;
		while(Local_u8IRValue != DIO_HIGH)
		{
			DIO_u8GetPinValue(DIO_PORT_1, DIO_PIN_0, &Local_u8IRValue);
			_delay_ms(100);
		}
	}
	else
	{
		Local_u8Read = FALSE;
	}

	return Local_u8Read;
}



//DIO_u8GetPinValue(DIO_PORT_1, DIO_PIN_0, &Local_u8PINValue);
//
//if(Local_u8PINValue == DIO_LOW)
//{
//	Local_u8Counter ++;
//	while(Local_u8PINValue != DIO_HIGH)
//	{
//		DIO_u8GetPinValue(DIO_PORT_1, DIO_PIN_0, &Local_u8PINValue);
//		_delay_ms(100);
//	}
//}
//
//Local_7SEGError = _7SEG_u8DoubleDigits(Local_u8Counter);
