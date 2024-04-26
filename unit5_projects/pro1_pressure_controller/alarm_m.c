/*
 * alarm_m.c
 *
 *  Created on: Apr 21, 2024
 *      Author: smartypc
 */
#include "alarm_m.h"
void (*P_alarm_mon_state)();

//receive signal from sys_alg
void high_pressure_detected ()
{
	//set pointer to alarm on fn
	P_alarm_mon_state = STATE(alarm_on) ;
}
//alarm off state
STATE_DEFINE(alarm_off)
{
	//state id
	alarm_monitor_id = alarm_off_s ;
	//send signal
	stop_alarm();
}

STATE_DEFINE(alarm_on)
{
	//state id
	alarm_monitor_id = alarm_on_s ;
	//send signal >> start alarm
	start_alarm();
	//delay
	Delay(alarm_delay);
	//set pointer to waiting state
	P_alarm_mon_state = STATE(waiting_alarm_mon) ;
}
STATE_DEFINE(waiting_alarm_mon)
{
	//state id
	alarm_monitor_id = waiting_S ;
	//set pointer to alarm off fn
	P_alarm_mon_state = STATE(alarm_off) ;

}



