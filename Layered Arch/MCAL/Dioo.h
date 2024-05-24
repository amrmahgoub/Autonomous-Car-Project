/*
 * Dioo.h
 *
 *  Created on: Feb 8, 2022
 *      Author: Amr Mahgoub
 */

#ifndef DIOO_H_
#define DIOO_H_
#include"MATH_BTS.H"
#include"DIO.H"
#include"STD.H"
/* USER DATA DEFINITION*/
typedef enum{
	DIO_PORTA,
	DIO_PORTB,
	DIO_PORTC,
	DIO_PORTD,
}port_type;
typedef enum{
	DIO_PIN0,
	DIO_PIN1,
	DIO_PIN2,
	DIO_PIN3,
	DIO_PIN4,
	DIO_PIN5,
	DIO_PIN6,
	DIO_PIN7,
}pin_type;
typedef enum{
	INPUT,
	OUTPUT
}direction_type;
typedef enum{
	STD_LOW,
	STD_HIGH
}level_type;
/*Functions prototypes*/
void DIO_ConfigChannel(port_type port,pin_type pin,direction_type dirction);
void DIO_WriteChannel(port_type port,pin_type pin,level_type level);
level_type ReadChannel(port_type port,pin_type pin);
void DIO_TOGGLE(port_type port,pin_type pin);
void DIO_WriteGroup(port_type port,u8 mask,u8 data);

#endif /* DIOO_H_ */
