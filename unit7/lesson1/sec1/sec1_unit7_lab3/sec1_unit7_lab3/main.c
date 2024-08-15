/*
 * sec1_unit7_lab3.c
 *
 * Created: 8/15/2024 10:03:53 PM
 * Author : smartypc
 */ 

#include "Memmap.h"
#include "bitconfig.h"
#define  F_CPU 8000000UL
#include "util/delay.h"

int main(void)
{
	DDRD = 0xFF ;
	
	reset_bit(DDRC,0);
	set_bit(PORTC,0);

	char flag=1;
	
    while (1) 
    {
		if(read_bit(PINC,0) == 0)
		{
			while(read_bit(PINC,0) == 0);
			for(char i=0;i<flag;i++)
			{
				set_bit(PORTD,i);
				if(i == 3){
					_delay_ms(1000);
				}
    }
	flag++;
	if(flag >= 5){
		PORTD = 0 ;
		flag = 1 ;
		
	}
}
	}
}

