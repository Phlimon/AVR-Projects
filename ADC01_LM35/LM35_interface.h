/*
 * LM35_interface.c
 *
 *  Created on: Aug 6, 2020
 *      Author: my
 */

#ifndef LM35_INTERFACE_C_
#define LM35_INTERFACE_C_

/* Description	: Convert The ADC Value Into Analog Temperature
 * Input		: Sensor Read, pointer to store the converted Value
 * Output		: Error State -> 0 No Error
 * 								 1 Error
 */
u8 LM35_u8Tempreature(u16 Copy_u16SensorRead, f32 *Copy_f32ActualValue);

/* Description	: Print a Float Temp on LCD
 * Input		: Temp Value
 * Output		: Error State -> 0 No Error
 * 								 1 Error
 */
u8 LM35_u8TempPrintLCD(f32 Copy_f32Temp);

#endif /* LM35_INTERFACE_C_ */
