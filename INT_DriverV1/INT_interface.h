/*
 * Interrupt_interface.h
 *
 *  Created on: Jul 12, 2020
 *      Author: Phlimon.fahim
 */

#ifndef INT_INTERFACE_H_
#define INT_INTERFACE_H_

/*Active and de-active state*/
#define ACTIVE 	 1
#define DEACTIVE 0

/*The State of Each Interrupt*/
#define INTERRUPT_0	ACTIVE
#define INTERRUPT_1	ACTIVE
#define INTERRUPT_2	DEACTIVE 		/*Remark that Interrupt 2 Works only with Falling and Rising Edges */

/*State for Interrupt Zero*/
#define SENSE_CONTROL_INT0 		FALLING_EDGE_INT0

#define LOW_LEVEL_INT0			0
#define LOGICAL_CHANGE_INT0  	1
#define FALLING_EDGE_INT0		2
#define RISING_EDGE_INT0		3

/*State for Interrupt One*/
#define SENSE_CONTROL_INT1		FALLING_EDGE_INT1

#define LOW_LEVEL_INT1			0
#define LOGICAL_CHANGE_INT1 	1
#define FALLING_EDGE_INT1		2
#define RISING_EDGE_INT1		3

/*State for Interrupt Two*/
#define SENSE_CONTROL_INT2		RISING_EDGE_INT2

#define FALLING_EDGE_INT2		0
#define RISING_EDGE_INT2		1

/* Description	: Initialization for Interrupt
 * Input		: Non
 * Output		: Non
 */
void EXINT_voidInitialization(void);

#endif /* INT_INTERFACE_H_ */
