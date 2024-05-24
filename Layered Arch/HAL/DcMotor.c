/*
 * DcMotor.c
 *
 *  Created on: Feb 17, 2022
 *      Author: Amr Mahgoub
 */
#include"DcMotor.h"
//Configure The Pins in The H bridge
void DcMotor_init(void){
	DIO_ConfigChannel(DIO_PORTD,Enable1,OUTPUT);
	DIO_ConfigChannel(DIO_PORTD,Enable2,OUTPUT);
	DIO_ConfigChannel(DIO_PORTC,Input1,OUTPUT);
	DIO_ConfigChannel(DIO_PORTC,Input2,OUTPUT);
	DIO_ConfigChannel(DIO_PORTC,Input3,OUTPUT);
	DIO_ConfigChannel(DIO_PORTC,Input4,OUTPUT);

}
//Checks on the the Direction and The Motor And will move It as wished
void MoveInDirction(direction D,Motor_type M){
	switch(M){
	case MotorA:
		if(D==Clockwise){
			DIO_WriteChannel(DIO_PORTD,Enable1,STD_HIGH);

			DIO_WriteChannel(DIO_PORTC,Input1,STD_HIGH);
			DIO_WriteChannel(DIO_PORTC,Input2,STD_LOW);

		}
		else{
			DIO_WriteChannel(DIO_PORTD,Enable1,STD_HIGH);
			DIO_WriteChannel(DIO_PORTC,Input1,STD_LOW);
			DIO_WriteChannel(DIO_PORTC,Input2,STD_HIGH);

		}
		break;
	case MotorB:
		if(D==Clockwise){
			DIO_WriteChannel(DIO_PORTD,Enable2,STD_HIGH);

			DIO_WriteChannel(DIO_PORTC,Input3,STD_LOW);
			DIO_WriteChannel(DIO_PORTC,Input4,STD_HIGH);

		}
		else{
			DIO_WriteChannel(DIO_PORTD,Enable2,STD_HIGH);
			DIO_WriteChannel(DIO_PORTC,Input3,STD_HIGH);
			DIO_WriteChannel(DIO_PORTC,Input4,STD_LOW);

		}
		break;
	}
}
//Stop The Two Motors at Same Instant
void Stop(){
	DIO_WriteChannel(DIO_PORTD,Enable1,STD_LOW);
	DIO_WriteChannel(DIO_PORTD,Enable2,STD_LOW);
}
//Turn the car left by enable Motor A And Disable Motor B
void TurnLeft(){
	MoveInDirction(Clockwise,MotorA);
	//Duration of Rotation
	_delay_ms(800);
	//Stop The car After Rotation
	Stop();

}
//Same As Turn Left
void TurnRight(){
	DIO_WriteChannel(DIO_PORTD,Enable1,STD_LOW);
	MoveInDirction(Clockwise,MotorB);
	_delay_ms(800);
	Stop();
}
//Enable The Two Motors to Go Forward
void GoForward(){
	MoveInDirction(Clockwise,MotorB);
	MoveInDirction(Clockwise,MotorA);


}
