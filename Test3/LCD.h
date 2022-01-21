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
#define e1 PORTD|=0b00001000 // ��������� ����� E � 1
#define e0 PORTD&=0b11110111 // ��������� ����� E � 0
#define rs1 PORTD|=0b00000100 // ��������� ����� RS � 1 (������)
#define rs0 PORTD&=0b11111011 // ��������� ����� RS � 0 (�������)
//---------------
void sendChar(unsigned char c);
void init_LCD(void);
void setPos(unsigned char x, unsigned y);
void str_LCD(char str[]);

#endif /* LCD_H_ */