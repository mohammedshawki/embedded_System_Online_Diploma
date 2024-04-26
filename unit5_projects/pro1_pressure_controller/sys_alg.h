/*
 * sys_alg.h
 *
 *  Created on: Apr 21, 2024
 *      Author: smartypc
 */

#ifndef SYS_ALG_H_
#define SYS_ALG_H_
#include "state.h"
#include"driver.h"
//state
enum {
	high_pressure_detected_s
}sys_alg_id;

//func
STATE_DEFINE(high_pressure_detected);

//pointer to func
extern void (*P_sysalg_state)();
#endif /* SYS_ALG_H_ */
