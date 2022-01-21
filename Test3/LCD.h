/*
 * LCD.h
 *
 * Created: 16.01.2022 18:37:51
 *  Author: USER
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "main.h"
//---------------
#define e1 PORTD|=0b00001000 // установка линии E в 1
#define e0 PORTD&=0b11110111 // установка линии E в 0
#define rs1 PORTD|=0b00000100 // установка линии RS в 1 (данные)
#define rs0 PORTD&=0b11111011 // установка линии RS в 0 (команда)
//---------------
void sendChar(unsigned char c);
void init_LCD(void);
void setPos(unsigned char x, unsigned y);
void str_LCD(char str[]);

#endif /* LCD_H_ */