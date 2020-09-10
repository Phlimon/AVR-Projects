/*
 * Timer1.h
 *
 *  Created on: Feb 15, 2018
 *      Author: Mohamed Waleed
 */

#ifndef TIMER1_H_
#define TIMER1_H_

#define OCR1AL *((volatile u16*)0x4A)

extern void TIMER1_voidInit(void);

extern void TIMER1_voidInit0ff(void);

#endif /* TIMER1_H_ */
