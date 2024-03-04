/*
 * main.c
 *
 *  Created on: Mar 3, 2024
 *      Author: smartypc
 */

#include "DC.h"

void (*DC_state)();
//variables
uint32_t DC_speed;
//func
void DC_init()
{
	printf("DC_init >>> Done\n");
}

//receive signal
void DC_motor_set_speed(int speed)
{
	DC_speed = speed;
	DC_state = STATE(DC_busy);
	printf("CA -----speed = %d -----> Dc\n", DC_speed);
}
STATE_DEFINE(DC_idle)
{
	DC_state_id = DC_idle ;
	printf("DC_idle state: speed= %d\n",DC_speed);
}
STATE_DEFINE(DC_busy)
{
	DC_state_id = DC_busy ;
	printf("DC_busy state: speed= %d\n",DC_speed);
	DC_state = STATE(DC_idle);
}
