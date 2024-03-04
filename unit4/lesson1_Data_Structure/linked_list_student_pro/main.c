/*
 * main.c
 *
 *  Created on: Oct 23, 2023
 *      Author: smartypc
 */

#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include "string.h"

#define DPRINTF(...)		{fflush(stdout); \
		fflush(stdin); \
		printf(__VA_ARGS__); \
		fflush(stdout); \
		fflush(stdin);}

struct SData{
	unsigned int ID;
	char name [40] ;
	float height ;
};

struct Sstudent{
	struct SData SData;
	struct Sstudent* P_next_student;
};
struct Sstudent* gp_first_student = NULL ;

void Add_student()
{
	struct Sstudent* P_new_student;
	struct Sstudent* P_last_student;
	char temp_text[40];

	//list is empty or not?
	if (gp_first_student == NULL)
	{
		//it is empty..so we need to create a new record
		P_new_student = (struct Sstudent*) malloc (1 * sizeof(struct Sstudent));
		//assign it to gp_first_student
		gp_first_student = P_new_student;
	}
	else
	{
		//it is not empty...we have some previous data and we need to add a new data
		P_last_student = gp_first_student ;
		while(P_last_student->P_next_student)
			P_last_student = P_last_student->P_next_student ;
		//create new record
		P_new_student = (struct Sstudent*) malloc (sizeof(struct Sstudent));
		//assign it to gp_first_student
		P_last_student->P_next_student = P_new_student;
	}
	//now we need to enter the new data
	DPRINTF("Enter the ID:");
	gets(temp_text);
	P_new_student->SData.ID = atoi (temp_text);

	DPRINTF("Enter the name:");
	gets(P_new_student->SData.name);

	DPRINTF("Enter the height:");
	gets(temp_text);
	P_new_student->SData.height = atof (temp_text);

	//set the next pointer (P_new_student) to NULL
	P_new_student->P_next_student = NULL ;

}

int Delete_student()
{
	char temp_text[40];
	int selected_ID;
	DPRINTF("Enter the student ID to be deleted:");
	gets(temp_text);
	selected_ID = atoi(temp_text);
	//the list is empty or not?
	if(gp_first_student)
	{
		struct Sstudent* P_previous_student = NULL;
		struct Sstudent* P_selected_student = gp_first_student ;

		//loop on all records
		while (P_selected_student)
		{
			//compare id
			if (P_selected_student->SData.ID == selected_ID)
			{
				if (P_previous_student)
				{
					P_previous_student->P_next_student = P_selected_student->P_next_student ;
				}
				else{
					gp_first_student = P_selected_student->P_next_student ;
				}
				free (P_selected_student);
				return 1;
			}
			//store previous record pointer
			P_previous_student = P_selected_student ;
			P_selected_student = P_selected_student->P_next_student ;
		}
	}
	DPRINTF("\n cannot find ID.");
	return 0;
}

void View_students()
{
	int count = 0;
	struct Sstudent* P_current_student = gp_first_student ;
	if (gp_first_student == NULL)
		DPRINTF("List is empty");

	while(P_current_student)
	{
		DPRINTF("\n-------------------------")
						DPRINTF("\n Record Number %d", count+1);
		DPRINTF("\n ID: %d",P_current_student->SData.ID);
		DPRINTF("\n name: %s",P_current_student->SData.name);
		DPRINTF("\n height: %.2f", P_current_student->SData.height);
		P_current_student = P_current_student->P_next_student;
		count++;
	}
}

void Delete_all()
{
	struct Sstudent* P_current_student = gp_first_student ;
	if (gp_first_student == NULL)
		DPRINTF("\nList is empty\n");

	while(P_current_student)
	{
		struct Sstudent* P_temp_student = P_current_student ;
		P_current_student= P_current_student->P_next_student;
		free (P_temp_student);
	}
	gp_first_student= NULL;
}

int specific_student()
{
	int count = 1 ;
	int sel_student ;
	//check list is empty or not
	if (gp_first_student == NULL)
		DPRINTF("List is empty\n");
	DPRINTF("Enter the student number:");
	scanf("%d",&sel_student);
	struct Sstudent* P_temp_student = gp_first_student ;
	while(P_temp_student)
	{
		if(sel_student == count)
		{
			DPRINTF("\n student Number %d", count);
			DPRINTF("\n ID: %d",P_temp_student->SData.ID);
			DPRINTF("\n name: %s",P_temp_student->SData.name);
			DPRINTF("\n height: %.2f", P_temp_student->SData.height);
			return 1;
		}
		else
		{
			count++;
			P_temp_student = P_temp_student->P_next_student;
		}

	}
	DPRINTF("Error\n");
	return 1;
}

