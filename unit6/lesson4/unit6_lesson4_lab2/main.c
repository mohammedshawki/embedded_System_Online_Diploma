/*
 * main.c
 *
 *  Created on: Jul 24, 2024
 *      Author: smartypc
 */
#include "avr/interrupt.h"
#include "avr/io.h"
#include "util/delay.h"

#define set_bit(address, bit) address |= (1<<bit)
#define reset_bit(address, bit) address &= ~(1<<bit)
#define Toggle_bit(address, bit) address ^= (1<<bit)



#define IO_base 0x20

#define DDRD *((volatile unsigned int*)(IO_base + 0x11))
#define PORTD *((volatile unsigned int*)(IO_base + 0x12))

#define INT_MCUCR *((volatile unsigned int*)(IO_base + 0x35))
#define INT_MCUCSR *((volatile unsigned int*)(IO_base + 0x34))
#define INT_GICR *((volatile unsigned int*)(IO_base + 0x3B))
#define INT_SREG *((volatile unsigned int*)(IO_base + 0x3F))

void main(void)
{
	//configure pin trigger
	// INT0 >> logical
	set_bit(INT_MCUCR,0);
	reset_bit(INT_MCUCR,1);
	//INT1 >> rising edge
	set_bit(INT_MCUCR,2);
	set_bit(INT_MCUCR,3);
	//INT2 >> failing edge
	reset_bit(INT_MCUCSR,6);
	//===================================
	//enable INT 0,1,2
	set_bit(INT_GICR,5);
	set_bit(INT_GICR,6);
	set_bit(INT_GICR,7);
	//===================================
	//Global Interrupt Enable
	set_bit(INT_SREG, 7);
	//===================================
	//PortD >> pin 5,6,7 >> o/p
	set_bit(DDRD,5);
	set_bit(DDRD,6);
	set_bit(DDRD,7);
	//===================================
	while(1)
	{
		reset_bit(PORTD,5);
		reset_bit(PORTD,6);
		reset_bit(PORTD,7);
	}
}

ISR(INT0_vect)
{
	set_bit(PORTD,5);
	_delay_ms(1000);
}
ISR(INT1_vect)
{
	set_bit(PORTD,6);
	_delay_ms(1000);
}
ISR(INT2_vect)
{
	set_bit(PORTD,7);
	_delay_ms(1000);
}
