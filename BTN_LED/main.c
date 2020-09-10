/*
 * main.c
 *
 *  Created on: May 29, 2020
 *      Author: my
 */

/*Standard Types*/
#include "STD_TYPES.h"
#include "AVR_DIO_REG.h"
/*Module*/
#include <util/delay.h>
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "LCD_interface.h"
#include "BTN_interface.h"

void main(void)
{
	u8 Local_u8BtnValue = 0, Local_u8Counter = 0;

	/*Initialize the LCD*/
	LCD_voidInitialization();

	BTN_u8Initialization(DIO_PORT_3, DIO_PIN_0);

	/*LED*/
	DIO_u8SetPinDirection(DIO_PORT_2, DIO_PIN_7, DIO_OUTPUT); //LED

	/*Using APIs*/
	while(1)
	{
		BTN_u8Pressed(DIO_PORT_3, DIO_PIN_0, &Local_u8BtnValue);

		/*if  BTNValue = LOW means btn is pressed*/
		if(Local_u8BtnValue == DIO_LOW)
		{
			/*increment the counter*/
			Local_u8Counter++;

			/*if counter = 10 make it = 0 clear LCD and make btn initial value ONE not pressed*/
			if(Local_u8Counter == 10)
			{
				Local_u8Counter = 0;
				LCD_voidClearLCD();
				Local_u8BtnValue = 1;
			}
			/*Toggle LED*/
			DIO_u8TogglePinValue(DIO_PORT_2, DIO_PIN_7);
		}
		/*Print on LCD*/
		LCD_u8WriteINT(Local_u8Counter, 0, 0);
	}

/*Without Using any APIs*/

//	while(1)
//	{
//		DIO_u8GetPinValue(DIO_PORT_3, DIO_PIN_0, &Local_u8BtnValue);
//
//		if(Local_u8BtnValue == 0)
//		{
//			while(Local_u8BtnValue != 1)
//			{
//				DIO_u8GetPinValue(DIO_PORT_3, DIO_PIN_0, &Local_u8BtnValue);
//			}
//
//			_delay_ms(10);
//			Local_u8Counter++;
//
//			if(Local_u8Counter == 10)
//			{
//				Local_u8Counter = 0;
//				LCD_voidClearLCD();
//			}
//			DIO_u8TogglePinValue(DIO_PORT_3, DIO_PIN_1);
//		}
//		LCD_u8WriteINT(Local_u8Counter, 0, 0);
//	}
}


