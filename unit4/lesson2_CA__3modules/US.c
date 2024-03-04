/*
 * main.c
 *
 *  Created on: Mar 3, 2024
 *      Author: smartypc
 */
#include "US.h"

void (*US_state)();
//variables
uint32_t US_distance = 0 ;

//func
void US_init()
{
		printf("US_init >>> Done\n");
}
//random distance func (sensor)
int rand_distance(int l, int r, int count)
{
		for(int i=0;i<count;i++)
		{
			int rand_value = (rand() % (r-l+1)) + l ;
			return rand_value ;
		}
}

STATE_DEFINE(US_busy)
{
	//state name
	US_state_id = US_busy ;
	//measure the distance
	US_distance = rand_distance(45,55,1);
	printf("US_busy: US_distance = %d\n",US_distance);
	//send signal
	US_set_distance(US_distance);
	//set pointer to busy state
	US_state = STATE(US_busy) ;

}

