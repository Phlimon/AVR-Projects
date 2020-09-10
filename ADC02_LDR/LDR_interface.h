/*
 * LDR_interface.h
 *
 *  Created on: Aug 8, 2020
 *      Author: my
 */

#ifndef LDR_INTERFACE_H_
#define LDR_INTERFACE_H_

#define FIXED_RESETANCE		1000
#define RESOLUTION			1024		//BITs For ADC

u8 LDR_u8LDRValue(u16 Copy_u16SensorRead, u32 *Copy_u32ActualLDR);

#endif /* LDR_INTERFACE_H_ */
