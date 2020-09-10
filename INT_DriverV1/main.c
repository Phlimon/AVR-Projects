/*
 * main.c
 *
 *  Created on: Jul 12, 2020
 *      Author: my
 */

/*Standard Types*/
#include "STD_TYPES.h"

/*Modules*/
#include "DIO_interface.h"
#include "BTN_interface.h"
#include "INT_interface.h"
#include "SEG_interface.h"

/*ISR "Interrupt Service Routine" for Interrupt 0
 *and #pragma or __attribute__((Signal, used));
 *to not make the compiler optimization delete the ISR
 */
void __vector_1(void) __attribute__((signal, used));

/*ISR "Interrupt Service Routine" for Interrupt 1
 *and #pragma or __attribute__((Signal, used));
 *to not make the compiler optimization delete the ISR
 */
void __vector_2(void) __attribute__((signal, used));

/*Global Variable Counter*/
volatile u8 INT_u8Counter = 0;

void main(void)
{
	/*Interrupt Initialization*/
	EXINT_voidInitialization();

	/*Make the 7 segment port as output*/
	DIO_u8SetPortDirection(_7SEG1_PORT, DIO_MAX_PORT_VALUE);

	/*Interrupt 0*/
	BTN_u8Initialization(DIO_PORT_3, DIO_PIN_2);
	/*Interrupt 1*/
	BTN_u8Initialization(DIO_PORT_3, DIO_PIN_3);

	while(1)
	{
		/*Take the Number and display it on 7 segment*/
		DIO_u8SetPortValue(_7SEG1_PORT, _7SEG_u8SingleDigit1(INT_u8Counter));
	}
}

/*ISR for Interrupt 0*/
void __vector_1(void)
{
	/*Local Variable*/
	u8 Local_u8BTN1 = 0;

	/*Check if the Button pressed*/
	BTN_u8Pressed(DIO_PORT_3, DIO_PIN_2, &Local_u8BTN1);

	/*if pressed*/
	if(Local_u8BTN1 == DIO_LOW)
	{
		INT_u8Counter++;
	}

	/*if counter reaches 10 reset it to zero*/
	if(INT_u8Counter == 10)
	{
		INT_u8Counter = 0;
	}
}

/*ISR for Interrupt 1*/
void __vector_2(void)
{
	/*Local Variables*/
	u8 Local_u8BTN1 = 0;

	/*Check the button*/
	BTN_u8Pressed(DIO_PORT_3, DIO_PIN_3, &Local_u8BTN1);

	/*if button pressed*/
	if(Local_u8BTN1 == DIO_LOW)
	{
		INT_u8Counter--;
	}

	/*if less than zero make it nine*/
	if(INT_u8Counter == 255)
	{
		INT_u8Counter = 9;
	}
}
