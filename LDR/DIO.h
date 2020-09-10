/*
y8 * DIO.h
 *
 *  Created on: Aug 17, 2019
 *      Author: JESUS
 */

#ifndef DIO_H_
#define DIO_H_

#define A 0
#define B 1
#define C 2
#define D 3
#define pin0 0
#define pin1 1
#define pin2 2
#define pin3 3
#define pin4 4
#define pin5 5
#define pin6 6
#define pin7 7
#define output 1
#define input 0
#define high 1
#define low 0




void DIO_VidSetDir(u8 port, u8 pin, u8 dir);
void DIO_VidWriteValue(u8 port, u8 pin, u8 value);
u8 DIO_U8ReadPin(u8 port, u8 pin);
void DIO_VidSetPortDir(u8 port, u8 dir);
void DIO_VidSetPortValue(u8 port, u8 value);





#endif /* DIO_H_ */
