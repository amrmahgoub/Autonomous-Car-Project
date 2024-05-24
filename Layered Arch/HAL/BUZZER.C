/*
 * BUZZER.C
 *
 *  Created on: Feb 10, 2022
 *      Author: user
 */
#include"BUZZER.H"
void Buzzer_init(void){
DIO_ConfigChannel(DIO_PORTA,DIO_PIN3,OUTPUT);
}
void Buzzer_ON(){
	DIO_WriteChannel(DIO_PORTA,DIO_PIN3,STD_HIGH);
}
void Buzzer_OFF(){
	DIO_WriteChannel(DIO_PORTA,DIO_PIN3,STD_LOW);
}
void Buzzer_TOGGLE(){
	if(ReadChannel(DIO_PORTA,DIO_PIN3)==STD_HIGH){
		DIO_WriteChannel(DIO_PORTA,DIO_PIN3,STD_LOW);
	}
	else
		DIO_WriteChannel(DIO_PORTA,DIO_PIN3,STD_HIGH);
}
