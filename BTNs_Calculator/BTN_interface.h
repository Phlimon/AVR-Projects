/*
 * BTN_interface.h
 *
 *  Created on: Jun 23, 2020
 *      Author: Phlimon.fahim
 */

#ifndef BTN_INTERFACE_H_
#define BTN_INTERFACE_H_

/* Description	: Initialize the button
 * Input		: Port Number, Pin Number
 * Output		: Error State -> 0 No Error
 * 								 1 Error
 */
u8 BTN_u8Initialization(u8 Copy_u8BTNPort, u8 Copy_u8BTNPin);

/* Description	: state of the button
 * Input		: Port Number, Pin Number, pointer for the Value
 * Output		: Error State -> 0 No Error
 * 								 1 Error
 */
u8 BTN_u8Pressed(u8 Copy_u8BTNPort, u8 Copy_u8BTNPin, u8 *Copy_u8Value);

#endif /* BTN_INTERFACE_H_ */
