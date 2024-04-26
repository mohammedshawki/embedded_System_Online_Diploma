/*
 * fifo.h
 *
 *  Created on: Apr 24, 2024
 *      Author: smartypc
 */

#ifndef FIFO_H_
#define FIFO_H_
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "conio.h"

#define DPRINTF(...)		{fflush(stdout); \
		fflush(stdin); \
		printf(__VA_ARGS__); \
		fflush(stdout); \
		fflush(stdin);}

//student data
typedef struct {
	char f_name[50];
	char s_name[50];
	int roll;
	float GPA;
	int cid[10];
}student;

student buffer[100];

//fifo defination
typedef struct {
	unsigned int count ;
	unsigned int length;
	student* head;
	student* base;
	student* tail;
}FIFO_BUF_t;

FIFO_BUF_t students_fifo;

//fifo status

typedef enum{
	FIFO_NO_Error,
	FIFO_FULL,
	FIFO_empty,
	FIFO_NULL,
	FIFO_Error
}FIFO_Buf_status;

//APIs
FIFO_Buf_status fifo_init(FIFO_BUF_t* fifo, student* buf, unsigned int length);
int check_roll_number(FIFO_BUF_t* fifo, int n);
FIFO_Buf_status add_student_from_file(FIFO_BUF_t* fifo);
FIFO_Buf_status add_student_manually(FIFO_BUF_t* fifo);
FIFO_Buf_status find_rl(FIFO_BUF_t* fifo);
FIFO_Buf_status find_fn(FIFO_BUF_t* fifo);
FIFO_Buf_status find_c(FIFO_BUF_t* fifo);
FIFO_Buf_status tot_S_number(FIFO_BUF_t* fifo);
FIFO_Buf_status delete_student(FIFO_BUF_t* fifo);
FIFO_Buf_status update_student(FIFO_BUF_t* fifo);
FIFO_Buf_status show_all_information(FIFO_BUF_t* fifo);



#endif /* FIFO_H_ */
