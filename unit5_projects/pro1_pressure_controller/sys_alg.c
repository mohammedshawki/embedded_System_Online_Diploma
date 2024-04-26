/*
 * sys_alg.c
 *
 *  Created on: Apr 21, 2024
 *      Author: smartypc
 */

#include "sys_alg.h"
//variables
unsigned int pressure_value_ = 0, threshold = 20;
//P to func
void (*P_sysalg_state)();
//receive signal (pressure value)
void send_Pval(int p)
{
	pressure_value_ = p ;
	P_sysalg_state = STATE(high_pressure_detected) ;
}

STATE_DEFINE(high_pressure_detected)
{
	//state id
	sys_alg_id = high_pressure_detected_s ;
	//compare pressure value with threshold value
	if(pressure_value_ > threshold)
	{
		//send signal to alarm monitor (P > 20 bar)
		high_pressure_detected ();
		P_sysalg_state = send_Pval ;
	}
	else
	{
		P_sysalg_state = send_Pval ;
	}

}
