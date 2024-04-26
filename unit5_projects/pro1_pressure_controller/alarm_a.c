/*
 * alarm_a.c
 *
 *  Created on: Apr 21, 2024
 *      Author: smartypc
 */

#include "alarm_a.h"
void(*P_alarm_act)();
//init
void alarm_act_init(){
	//by default (led is off)
	stop_alarm();
	//set pointer >> waiting state
	P_alarm_act = STATE(waiting);
}

//waiting state
STATE_DEFINE(waiting)
{
	//state id
	alarm_act_id = waiting ;
}
void stop_alarm()
{
	Set_Alarm_actuator(1);
	//set pointer
	P_alarm_act = STATE(led_off) ;

}
void start_alarm()
{
	Set_Alarm_actuator(0);
	//set pointer
	P_alarm_act = STATE(led_on) ;
}
STATE_DEFINE(led_on)
{
	//state id
	alarm_act_id = alarm_on_S ;
	//set pointer
	P_alarm_act = STATE(waiting) ;

}
STATE_DEFINE(led_off)
{
	//state id
	alarm_act_id = alarm_off_S ;
	//set pointer
	P_alarm_act = STATE(waiting) ;
}

