/*
 * CA.h
 *
 *  Created on: Mar 3, 2024
 *      Author: smartypc
 */

#ifndef CA_H_
#define CA_H_

#include "state.h"
//states
enum{
	CA_waiting,
	CA_driving
}CA_state_id;

//func
STATE_DEFINE(CA_waiting);
STATE_DEFINE(CA_driving);

//pointer to func
extern void (*CA_state)();

#endif /* CA_H_ */
