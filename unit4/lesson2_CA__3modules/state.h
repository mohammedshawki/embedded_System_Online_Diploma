/*
 * CA.h
 *
 *  Created on: Mar 3, 2024
 *      Author: smartypc
 */

#ifndef STATE_H_
#define STATE_H_
#include "stdio.h"
#include "stdlib.h"

typedef unsigned int uint32_t;

#define STATE_DEFINE(_statfunc_) void st_##_statfunc_()
#define STATE(_statfunc_) st_##_statfunc_

//connections
void US_set_distance(int distance);
void DC_motor_set_speed(int speed);


#endif /* STATE_H_ */
