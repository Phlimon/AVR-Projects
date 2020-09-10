/*
 * BIT_MATH.h
 *
 *  Created on: May 24, 2020
 *      Author: my
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

/*shift lift for ONE with the bit number and or it with the variable*/
#define SET_BIT(VAR, BIT_NB) 			(VAR) |= (1 << (BIT_NB))

/*Shift lift for ONE with the bit Number and the NOT it then and it with the variable*/
#define CLR_BIT(VAR, BIT_NB) 			(VAR) &= ~ (1 << (BIT_NB))

/*Shift Lift for ONE with the bit number and the XOR it*/
#define TOGGLE_BIT(VAR, BIT_NB) 		(VAR) ^= (1 << (BIT_NB))

/*shift lift for ONE with bit number and NOT it then AND it with the variable and then OR it with the Value shifted lift with bit number*/
#define ASSIGN_BIT(VAR, BIT_NB, VAL) 	(VAR) = (VAR & (~(1 << BIT_NB))) | (VAL << BIT_NB)

/*shift right for variable and and it with ONE*/
#define GET_BIT(VAR, BIT_NB) 			((VAR >> BIT_NB) & 0x01)

#endif /* BIT_MATH_H_ */
