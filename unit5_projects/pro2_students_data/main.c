/*
 * main.c
 *
 *  Created on: Apr 24, 2024
 *      Author: smartypc
 */

#include "fifo.h"

int main()
{
	int option;
	fifo_init(&students_fifo, buffer, 100);
	while(1)
	{
		DPRINTF("\n=======================");
		DPRINTF("\n\t choose from the following options");
		DPRINTF("\n1- add student from file");
		DPRINTF("\n2- add student manually");
		DPRINTF("\n3- find student by using roll number");
		DPRINTF("\n4- find student by using his first name");
		DPRINTF("\n5- find students in the same course");
		DPRINTF("\n6- show the students number in the list");
		DPRINTF("\n7- delete student");
		DPRINTF("\n8- update student information");
		DPRINTF("\n9- show all students informations");
		DPRINTF("\nEnter the option number: ");
		scanf("%d",&option);
		switch (option) {
			case 1:
				add_student_from_file(&students_fifo);
				break;
			case 2:
				add_student_manually(&students_fifo);
				break;
			case 3:
				find_rl(&students_fifo);
				break;
			case 4 :
				find_fn(&students_fifo);
				break;
			case 5 :
				 find_c(&students_fifo);
				 break;
			case 6 :
				tot_S_number(&students_fifo);
				break ;
			case 7 :
				 delete_student(&students_fifo);
				 break;
			case 8 :
				update_student(&students_fifo);
				 break;
			case 9 :
				show_all_information(&students_fifo);
				break;
			default:
				DPRINTF("wrong option\n");
				break;
		}
	}

	return 1;
}


