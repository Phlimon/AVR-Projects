/*
 * KPD_interface.h
 *
 *  Created on: Jun 30, 2020
 *      Author: my
 */

#ifndef KPD_INTERFACE_H_
#define KPD_INTERFACE_H_

#define KPD_PORT			DIO_PORT_3
#define COL_NB				4
#define ROW_NB				4
#define ROW_START_AFTER		4

/* Description	: KPD Initialization
 * Input		: Non
 * Output		: Error State -> 0 No Error
 * 								 1 Error
 */
u8 KPD_u8Initialization();

/* Description	: Get the Key pressed
 * Input		: Pointer for the Pressed key
 * Output		: Error State -> 0 No Error
 * 								 1 Error
 */
u8 KPD_u8GetPressedKey(u8 *Copy_u8KeyNB);

#endif /* KPD_INTERFACE_H_ */
