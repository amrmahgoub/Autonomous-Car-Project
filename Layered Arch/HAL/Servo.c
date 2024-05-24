/*
 * Servo.c
 *
 *  Created on: Feb 19, 2022
 *      Author: Amr Mahgoub
 */
#include"Servo.h"
//Configure the The Servo PIN Using DIO Module
void Servo_init(){
	DIO_ConfigChannel(DIO_PORTD,DIO_PIN7,OUTPUT);
}
//I used to Do PWM using Software
// Turn The Servo on Position Zero
void Possition_Zero(void){
	//Apply PWM for some time To move the Servo to Zero Position
	for(int i=0;i<45;i++){
		DIO_WriteChannel(DIO_PORTD,DIO_PIN7,STD_LOW);
			_delay_ms(1.86);
			DIO_WriteChannel(DIO_PORTD,DIO_PIN7,STD_HIGH);
			_delay_ms(1.4);}
}
// Turn The Servo on Position 90
void Possition_90(void){
//Same as Position Zero
	for(int i=0;i<45;i++){
		DIO_WriteChannel(DIO_PORTD,DIO_PIN7,STD_LOW);
			_delay_ms(19.48);
			DIO_WriteChannel(DIO_PORTD,DIO_PIN7,STD_HIGH);
			_delay_ms(0.52);}
}
// Turn The Servo on Position 180
void Possition_180(void){
//Same as Position Zero
	for(int i=0;i<55;i++){
		DIO_WriteChannel(DIO_PORTD,DIO_PIN7,STD_LOW);
			_delay_ms(17.6);
			DIO_WriteChannel(DIO_PORTD,DIO_PIN7,STD_HIGH);
			_delay_ms(2.4);}
}
