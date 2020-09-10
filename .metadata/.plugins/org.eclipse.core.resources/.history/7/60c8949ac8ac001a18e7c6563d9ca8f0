/*
 * DIO_interface.h
 *
 *  Created on: May 24, 2020
 *      Author: my
 */

/*Header Guard*/
#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

/*Directions*/
#define DIO_INPUT   		0
#define DIO_OUTPUT  		1

/*Value*/
#define DIO_LOW  			0
#define DIO_HIGH 			1
#define DIO_MAX_PORT_VALUE 255
/*PORT Number*/
#define DIO_PORT_0			0
#define DIO_PORT_1			1
#define DIO_PORT_2			2
#define DIO_PORT_3			3

/*PIN Number*/
#define DIO_PIN_0  			0
#define DIO_PIN_1  			1
#define DIO_PIN_2  			2
#define DIO_PIN_3  			3
#define DIO_PIN_4  			4
#define DIO_PIN_5  			5
#define DIO_PIN_6  			6
#define DIO_PIN_7  			7

/*Null Pointer*/
#define NULL_POINTER ((u8*)0) //casting for the pointer

/* Description	: To Set Direction for the whole Port (Input, Output)
 * Input		: Port Number, Direction
 * Output		: Error State -> 0 No Error
 * 								 1 Error
 */
u8 DIO_u8SetPortDirection(u8 Copy_u8PortNB, u8 Copy_u8Dir);

/* Description	: To Set Value for the whole Port (High, Low)
 * Input		: Port Number, Value
 * Output		: Error State -> 0 No Error
 * 								 1 Error
 */
u8 DIO_u8SetPortValue(u8 Copy_u8PortNB, u8 Copy_u8Value);



/* Description	: To Set Direction for a Pin (Input, Output)
 * Input		: Port Number, Pin Number, Direction
 * Output		: Error State -> 0 No Error
 * 								 1 Error
 */
u8 DIO_u8SetPinDirection(u8 Copy_u8PortNB, u8 Copy_u8PinNB, u8 Copy_u8Dir);

/* Description	: To Set Value for Pin (High, Low)
 * Input		: Port Number, Pin Number, Value
 * Output		: Error State -> 0 No Error
 * 								 1 Error
 */
u8 DIO_u8SetPinValue(u8 Copy_u8PortNB, u8 Copy_u8PinNB, u8 Copy_u8Value);



/* Description	: To Get a Value for a whole Port
 * Input		: Port Number, Pointer for a Value
 * Output		: Error State -> 0 No Error
 * 								 1 Error
 */
u8 DIO_u8GetPortValue(u8 Copy_u8PortNB, u8 * Copy_u8Value);

/* Description	: To Get Value for a Pin
 * Input		: Port Number, Pin Number, Pointer for a Value
 * Output		: Error State -> 0 No Error
 * 								 1 Error
 */
u8 DIO_u8GetPinValue(u8 Copy_u8PortNB, u8 Copy_u8PinNB, u8 * Copy_u8Value);

#endif /* DIO_INTERFACE_H_ */
