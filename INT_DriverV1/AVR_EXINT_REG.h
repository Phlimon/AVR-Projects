/*
 * AVR_EXTI_REG.h
 *
 *  Created on: Jul 10, 2020
 *      Author: my
 */

#ifndef AVR_EXTI_REG_H_
#define AVR_EXTI_REG_H_

#define MCUCR (*((u8*) 0x55))

#define MCUCR_ISC00 0
#define MCUCR_ISC01 1
#define MCUCR_ISC10 2
#define MCUCR_ISC11 3

#define MCUCR_SM0	4
#define MCUCR_SM1	5
#define MCUCR_SM2	6
#define MCUCR_SE	7

#define MCUCSR (*((u8*) 0x54))

#define MCUCSR_PORF   0
#define MCUCSR_EXTIRF 1
#define MCUCSR_BORF   2
#define MCUCSR_WDRF   3
#define MCUCSR_JTRF   4

#define MCUCSR_ISC2   6

#define MCUCSR_JTD    7


#define GICR (*((u8*) 0x5B))

#define GICR_INT0 6
#define GICR_INT1 7
#define GICR_INT2 5

#define GIFR (*((u8*) 0x5A))

#define GIFR_IVCE  0
#define GIFR_IVSEL 1

#define GIFR_INTF0 6
#define GIFR_INTF1 7
#define GIFR_INTF2 5

#define SREG (*((u8*) 0x5F))

#define SREG_I 	   7

#endif
