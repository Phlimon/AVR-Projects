/*
 * SEG_interface.h
 *
 *  Created on: May 25, 2020
 *      Author: my
 */

#ifndef SEG_INTERFACE_H_
#define SEG_INTERFACE_H_

/*The 7SEG PORTs*/
#define _7SEG1_PORT DIO_PORT_2
#define _7SEG2_PORT DIO_PORT_3

/* Description	: To perform a single Symbol, Number or Character for Single Display
 * Input		: Symbol, Number or Character E.X. (1), ('A') ...
 * Output		: Error State -> 0 No Error
 * 								 1 Error
 */
u8 _7SEG_u8SingleDigit1(u8 Copy_u8Symbol);

/* Description	: To perform a single Symbol, Number or Character for another Single Display
 * Input		: Symbol, Number or Character E.X. (1), ('A') ...
 * Output		: Error State -> 0 No Error
 * 								 1 Error
 */
u8 _7SEG_u8SingleDigit2(u8 Copy_u8Symbol);

/* Description	: To perform a number consists of TWO Digits
 * Input		: Number E.X. (05), (99) ...
 * Output		: Error State -> 0 No Error
 * 								 1 Error
 */
u8 _7SEG_u8DoubleDigits(u8 Copy_u8Symbol);

#endif /* SEG_INTERFACE_H_ */
