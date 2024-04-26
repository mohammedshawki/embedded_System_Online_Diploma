/*
 * alarm_a.h
 *
 *  Created on: Apr 21, 2024
 *      Author: smartypc
 */

#ifndef ALARM_A_H_
#define ALARM_A_H_
#include"state.h"
#include "driver.h"
//init
void alarm_act_init();
//state id
enum {
	waiting,
	alarm_on_S,
	alarm_off_S
}alarm_act_id;
//fun
STATE_DEFINE(waiting);
STATE_DEFINE(led_on);
STATE_DEFINE(led_off);
//pointer to fn
extern void(*P_alarm_act)();


#endif /* ALARM_A_H_ */
