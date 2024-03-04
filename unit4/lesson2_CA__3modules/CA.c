/*
 * main.c
 *
 *  Created on: Mar 3, 2024
 *      Author: smartypc
 */

#include "CA.h"

void (*CA_state)();
//variables
uint32_t CA_speed = 0, CA_distance = 0 , CA_threshold = 50 ;

//func
void US_set_distance(int distance)
{
	CA_distance = distance ;
	CA_state = (CA_distance <= CA_threshold) ? STATE(CA_waiting) : STATE(CA_driving) ;
	printf("US------distance = %d ------>CA\n",CA_distance);
}
STATE_DEFINE(CA_waiting)
{
	CA_state_id = CA_waiting ;
	printf("CA_waiting: distance = %d, speed = %d\n",CA_distance, CA_speed);
	//action
	CA_speed = 0 ;
	DC_motor_set_speed(CA_speed);
}
STATE_DEFINE(CA_driving)
{
	CA_state_id = CA_driving ;
	printf("CA_driving: distance = %d, speed = %d\n",CA_distance, CA_speed);
	//action
	CA_speed = 30 ;
	DC_motor_set_speed(CA_speed);
}

