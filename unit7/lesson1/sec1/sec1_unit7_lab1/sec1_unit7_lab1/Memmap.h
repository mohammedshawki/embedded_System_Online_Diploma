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





#endif /* MEMMAP_H_ */