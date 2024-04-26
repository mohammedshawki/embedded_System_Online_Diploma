/*
 * PS_D.h
 *
 *  Created on: Apr 21, 2024
 *      Author: smartypc
 */

#ifndef PS_D_H_
#define PS_D_H_
#define pressure_sensor_delay 60000
#include "state.h"
#include"driver.h"
void PSD_init();

//state
enum {
	PS_reading_s,
	PS_waiting_s
}PS_state_id;

//func
STATE_DEFINE(PS_reading);
STATE_DEFINE(PS_waiting);


//pointer to func
extern void (*P_PSD_state)();

#endif /* PS_D_H_ */
