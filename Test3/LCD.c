/*
 * LCD.c
 *
 * Created: 16.01.2022 18:43:22
 *  Author: USER
 */ 

#include "LCD.h"

void sendHalfByte(unsigned char c)
{
	c<<=4;
	e1; //включаем линию Е
	_delay_us(50);
	PORTD&=0b00001111; //стираем информацию на входах DB4-DB7, остальное не трогаем
	PORTD|=c;
	e0; //выключаем линию Е
	_delay_us(50);
}
//---------------
void sendByte(unsigned char c, unsigned char mode)
{
	if(mode == 0) rs0;
	else rs1;
	unsigned char hc=0;
	hc=c>>4;
	sendHalfByte(hc);
	sendHalfByte(c);
}
//---------------
void sendChar(unsigned char c)
{
	sendByte(c,1);
}
//---------------
void init_LCD(void)
{
	_delay_ms(15);
	sendHalfByte(0b00000011);
	_delay_ms(4);
	sendHalfByte(0b00000011);
	_delay_us(100);
	sendHalfByte(0b00000011);
	_delay_ms(1);
	sendHalfByte(0b00000010);
	_delay_ms(1);
	sendByte(0b00101000, 0); //4бит-режим (DL=0) и 2 линии (N=1)
	_delay_ms(1);
	sendByte(0b00001100, 0); //включаем изображение на дисплее (D=1), курсоры никакие не включаем (C=0, B=0)
	_delay_ms(1);
	sendByte(0b00000110, 0); //курсор (хоть он у нас и невидимый) будет двигаться влево
	_delay_ms(1);
}
//---------------
void setPos(unsigned char x, unsigned y)
{
	char adress;
	adress=(0x40*y+x)|0b10000000;
	sendByte(adress, 0);
}
//---------------
void str_LCD(char str[])
{
	for(int i = 0; str[i] != '\0'; i++) sendChar(str[i]);
}
//---------------