void NO_of_student()
{
	//check list is empty or not
	if (gp_first_student == NULL)
		DPRINTF("List is empty");
	int count = 0;
	struct Sstudent* P_temp_student = gp_first_student ;
	while(P_temp_student)
	{
		count++;
		P_temp_student = P_temp_student->P_next_student ;
	}
	DPRINTF("number of students: %d",count);
}

int get_count(struct Sstudent* P_temp_student)
{
	if(P_temp_student == NULL){
		return 0;
	}
	else
	{
		P_temp_student = P_temp_student->P_next_student ;
		return 1 + get_count(P_temp_student);
	}

}

int NO_of_student_from_the_end()
{
	//check list is empty or not
	if (gp_first_student == NULL)
		DPRINTF("List is empty");
	int number, i;
	DPRINTF("choose the student number:");
	scanf("%d",&number);
	struct Sstudent* P_main = gp_first_student ;
	struct Sstudent* P_ref  =  gp_first_student ;
	//move the P_ref
	for (i = 0; i < number; i++) {
		if (P_ref == NULL) {
			DPRINTF("\n Invalid number.");
			return 1;
		}
		P_ref = P_ref->P_next_student;
	}
	//move 2 pointers
	while(P_ref)
	{
		P_main = P_main->P_next_student;
		P_ref = P_ref->P_next_student;
	}
	DPRINTF("\n student Number %d", number);
	DPRINTF("\n ID: %d",P_main->SData.ID);
	DPRINTF("\n name: %s",P_main->SData.name);
	DPRINTF("\n height: %.2f", P_main->SData.height);
	return 1;
}
void middle_ele()
{
	//check list is empty or not
	if (gp_first_student == NULL)
	{
		DPRINTF("List is empty");
	}
	else
	{
	struct Sstudent* P_slow =  gp_first_student ;
	struct Sstudent* P_fast =  gp_first_student ;
	int count = 1;
	//move 2 pointers
	while (P_fast)
	{
		P_fast = P_fast->P_next_student;
		P_fast = P_fast->P_next_student;
		P_slow = P_slow->P_next_student;
		count++;
	}
	// Print the middle student
	DPRINTF("\n student Number %d", count);
	DPRINTF("\n ID: %d",P_slow->SData.ID);
	DPRINTF("\n name: %s",P_slow->SData.name);
	DPRINTF("\n height: %.2f", P_slow->SData.height);
	}
}

void rev_list()
{
	// Check if the list is empty
	if (gp_first_student == NULL) {
		DPRINTF("\n Empty List");
	} else {
		struct Sstudent* P_CurrentStudent = gp_first_student;
		struct Sstudent* P_PreviousStudent = NULL;
		struct Sstudent* P_NextStudent = NULL;

		// Traverse the linked list and reverse the pointers
		while (P_CurrentStudent != NULL) {
			P_NextStudent = P_CurrentStudent->P_next_student;
			P_CurrentStudent->P_next_student = P_PreviousStudent;
			P_PreviousStudent = P_CurrentStudent;
			P_CurrentStudent = P_NextStudent;
		}

		// Update the pointer to the first student for the reversed list
		gp_first_student = P_PreviousStudent;
	}
	DPRINTF("====Reverse is done====");
}


void main()
{
	unsigned int c;
	unsigned int nodes_number;

	while (1)
	{
		DPRINTF("\n=======================");
		DPRINTF("\n\t choose from the following options");
		DPRINTF("\n 1: Add_student");
		DPRINTF("\n 2: delete_student");
		DPRINTF("\n 3: view_students");
		DPRINTF("\n 4: delete_all");
		DPRINTF("\n 5: view specific student");
		DPRINTF("\n 6: view No. of student");
		DPRINTF("\n 7: view No. of student---->by recursive way");
		DPRINTF("\n 8: view specific student from the end");
		DPRINTF("\n 9: view the middle element");
		DPRINTF("\n 10: reverse the list");

		DPRINTF("\n Enter option number:");
		scanf("%d",&c);

		DPRINTF("\n=======================\n");
		switch(c)
		{
		case 1:
			Add_student();
			break;
		case 2:
			Delete_student();
			break;
		case 3:
			View_students();
			break;
		case 4:
			Delete_all();
			break;
		case 5:
			specific_student();
			break;
		case 6:
			NO_of_student();
			break;
		case 7:
			nodes_number =  get_count(gp_first_student);
			DPRINTF("the number of students: %d",nodes_number);
			break;
		case 8:
			NO_of_student_from_the_end();
			break;
		case 9:
			middle_ele();
			break;
		case 10:
			rev_list();
			break;
		default:
			DPRINTF("\n wrong option");
		}
	}
}








