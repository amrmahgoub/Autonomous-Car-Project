/*
 * DcMotor.h
 *
 *  Created on: Feb 17, 2022
 *      Author: Amr Mahgoub
 */

#ifndef DCMOTOR_H_
#define DCMOTOR_H_
#include"Dioo.h"
#include"delay.h"
#include"STD.h"
#define Enable1 (4)
#define Enable2 (5)
#define Input1 (3)
#define Input2  (4)
#define Input3  (5)
#define Input4  (6)
typedef enum{
	Clockwise,
	AntiClockwise
}direction;
typedef enum{
	MotorA,
	MotorB
}Motor_type;
void DcMotor_init(void);
void MoveInDirction(direction D,Motor_type M);
void Stop();
void TurnLeft();
void TurnRight();
void GoForward();
#endif /* DCMOTOR_H_ */
