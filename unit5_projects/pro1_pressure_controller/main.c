/*
 * main.c
 *
 *  Created on: Apr 21, 2024
 *      Author: smartypc
 */

#include "driver.h"
#include "state.h"
#include "PS_D.h"
#include "sys_alg.h"
#include "alarm_m.h"
#include "alarm_a.h"

void (*P_PSD_state)() = PSD_init;
void (*P_sysalg_state)() = STATE(high_pressure_detected);
void (*P_alarm_mon_state)() = STATE(alarm_off);
void(*P_alarm_act)() = alarm_act_init ;

void main()
{
	while(1)
	{
		P_PSD_state();
		P_sysalg_state();
		P_alarm_mon_state();
		P_alarm_act();
	}
}
