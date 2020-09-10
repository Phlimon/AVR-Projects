/*
 * utils.h
 *
 *  Created on: Aug 17, 2019
 *      Author: JESUS
 */

#ifndef UTILS_H_
#define UTILS_H_

#define set_bit(reg,bitn) reg|=(1<<bitn)
#define clr_bit(reg,bitn) reg&=(~(1<<bitn))
#define get_bit(reg,bitn) ((reg&(1<<bitn))>>bitn)


#endif /* UTILS_H_ */
