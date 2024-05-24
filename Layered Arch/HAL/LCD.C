/*
 * LCD.c
 *
 *  Created on: Feb 10, 2022
 *      Author: user
 *      RS:PB1
 *      RW:PB2
 *      EN:PB3
 *      DATA:PA4,PA5,PA6,PA7
 */
#include"LCD.h"
//Configure the LCD PINS
void Lcd_init(void){
	DIO_ConfigChannel(DIO_PORTA,DIO_PIN4,OUTPUT);
	DIO_ConfigChannel(DIO_PORTA,DIO_PIN5,OUTPUT);
	DIO_ConfigChannel(DIO_PORTA,DIO_PIN6,OUTPUT);
	DIO_ConfigChannel(DIO_PORTA,DIO_PIN7,OUTPUT);

	DIO_ConfigChannel(DIO_PORTB,DIO_PIN1,OUTPUT); /*RS*/
	DIO_ConfigChannel(DIO_PORTB,DIO_PIN2,OUTPUT);/*RW*/
	DIO_ConfigChannel(DIO_PORTB,DIO_PIN3,OUTPUT);/*EN*/
	DIO_WriteChannel(DIO_PORTB,DIO_PIN2,STD_LOW);
	_delay_ms(15);
	Lcd_Cmd(3);
	_delay_ms(5);
	Lcd_Cmd(3);
	_delay_us(100);
	Lcd_Cmd(3);
	Lcd_Cmd(2);
	Lcd_Cmd(LCD_4BIT_MODE);
	Lcd_Poss(0,0);
}
//Enable pulses to Send The Data
static void Enable_pulse(void){
	//Follow The Datasheet of The LCD_16*2
	DIO_WriteChannel(DIO_PORTB,DIO_PIN3,STD_HIGH);
	_delay_us(1);
	DIO_WriteChannel(DIO_PORTB,DIO_PIN3,STD_LOW);
	_delay_ms(2);
}
/*Let RS = 1 To Send Data*/
//Send the data to LCD by the given Instructions (Data Sheet)
void Lcd_Data(u8 Data){
	u8 High_Nibble=Data;
	u8 Low_Nibble=Data<<4;
	DIO_WriteChannel(DIO_PORTB,DIO_PIN1,STD_HIGH);
	DIO_WriteGroup(DIO_PORTA,LCD_MASK,High_Nibble);
	/*Enable Pulse*/
	Enable_pulse();

	DIO_WriteGroup(DIO_PORTA,LCD_MASK,Low_Nibble);
	Enable_pulse();

}
/*Let RS = 0 To Send Command*/
//Send Commands To LCD Same As the Data
void Lcd_Cmd(lcd_Cmd_type cmd){
	u8 High_Nibble=cmd;
	u8 Low_Nibble=cmd<<4;
	DIO_WriteChannel(DIO_PORTB,DIO_PIN1,STD_LOW);
	DIO_WriteGroup(DIO_PORTA,LCD_MASK,High_Nibble);
	/*Enable Pulse*/
	Enable_pulse();

	DIO_WriteGroup(DIO_PORTA,LCD_MASK,Low_Nibble);
	Enable_pulse();


}
//Function To display Character of 8 Bits
void Lcd_DisplayChr(u8 chr){
	Lcd_Data(chr);
}
//Function To Display String
void Lcd_DisplayStr(u8* str){
	while(*str!='\0'){
		Lcd_DisplayChr(*str);
		str++;
	}
}
//Move to A certain Position of rows and Columns
void Lcd_Poss(u8 row,u8 col){
	switch(row){
	case 0:
		Lcd_Cmd(LCD_0x80+col);
		break;
	case 1:
		Lcd_Cmd(LCD_0xC0+col);
		break;
	}
}
//Display a Number more than 1 Digit
void Lcd_Displayu8(u16 num){
	Lcd_DisplayChr(num/1000+'0');
	Lcd_DisplayChr(num%1000/100+'0');
	Lcd_DisplayChr(num%1000%100/10+'0');
	Lcd_DisplayChr(num%1000%100%10%10+'0');
}
//Display a Decimal Number
void LCD_DisplayFloat(f64 floatNum){
	u16 intPart=0;
	f64 fractionTemp=0;
	u16 fractionPart=0;

	intPart	=(u16)floatNum;
	fractionTemp=floatNum-intPart;
	fractionPart=fractionTemp*10000;
	Lcd_Displayu8(intPart);
	Lcd_DisplayChr('.');
	Lcd_Displayu8(fractionPart);

}

