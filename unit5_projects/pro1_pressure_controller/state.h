/*
 * state.h
 *
 *  Created on: Apr 21, 2024
 *      Author: smartypc
 */

#ifndef STATE_H_
#define STATE_H_
#include "stdio.h"
#include "stdlib.h"


#define STATE_DEFINE(_statfunc_) void st_##_statfunc_()
#define STATE(_statfunc_) st_##_statfunc_

//connections
// 1- send signal (pressure value)
void send_Pval(int p);
// 2- send signal to alarm monitor to infore high pressure detected
void high_pressure_detected ();
// 3- send signal to alarm actuator (alarm off)
void stop_alarm();
// 4- send signal to alarm actuator (alarm on)
void start_alarm();
#endif /* STATE_H_ */
