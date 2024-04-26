/*
 * alarm_m.h
 *
 *  Created on: Apr 21, 2024
 *      Author: smartypc
 */

#ifndef ALARM_M_H_
#define ALARM_M_H_
#include "state.h"
#include "driver.h"

#define alarm_delay 60

//states
enum {
	alarm_off_s,
	alarm_on_s,
	waiting_S
}alarm_monitor_id;

//func
STATE_DEFINE(alarm_off);
STATE_DEFINE(alarm_on);
STATE_DEFINE(waiting_alarm_mon);

//pointer to func
extern void (*P_alarm_mon_state)();


#endif /* ALARM_M_H_ */
