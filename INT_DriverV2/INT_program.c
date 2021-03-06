/*
 * Interrupt_program.c
 *
 *  Created on: Jul 12, 2020
 *      Author: Phlimon.fahim
 */
#include "STD_TYPES.h"

/*Dependences*/
#include "BIT_MATH.h"
#include "AVR_DIO_REG.h"
#include "AVR_EXINT_REG.h"

#include "INT_interface.h"

/*Pointer to Function of ISR INT0*/
void (*INT0_CallBack)(void);

/*Pointer to Function of ISR INT1*/
void (*INT1_CallBack)(void);

/*Pointer to Function of ISR INT2*/
void (*INT2_CallBack)(void);

/* Description	: Initialization for Interrupt
 * Input		: Non
 * Output		: Non
 */
void EXINT_voidInitialization(void)
{
	/*Enable General Interrupt*/
	SET_BIT(SREG, SREG_I);

	/*Activation for Interrupt Zero*/
#if INTERRUPT_0 == ACTIVE

	/*Enable INT0 */
	SET_BIT(GICR, GICR_INT0);

	/*Choose the State of Interrupt 0*/
	#if SENSE_CONTROL_INT0 == LOW_LEVEL_INT0
		CLR_BIT(MCUCR, MCUCR_ISC00);
		CLR_BIT(MCUCR, MCUCR_ISC01);

	#elif SENSE_CONTROL_INT0 == LOGICAL_CHANGE_INT0
		SET_BIT(MCUCR, MCUCR_ISC00);
		CLR_BIT(MCUCR, MCUCR_ISC01);

	#elif SENSE_CONTROL_INT0 == FALLING_EDGE_INT0
		CLR_BIT(MCUCR, MCUCR_ISC00);
		SET_BIT(MCUCR, MCUCR_ISC01);

	#elif SENSE_CONTROL_INT0 == RISING_EDGE_INT0
		SET_BIT(MCUCR, MCUCR_ISC00);
		SET_BIT(MCUCR, MCUCR_ISC01);
	#endif
#endif

		/*Activation for Interrupt One*/
#if INTERRUPT_1 == ACTIVE

		/*Enable INT1*/
	SET_BIT(GICR, GICR_INT1);

	/*Choose the State of Interrupt 1*/
	#if SENSE_CONTROL_INT1 == LOW_LEVEL_INT1
		CLR_BIT(MCUCR, MCUCR_ISC10);
		CLR_BIT(MCUCR, MCUCR_ISC11);

	#elif SENSE_CONTROL_INT1 == LOGICAL_CHANGE_INT1
		SET_BIT(MCUCR, MCUCR_ISC10);
		CLR_BIT(MCUCR, MCUCR_ISC11);

	#elif SENSE_CONTROL_INT1 == FALLING_EDGE_INT1
		CLR_BIT(MCUCR, MCUCR_ISC10);
		SET_BIT(MCUCR, MCUCR_ISC11);

	#elif SENSE_CONTROL_INT1 == RISING_EDGE_INT1
		SET_BIT(MCUCR, MCUCR_ISC10);
		SET_BIT(MCUCR, MCUCR_ISC11);
	#endif
#endif

		/*Activation for Interrupt Two*/
#if INTERRUPT_2 == ACTIVE

		/*Enable INT2 */
	SET_BIT(GICR, GICR_INT2);

	/*Choose the State of Interrupt 2*/
	#if SENSE_CONTROL_INT2 == FALLING_EDGE_INT2
		CLR_BIT(MCUCSR, MCUCSR_ISC2);

	#elif SENSE_CONTROL_INT2 == RISING_EDGE_INT2
		SET_BIT(MCUCSR, MCUCSR_ISC2);
	#endif
#endif
}

/*ISR for Interrupt 0*/
void __vector_1(void)
{
	INT0_CallBack();
}

/*ISR for Interrupt 1*/
void __vector_2(void)
{
	INT1_CallBack();
}

/* Description	: Set the Value of the ISR
 * Input		: Pointer to Function
 * Output		: Non
 */
void INT0_SET_CallBack(void(*Ptr)(void))
{
	INT0_CallBack = Ptr;
}

/* Description	: Set the Value of the ISR
 * Input		: Pointer to Function
 * Output		: Non
 */
void INT1_SET_CallBack(void(*Ptr1)(void))
{
	INT1_CallBack = Ptr1;
}

/* Description	: Set the Value of the ISR
 * Input		: Pointer to Function
 * Output		: Non
 */
void INT2_SET_CallBack(void(*Ptr2)(void))
{
	INT2_CallBack = Ptr2;
}
