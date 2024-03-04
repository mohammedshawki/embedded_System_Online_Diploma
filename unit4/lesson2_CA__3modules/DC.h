/*
 * CA.h
 *
 *  Created on: Mar 3, 2024
 *      Author: smartypc
 */

#ifndef DC_H_
#define DC_H_

#include "state.h"
//states
enum{
	DC_idle,
	DC_busy
}DC_state_id;

//func
void DC_init();
STATE_DEFINE(DC_idle);
STATE_DEFINE(DC_busy);

//pointer to func
extern void (*DC_state)();

#endif /* DC_H_ */
