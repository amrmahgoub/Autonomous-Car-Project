/*
 * Timer.c
 *
 *  Created on: Feb 17, 2022
 *      Author: Amr Mahgoub
 */
#include"timer.h"
//intialize the timer on prescaler 1024
void Timmer_init(void){
	TIMER_TCNT0_REG=0x00;
	TIMER_TIMSK_REG|=(1<<0);
	TIMER_TCCR0_REG|=(0<<3);
	TIMER_TCCR0_REG|=5;
}


