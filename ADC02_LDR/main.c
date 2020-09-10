/*
 * main.c
 *
 *  Created on: Aug 5, 2020
 *      Author: my
 */

/* MCAL */
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "BIT_MATH.h"

/* HAL */
#include "LCD_interface.h"
#include "ADC_interface.h"
#include "LDR_interface.h"
#include <avr/delay.h>

void main(void)
{
	/*Local Variables*/
	u8 Local_u8String[] = "LDR: "; //Max 20 Char
	u8 Local_u8StringSize = (sizeof(Local_u8String) - 1);
	u16 Local_u16ADCValue = 0;
	u32 Local_u32ActualLDR = 0;

	DIO_u8SetPortDirection(LCD_DATA_PORT, DIO_MAX_PORT_VALUE);
	DIO_u8SetPinDirection(LCD_CONTROL_PORT, LCD_RS_PIN, DIO_OUTPUT);
	DIO_u8SetPinDirection(LCD_CONTROL_PORT, LCD_RW_PIN, DIO_OUTPUT);
	DIO_u8SetPinDirection(LCD_CONTROL_PORT, LCD_E_PIN, DIO_OUTPUT);

	/*LCD Initialization*/
	LCD_voidInitialization();

	/*ADC Initialization*/
	ADC_voidInitialization();

	/*ADC PIN Direction*/
	DIO_u8SetPinDirection(DIO_PORT_0, DIO_PIN_0, DIO_INPUT);

	while(1)
	{
		/*Get the Digital Reading from ADC*/
		ADC_u8GetReading(Channel_0, &Local_u16ADCValue);

		/*Convert the Value to Actual TEMP*/
		LDR_u8LDRValue(Local_u16ADCValue, &Local_u32ActualLDR);

		/*Print the Actual TEMP on LCD*/
		LCD_u8GoToXY(0, 0);
		LCD_u8WriteString(Local_u8String, Local_u8StringSize);

		LCD_u8WriteINT(Local_u32ActualLDR, 0, 1);
		LCD_u8WriteINT(Local_u16ADCValue, 10, 0);
	}
}

