/*
 * LED.h
 *
 *  Created on: Aug 21, 2019
 *      Author: JESUS
 */

#ifndef LED_H_
#define LED_H_

#define ON 1
#define OFF 0

void LED_VidSetBit(u8 port, u8 pin );

void LED_VidTurnOn(u8 port, u8 pin );

void LED_VidTurnOff(u8 port, u8 pin );


#endif /* LED_H_ */
