/*
 * sec1_unit7_lab1.c
 *
 * Created: 8/14/2024 4:52:04 PM
 * Author : smartypc
 */ 

#include "Memmap.h"
#include "bitconfig.h"
#define  F_CPU 8000000UL
#include "util/delay.h"



int main(void)
{
	DDRA = 0xFF;
	int i;
	
	while (1)
	{
		for(i=0; i<8; i++)
		{
			toggle_bit(PORTA, i);
			_delay_ms(500);
		}
		
		for(i=7; i>=0; i--)
		{
			toggle_bit(PORTA, i);
			_delay_ms(500);
		}
	}
}
