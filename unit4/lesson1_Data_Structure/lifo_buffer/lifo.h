/*
 * lifo.h
 *
 *  Created on: Oct 20, 2023
 *      Author: smartypc
 */

#ifndef LIFO_H_
#define LIFO_H_
#include "stdio.h"
//type definition

typedef struct {
	unsigned int count ;
	unsigned int length ;
	unsigned int* base ;
	unsigned int* head ;
}LIFO_Buf_t;

typedef enum {
	LIFO_no_error,
	LIFO_full,
	LIFO_empty,
	LIFO_null
}LIFO_status;

//APIs

LIFO_status LIFO_Add_item(LIFO_Buf_t* lifo_buf, unsigned int item);
LIFO_status LIFO_get_item(LIFO_Buf_t* lifo_buf, unsigned int* item);
LIFO_status LIFO_init(LIFO_Buf_t* lifo_buf, unsigned int* buf, unsigned int length);
#endif /* LIFO_H_ */
