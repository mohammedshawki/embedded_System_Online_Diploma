/*
 * bus.h
 *
 *  Created on: May 5, 2024
 *      Author: smartypc
 */

#ifndef BUS_H_
#define BUS_H_
#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include "string.h"

#define DPRINTF(...)		{fflush(stdout); \
		fflush(stdin); \
		printf(__VA_ARGS__); \
		fflush(stdout); \
		fflush(stdin);}
// bus seats are 33

//passenger data
typedef struct{
	char first_name[50];
	char second_name[50];
	long phone_number;
	int seat_number ;
	char flag;
}passenger_t;
//number of chairs >> 33
passenger_t no_of_chairs1[33], no_of_chairs2[33], no_of_chairs3[33], no_of_chairs4[33], no_of_chairs5[33];


//func
void login();
void bus_list();
void ticket_booking();
void ticket_cacelation();
void checking_bus_status();




#endif /* BUS_H_ */
