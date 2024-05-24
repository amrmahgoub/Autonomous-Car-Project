/*
 * timer.h
 *
 *  Created on: Feb 17, 2022
 *      Author: Amr Mahgoub
 */

#ifndef TIMER_H_
#define TIMER_H_
#include"STD.H"
#define TIMER_TCCR0_REG  (*(volatile u8*)(0x53))
#define TIMER_TCNT0_REG  (*(volatile u8*)(0x52))
#define TIMER_OCR0_REG  (*(volatile u8*)(0x5C))
#define TIMER_TCCR0_REG  (*(volatile u8*)(0x53))
#define TIMER_TIMSK_REG  (*(volatile u8*)(0x59))
#define TIMER_TIFR_REG  (*(volatile u8*)(0x58))
void Timmer_init(void);

#endif /* TIMER_H_ */
