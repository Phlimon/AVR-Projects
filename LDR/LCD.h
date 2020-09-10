/*
 * LCD.h
 *
 *  Created on: Aug 23, 2019
 *      Author: JESUS
 */

#ifndef LCD_H_
#define LCD_H_


void LCD_VidWriteCommand(u8 command);
void LCD_VidWriteData(u8 data);
void LCD_VidInit(void);


void LCD_Gotoxy (u8 Y,u8 X);

void LCD_vidWriteInteger(u32 m);






#endif /* LCD_H_ */
