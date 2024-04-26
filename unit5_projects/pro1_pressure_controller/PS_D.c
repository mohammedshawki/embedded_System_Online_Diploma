/*
 * PS_D.c
 *
 *  Created on: Apr 21, 2024
 *      Author: smartypc
 */

#include "PS_D.h"

//variables
unsigned int Pressure_value ;
//pointer to func
void (*P_PSD_state)();
//init func
void PSD_init()
{
	//GPIO_INITIALIZATION
	GPIO_INITIALIZATION();
	//set pointer to reading state
	P_PSD_state = STATE(PS_reading) ;
}
//reading pressure from sensor
STATE_DEFINE(PS_reading)
{
	//state id
	PS_state_id = PS_reading_s;
	//sensor reading
	Pressure_value = getPressureVal();
	//send signal (pressure value) to (sys_alg)
	send_Pval(Pressure_value);
	//go to waiting state and wait for timer expiration
	P_PSD_state = STATE(PS_waiting);
}
STATE_DEFINE(PS_waiting)
{
	//state id
	PS_state_id = PS_waiting_s;
	//delay
	Delay(pressure_sensor_delay) ;
	//set pointer >> reading state again
	P_PSD_state = STATE(PS_reading);
}

