/*
* Test0.c
*
* Created: 08.01.2022 2:03:47
* Author : USER
*/

#include "main.h"
//---------------
void init_port(void)
{
	PORTD = 0x00;
	DDRD = 0xFF;
}
//---------------

int main(void)
{
	init_port(); //Инициализируем порты
	init_LCD(); //Инициализируем дисплей
	
	setPos(0, 0);
	str_LCD("Hello World!");
	
	setPos(3, 1);
	str_LCD("KekLol");
	
	while (1)
	{
		
	}
}
