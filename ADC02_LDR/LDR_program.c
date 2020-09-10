/*
 * LDR_program.c
 *
 *  Created on: Aug 8, 2020
 *      Author: my
 */
#include "STD_TYPES.h"

/*Dependences*/
#include "BIT_MATH.h"
#include "AVR_DIO_REG.h"

/*Module*/
#include "DIO_interface.h"
#include "ADC_interface.h"
#include "LDR_interface.h"
#include "LCD_interface.h"

u8 LDR_u8LDRValue(u16 Copy_u16SensorRead, u32 *Copy_u32ActualLDR)
{
//	u8 Local_u8Error = 0, Local_u8VoltageRef = 0;
//	f32 Local_f32InputAnalog = 0;
//	f32	Local_f32StepSize = 0;
//
//#if Voltage_REF == ADC_AVCC
//	Local_u8VoltageRef = 5;
//
//#elif Voltage_REF == ADV_AREF
//	Local_u8VoltageRef = 2.56;
//
//#endif
//
//	Local_f32StepSize = (Local_u8VoltageRef / RESOLUTION);	//Gives me Step Size in V
//
//	Local_f32InputAnalog = (Copy_u16SensorRead * Local_f32StepSize);
//
//	*Copy_u32ActualLDR = (((Local_u8VoltageRef * FIXED_RESETANCE) - (Local_f32InputAnalog * FIXED_RESETANCE)) / Local_f32InputAnalog);
//
//	return Local_u8Error;




	u32 Local_u32Actual;

	/*Convert the Value to Digital*/
	Local_u32Actual = ((u32)(Copy_u16SensorRead * (u32) 5000) / (u32) 256);//*50   /1023

	*Copy_u32ActualLDR = Local_u32Actual;
	return 0;
}

