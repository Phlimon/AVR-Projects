/*
 * IR_interface.h
 *
 *  Created on: May 26, 2020
 *      Author: my
 */

#ifndef IR_INTERFACE_H_
#define IR_INTERFACE_H_

/*IR Sensor PORT and PIN*/
#define IR_PORT		DIO_PORT_3
#define IR_PIN		DIO_PIN_7

/*IR Sensor Value*/
#define TRUE  	1
#define FALSE 	0

/* Description	: Initializing the IR Sensor *IR Infrared 2 - 30cm Obstacle Detaction Sensor Module FC-51*
 * 				  By get the PORT and The PIN and make the an INPUT
 * Input		: Non
 * Output		: Error State -> 0 No Error
 * 								 1 Error
 */
u8 IR_u8Initialize();

/* Description	: To get the IR sensor Read (TRUE, FALSE)
 * Input		: Address of the variable to put the result in
 * Output		: Error State -> 0 No Error
 * 								 1 Error
 */
u8 IR_u8GetValue(u8 * Copy_u8IRValue);

#endif /* IR_INTERFACE_H_ */
