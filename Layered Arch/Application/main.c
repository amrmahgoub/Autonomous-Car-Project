/*
 * main.c
 *
 *  Created on: Jan 30, 2022
 *      Author: Amr Mahgoub
 */



#include"delay.h"
#include"STD.H"
#include"Dioo.h"
#include"LCD.h"
#include"LCD.c"
#include"UltraSonic.h"
#include"DcMotor.h"
#include"Servo.h"



int main (){
//Initialize the Servo Motor and the Other External Hardware Modeules
	
	UltraSonic_init();
	Lcd_init();
	DcMotor_init();
	Servo_init();
	//Move Servo At Position zero at first
	Possition_Zero();

	while(1){
		//Clear Lcd To Update the Distance
		Lcd_Poss(0,0);
		//Display The Distance on LCD
		Lcd_DisplayStr("Dis= ");
		LCD_DisplayFloat(GET_Distance());
		//Check if there is an object in front of the vehicle
		if(GET_Distance()<=40){
			//Stop the Car
			Stop();
			//turn servo at position 90
			Possition_90()			
			//Check if there is an object in right of the vehicle
			if(GET_Distance()<=40){
				//turn servo at position 180
				Possition_180();
				//Check if there is an object in left of the vehicle
				if(GET_Distance()<=40){
					//if there was an object of it's left the car should stop
					Stop();
				}
				else{
					//if not the left side is the suitable side
					TurnLeft();
				//Move to Position 90 first to adjust the servo on right position
					Possition_90();
					_delay_ms(500);
					Possition_Zero();
					GoForward();
				}

			}
			else{
				//if the right side is the suitable one go right
				TurnRight();
				Possition_Zero();

				GoForward();

			}

		}
		else
			//if there was no object in front of the car
			GoForward();
	}


	return 0;

}
