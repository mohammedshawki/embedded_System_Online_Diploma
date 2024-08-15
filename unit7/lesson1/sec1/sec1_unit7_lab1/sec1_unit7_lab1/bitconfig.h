/*
 * bitconfig.h
 *
 * Created: 8/14/2024 4:55:37 PM
 *  Author: smartypc
 */ 


#ifndef BITCONFIG_H_
#define BITCONFIG_H_

#define set_bit(reg,bit_number) reg |= (1<<bit_number)
#define reset_bit(reg,bit_number) reg &= ~(1<<bit_number)
#define toggle_bit(reg,bit_number) reg ^= (1<<bit_number)
#define read_bit(reg,bit_number) ((reg & (1<<bit_number)) >> bit_number ) 




#endif /* BITCONFIG_H_ */