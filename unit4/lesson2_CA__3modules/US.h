/*
 * CA.h
 *
 *  Created on: Mar 3, 2024
 *      Author: smartypc
 */

#ifndef US_H_
#define US_H_
#include "state.h"
enum {
	US_busy
}US_state_id;
//func
void US_init();
STATE_DEFINE(US_busy);

//pointer to func
extern void (*US_state)();

#endif /* US_H_ */
