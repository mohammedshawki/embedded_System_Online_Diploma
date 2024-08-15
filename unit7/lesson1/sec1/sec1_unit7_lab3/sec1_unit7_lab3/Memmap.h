/*
 * Memmap.h
 *
 * Created: 8/14/2024 4:54:23 PM
 *  Author: smartypc
 */ 


#ifndef MEMMAP_H_
#define MEMMAP_H_

//PORTA
#define PORTA *((volatile unsigned char*)(0x3B))
#define DDRA  *((volatile unsigned char*)(0x3A))
#define PINA  *((volatile unsigned char*)(0x39))

//PORTC
#define PORTC *((volatile unsigned char*)(0x35))
#define DDRC  *((volatile unsigned char*)(0x34))
#define PINC  *((volatile unsigned char*)(0x33))

//PORTD
#define PORTD *((volatile unsigned char*)(0x32))
#define DDRD  *((volatile unsigned char*)(0x31))
#define PIND  *((volatile unsigned char*)(0x30))



#endif /* MEMMAP_H_ */