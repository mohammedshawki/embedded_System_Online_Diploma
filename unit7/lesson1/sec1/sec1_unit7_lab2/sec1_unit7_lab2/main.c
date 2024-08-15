/*
 * sec1_unit7_lab2.c
 *
 * Created: 8/15/2024 4:19:36 PM
 * Author : smartypc
 */ 

#include "Memmap.h"
#include "bitconfig.h"
#define  F_CPU 8000000UL
#include "util/delay.h"



int main(void)
{
	DDRA = 0xFF ;
	reset_bit(DDRC,0);
	set_bit(PORTC,0);
	
	int flag = 1 ;
	
	while (1)
	{
		if(read_bit(PINC,0) == 0)
		{
			while(read_bit(PINC,0) == 0);
			for(int i=0;i<flag;i++)
			{
				set_bit(PORTA,i);
				
			}
			flag++;
			
		}
	}
}

