/*
 * LCD.h
 *
 *  Created on: Feb 10, 2022
 *      Author: user
 */

#ifndef LCD_H_
#define LCD_H_
#include"Dioo.h"
#include"delay.h"
#define LCD_MASK 0xF0
//Commands Of LCD
typedef enum{
	LCD_CLEAR=0x01,
	LCD_CURSOR_OFF=0x0C,
	LCD_CURSOR_ON=0x0F,
	LCD_4BIT_MODE=0x28,
	LCD_8BIT_MODE=0x38,
	LCD_ON=0x0F,
	LCD_CURSOR_UNDERLINE=0x0E,
	LCD_CURSOR_SHIFT_LEFT=0x10,
	LCD_CURSOR_SHIFT_RIGHT=0x14,
	LCD_CURSOR_INCREMENT=0x66,
	LCD_CGRAM_START_ADDRESS=0x40,
	LCD_0x3=0x3,
	LCD_0x2=0x2,
	LCD_0x80,
	LCD_0xC0=0xC0



}lcd_Cmd_type;
void Lcd_init(void);
 void Lcd_Data(u8 Data);
void Lcd_Cmd(u8 cmd);
 void Lcd_DisplayChr(u8 chr);
void Lcd_DisplayStr(u8* str);
void Lcd_Poss(u8 row,u8 col);
void Lcd_Displayu8(u16 chr);
void LCD_DisplayFloat(f64 floatNum);


#endif /* LCD_H_ */
