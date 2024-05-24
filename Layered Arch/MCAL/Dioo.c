/*
 * Dioo.c
 *
 *  Created on: Feb 8, 2022
 *      Author: Amr Mahgoub
 */
#include"Dioo.h"
#include"MATH_BTS.H"
#include"DIO.H"
void DIO_ConfigChannel(port_type port,pin_type pin,direction_type dirction){
	switch(port){
	case DIO_PORTA:
		if(dirction==INPUT){
			CLR_BIT(DIO_DDRA_REG,pin);
		}
		else{
			SET_BIT(DIO_DDRA_REG,pin);
		}
		break;
	case DIO_PORTB:
		if(dirction==INPUT){
			CLR_BIT(DIO_DDRB_REG,pin);
		}
		else{
			SET_BIT(DIO_DDRB_REG,pin);
		}

		break;
	case DIO_PORTC:
		if(dirction==INPUT){
			CLR_BIT(DIO_DDRC_REG,pin);
		}
		else{
			SET_BIT(DIO_DDRC_REG,pin);
		}

		break;
	case DIO_PORTD:
		if(dirction==INPUT){
			CLR_BIT(DIO_DDRD_REG,pin);
		}
		else{
			SET_BIT(DIO_DDRD_REG,pin);
		}

		break;
	}
}
void DIO_WriteChannel(port_type port,pin_type pin,level_type level){
	switch(port){
	case DIO_PORTA:
		if(level==STD_HIGH){
			SET_BIT(DIO_PORTA_REG,pin);
		}
		else{
			CLR_BIT(DIO_PORTA_REG,pin);
		}
		break;
	case DIO_PORTB:
		if(level==STD_HIGH){
			SET_BIT(DIO_PORTB_REG,pin);
		}
		else{
			CLR_BIT(DIO_PORTB_REG,pin);
		}
		break;
	case DIO_PORTC:
		if(level==STD_HIGH){
			SET_BIT(DIO_PORTC_REG,pin);
		}
		else{
			CLR_BIT(DIO_PORTC_REG,pin);
		}
		break;
	case DIO_PORTD:
		if(level==STD_HIGH){
			SET_BIT(DIO_PORTD_REG,pin);
		}
		else{
			CLR_BIT(DIO_PORTD_REG,pin);
		}
		break;

	}
}
level_type ReadChannel(port_type port,pin_type pin){
	level_type result;
	switch(port){
	case DIO_PORTA:
		if(CHCK_BIT(DIO_PINA_REG,pin))
			result=STD_HIGH;
		else
			result= STD_LOW;
		break;
	case DIO_PORTB:
		if(CHCK_BIT(DIO_PINB_REG,pin))
			result= STD_HIGH;
		else
			result= STD_LOW;
		break;
	case DIO_PORTC:
		if(CHCK_BIT(DIO_PINC_REG,pin))
			result= STD_HIGH;
		else
			result=STD_LOW;
		break;
	case DIO_PORTD:
		if(CHCK_BIT(DIO_PIND_REG,pin))
			result=STD_HIGH;
		else
			result= STD_LOW;
		break;
	}
	return result;
}
void DIO_TOGGLE(port_type port,pin_type pin){
	switch(port){
	case DIO_PORTA:
		TOGGLE_BIT(DIO_PORTA_REG,pin);
		break;
	case DIO_PORTB:
			TOGGLE_BIT(DIO_PORTB_REG,pin);
			break;
	case DIO_PORTC:
			TOGGLE_BIT(DIO_PORTC_REG,pin);
			break;
	case DIO_PORTD:
			TOGGLE_BIT(DIO_PORTD_REG,pin);
			break;
	}
}
void DIO_WriteGroup(port_type port,u8 mask,u8 data){
	switch(port){
	case DIO_PORTA:
		DIO_PORTA_REG=(DIO_PORTA_REG&~mask)|(data&mask);
		break;
	case DIO_PORTB:
			DIO_PORTB_REG=(DIO_PORTB_REG&~mask)|(data&mask);
			break;
	case DIO_PORTC:
			DIO_PORTC_REG=(DIO_PORTC_REG&~mask)|(data&mask);
			break;
	case DIO_PORTD:
			DIO_PORTD_REG=(DIO_PORTD_REG&~mask)|(data&mask);
			break;
	}
}
