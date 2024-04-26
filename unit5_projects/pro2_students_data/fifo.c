/*
 * fifo.c
 *
 *  Created on: Apr 24, 2024
 *      Author: smartypc
 */
#include "fifo.h"

FIFO_Buf_status fifo_init(FIFO_BUF_t* fifo, student* buf, unsigned int length )
{
	//buf is valid or not
	if(buf == NULL)
		return FIFO_NULL ;
	//init
	fifo->base = buf ;
	fifo->head = buf ;
	fifo->tail = buf ;
	fifo->count = 0 ;
	fifo->length = length ;
	return FIFO_NO_Error ;
}

FIFO_Buf_status add_student_from_file(FIFO_BUF_t* fifo)
{
	//fifo is valid or not
	if(!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_NULL ;
	//fifo is full?
	if(fifo->count==fifo->length)
		return FIFO_FULL ;
	char firstName[50], lastName[50];
	int roll_number, cid[5], file_count=0, line=0;
	float GPA;
	FILE* fptr = fopen("student.txt", "r");
	if(fptr == NULL)
	{
		DPRINTF("file not found\n");
		return FIFO_Error ;
	}
	//read from file
	while(fscanf(fptr, "%d %s %s %f %d %d %d %d %d [^\n]",&roll_number,firstName, lastName,&GPA, &cid[0], &cid[1], &cid[2], &cid[3], &cid[4] ) != EOF)
	{
		if(fifo->count == fifo->length)
		{
			DPRINTF("fifo is full\n");
			return FIFO_FULL;
		}
		if(check_roll_number(fifo, roll_number) == 0)
		{
			DPRINTF("[ERROR] : in line %d >> roll number is already taken\n",line);
			line++;
			continue;
		}
		fifo->head->roll = roll_number ;
		fifo->head->GPA = GPA ;
		strcpy(fifo->head->f_name, firstName);
		strcpy(fifo->head->s_name, lastName);
		for(int j=0;j<5;j++)
		{
			fifo->head->cid[j] = cid[j];
		}
		fifo->head++;
		fifo->count++;
		file_count++;
		line++;
		DPRINTF("[INFO] : student details is added successfully\n");
	}
	//close the file
	fclose(fptr);
	DPRINTF("student added : %d\n",file_count);
	return FIFO_NO_Error ;
}
int check_roll_number(FIFO_BUF_t* fifo, int n)
{

	student* temp = fifo->base ;
	for(int i=0;i<(fifo->count);i++)
	{
		if(n == temp->roll)
			return 0 ;
		temp++;
	}
	return 1 ;
}
FIFO_Buf_status add_student_manually(FIFO_BUF_t* fifo)
{
	//fifo is valid or not
	if(!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_NULL ;
	//fifo is full?
	if(fifo->count==fifo->length)
		return FIFO_FULL ;

	int roll_n;
	DPRINTF("Enter the roll number: ");
	scanf("%d",&roll_n);
	if(check_roll_number(fifo, roll_n) == 0)
	{
		DPRINTF("[ERROR] : Roll number is already taken\n");
		return FIFO_Error ;
	}
	else
	{
		fifo->head->roll = roll_n;
		DPRINTF("Enter the first name of the student: ");
		gets(fifo->head->f_name);
		DPRINTF("Enter the second name of the student: ");
		gets(fifo->head->s_name);
		DPRINTF("Enter the GPA you obtained: ");
		scanf("%f",&fifo->head->GPA);
		DPRINTF("Enter the course ID of each course:\n");
		for(int i=0;i<5;i++)
		{
			DPRINTF("course %d id: ",i+1 );
			scanf("%d",&fifo->head->cid[i]);
		}
		DPRINTF("[INFO] : student details is added successfully\n");
		fifo->count++;
		fifo->head++;
		return FIFO_NO_Error ;
	}
}

FIFO_Buf_status find_rl(FIFO_BUF_t* fifo)
{
	//fifo is valid or not
	if(!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_NULL ;
	//fifo is empty
	if(fifo->count==0)
		return FIFO_empty ;
	int roll_num;
	student* current_student = fifo->base;
	DPRINTF("Enter the student roll number: ");
	scanf("%d",&roll_num);
	for(int i=0;i<fifo->count;i++,current_student++)
	{
		if(roll_num == current_student->roll)
		{
			DPRINTF("the student details are:\n");
			DPRINTF("The first name : %s\n",current_student->f_name);
			DPRINTF("the second name : %s\n",current_student->s_name);
			DPRINTF("The GPA : %.2f\n",current_student->GPA);
			DPRINTF("The courses ID:\n");
			for(int j=0;j<5;j++)
			{
				DPRINTF("%d\t",current_student->cid[j]);
			}
			return FIFO_NO_Error;
		}
	}
	DPRINTF("[ERROR] : Roll number %d not found",roll_num);
	return FIFO_Error;
}

FIFO_Buf_status find_fn(FIFO_BUF_t* fifo)
{
	//fifo is valid or not
	if(!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_NULL ;
	//fifo is empty
	if(fifo->count==0)
		return FIFO_empty ;
	char temp[50];
	int flag = 0;
	student* c_student = fifo->base;
	DPRINTF("Enter the first name:");
	gets(temp);
	for(int i=0;i<fifo->count;i++)
	{
		if(strcmp(temp,c_student->f_name) == 0)
		{
			DPRINTF("the student details are:\n");
			DPRINTF("The first name : %s\n",c_student->f_name);
			DPRINTF("the second name : %s\n",c_student->s_name);
			DPRINTF("The GPA : %.2f\n",c_student->GPA);
			DPRINTF("The courses ID:\n");
			for(int j=0;j<5;j++)
			{
				DPRINTF("%d\t",c_student->cid[j]);
			}
			DPRINTF("\n===============================\n");
			c_student++;
			flag++;
			continue ;
		}
		c_student++;
	}
	if(flag)
		return FIFO_NO_Error ;
	else {
	DPRINTF("[ERROR] : first name %s not found",temp);
	return FIFO_Error ;
	}
}
FIFO_Buf_status find_c(FIFO_BUF_t* fifo)
{
	//fifo is valid or not
	if(!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_NULL ;
	//fifo is empty
	if(fifo->count==0)
		return FIFO_empty ;
	int c_number, flag=0;
	student* c_student = fifo->base;
	DPRINTF("Enter the course id: ");
	scanf("%d",&c_number);
	for(int i=0;i<fifo->count;i++,c_student++)
	{
		for(int j=0;j<5;j++)
		{
			if(c_number == c_student->cid[j])
			{
				DPRINTF("the student details are:\n");
				DPRINTF("The first name : %s\n",c_student->f_name);
				DPRINTF("the second name : %s\n",c_student->s_name);
				DPRINTF("The GPA : %.2f\n",c_student->GPA);
				DPRINTF("==============================\n");
				flag++;
				break;
			}
		}
	}
	if(flag)
		return FIFO_NO_Error ;
	else
	{
		DPRINTF("course id %d not found\n",c_number);
		return FIFO_Error ;
	}
}

FIFO_Buf_status tot_S_number(FIFO_BUF_t* fifo)
{
	//fifo is valid or not
	if(!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_NULL ;
	//fifo is empty
	if(fifo->count==0){
		DPRINTF("The total number of students: %d\n",fifo->count);
		return FIFO_empty ;
	}
	DPRINTF("The total number of students: %d\n",fifo->count);
	DPRINTF("[INFO] : You can add up to 100 students\n");
	DPRINTF("[INFO] : u can add %d more students\n",fifo->length - fifo->count);
	return FIFO_NO_Error ;
}

FIFO_Buf_status delete_student(FIFO_BUF_t* fifo)
{
	//fifo is valid or not
	if(!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_NULL ;
	//fifo is empty
	if(fifo->count==0)
		return FIFO_empty ;
	int roll_number , flag = 0;
	int count = fifo->count - 1 ;
	student* current_stdudent = fifo->base ;
	DPRINTF("Enter the roll number which you want to delete : ");
	scanf("%d",&roll_number);
	for(int i=0;i<fifo->count;i++)
	{
		if(current_stdudent->roll == roll_number)
		{
			for(int j=i;j<count;j++)
			{
				buffer[j] = buffer[j+1];
				flag++;
			}
		}
		else
			current_stdudent++;
	}
	if(flag)
	{
		DPRINTF("[INFO] : Student with roll number %d deleted successfully\n", roll_number);
		fifo->count--;
		return FIFO_NO_Error ;
	}
	else
	{
		DPRINTF("[ERROR] : Student with roll number %d not found\n", roll_number);
		return FIFO_Error ;
	}

}

FIFO_Buf_status update_student(FIFO_BUF_t* fifo)
{
	//fifo is valid or not
	if(!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_NULL ;
	//fifo is empty
	if(fifo->count==0)
		return FIFO_empty ;
	student* cstudent = fifo->base;
	int roll_number, choice, flag=0;
	DPRINTF("Enter the roll number to update the student: ");
	scanf("%d",&roll_number);
	for(int i=0;i<fifo->count;i++)
	{
		if(roll_number == cstudent->roll)
		{
			DPRINTF("1. first name\n");
			DPRINTF("2. second name\n");
			DPRINTF("3. roll no\n");
			DPRINTF("4. GPA\n");
			DPRINTF("5. courses\n");
			DPRINTF("Enter the option number\n");
			scanf("%d",&choice);
			switch (choice) {
			case 1:
				DPRINTF("Enter the new first name: ");
				gets(cstudent->f_name);
				DPRINTF("[info] : UPDATED SUCCESSFULLY \n");
				flag++;
				break;
			case 2:
				DPRINTF("Enter the new second name: ");
				gets(cstudent->s_name);
				DPRINTF("[info] : UPDATED SUCCESSFULLY \n");
				flag++;
				break ;
			case 3:
				DPRINTF("Enter the new roll number: ");
				scanf("%d",&cstudent->roll);
				DPRINTF("[info] : UPDATED SUCCESSFULLY \n");
				flag++;
				break ;
			case 4:
				DPRINTF("Enter the new GPA: ");
				scanf("%f",&cstudent->GPA);
				DPRINTF("[info] : UPDATED SUCCESSFULLY \n");
				flag++;
				break;
			case 5:
				DPRINTF("Enter the new courses id: ");
				for(int j=0;j<5;j++)
				{
					scanf("%d",&cstudent->cid[j]);
				}
				DPRINTF("[info] : UPDATED SUCCESSFULLY \n");
				flag++;
				break;
			default:
				DPRINTF("Wrong choice\n");
				break;
			}
		}
		else{
			cstudent++;
			continue;
		}
		break;
	}
	if(flag)
		return FIFO_NO_Error ;
	else
	{
		DPRINTF("roll number %d not found",roll_number);
		return FIFO_Error ;
	}
}

FIFO_Buf_status show_all_information(FIFO_BUF_t* fifo)
{
	//fifo is valid or not
	if(!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_NULL ;
	//fifo is empty
	if(fifo->count==0)
		return FIFO_empty ;
	student* current_s = fifo->base;
	for(int i=0;i<fifo->count;i++,current_s++)
	{
		DPRINTF("The first name : %s\n",current_s->f_name);
		DPRINTF("the second name : %s\n",current_s->s_name);
		DPRINTF("The GPA : %.2f\n",current_s->GPA);
		DPRINTF("The courses ID:\n");
		for(int j=0;j<5;j++)
		{
			printf("%d\t",current_s->cid[j]);
		}
		DPRINTF("\n==========================\n");
	}
	return FIFO_NO_Error ;
}














