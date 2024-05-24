/*
 * UltraSonic.c
 *
 *  Created on: Feb 17, 2022
 *      Author: Amr Mahgoub
 */
#include"UltraSonic.h"
// Configure The Trig Pin and the Echo Pin
void UltraSonic_init(void){
	DIO_ConfigChannel(DIO_PORTC,TRIG,OUTPUT);
	DIO_ConfigChannel(DIO_PORTC,ECHO,INPUT);
}
f64 GET_Distance(void){
	f64 distance=0;
	//Initialize the Timer to zero and Turn it off
	TIMER_TCNT0_REG=0X00;
	TIMER_TCCR0_REG=0x00;
	f64 duration=0;
	//Enable the UltraSonic Sensor By that pulses
	DIO_WriteChannel(DIO_PORTC,TRIG,STD_LOW);
	_delay_us(2);
	DIO_WriteChannel(DIO_PORTC,TRIG,STD_HIGH);
	_delay_us(10);
	DIO_WriteChannel(DIO_PORTC,TRIG,STD_LOW);
	//Check on The ECHO PIN When will it become High the enable the timer
	while(ReadChannel(DIO_PORTC,ECHO)==0);
	TIMER_TCCR0_REG|=5;
	//Check on The ECHO PIN When will it become Low the disable the timer
	while(ReadChannel(DIO_PORTC,ECHO));
	TIMER_TCCR0_REG=0x00;
	//the time of one Instruction without prescaler is (0.000064)
	//the total time is the counts * the time of instruction (Tick Time)
	//Store The total time in Duration then the speed of sound 343, so get the distance
	duration=TIMER_TCNT0_REG*(0.000064);
	distance=duration*343/2;
	//Convert The Distance Into Cm
	distance=distance*100;
	return distance;

}
