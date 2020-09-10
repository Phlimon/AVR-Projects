/*
 * LM35_Program.c
 *
 *  Created on: Aug 6, 2020
 *      Author: my
 */

/*Types*/
#include "STD_TYPES.h"

/*Dependences*/
#include "BIT_MATH.h"
#include "AVR_DIO_REG.h"

/*Module*/
#include "DIO_interface.h"
#include "ADC_interface.h"
#include "LM35_interface.h"
#include "LCD_interface.h"

/*Delay*/
#include<avr/delay.h>

#define ADC_Voltage

/*
 * Vref = 5v
 * Resolution = 2^10 = 1024 	 2^Number of Bits(10 BIT or 8BIT)
 * step size = Vref / 2^resolution = 5/1024 = 0.0048828215V		4.8828215mV
 * Analog Value = Digital Value * Step Size(mV)
 *
 * LM35 Transfer is 10mV
 *
 * so Actual Reading = Analog Value /10
 * */

/* Description	: Convert The ADC Value Into Analog Temperature
 * Input		: Sensor Read, pointer to store the converted Value
 * Output		: Error State -> 0 No Error
 * 								 1 Error
 */
u8 LM35_u8Tempreature(u16 Copy_u16SensorRead, f32 *Copy_f32ActualValue)
{
	u8  Local_u8Erorr = 0, Local_u8VoltageRef = 0;
	f32 Local_f32StepSize = 0;

#if Voltage_REF == ADC_AVCC
	Local_u8VoltageRef = 5;

#elif Voltage_REF == ADV_AREF
	Local_u8VoltageRef = 2.56;

#endif

	Local_f32StepSize = ((Local_u8VoltageRef / 1024) * 1000);	//Gives me Step Size in mV

	*Copy_f32ActualValue = (Copy_u16SensorRead * Local_f32StepSize) / 10;

	return Local_u8Erorr;
}

/* Description	: Print a Float Temp on LCD
 * Input		: Temp Value
 * Output		: Error State -> 0 No Error
 * 								 1 Error
 */
u8 LM35_u8TempPrintLCD(f32 Copy_f32Temp)
{
	u8 Local_u8Error = 0;
	u8 Local_u8String[] = "Temp: "; //Max 20 Char
	u8 Local_u8StringSize = (sizeof(Local_u8String) - 1);

	LCD_u8WriteString(Local_u8String, Local_u8StringSize);

	LCD_u8FloatNB(Copy_f32Temp, 3, 7, 0);

	return Local_u8Error;
}
