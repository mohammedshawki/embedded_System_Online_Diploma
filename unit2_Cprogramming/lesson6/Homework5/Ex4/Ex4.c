/*
 * Ex4.c
 *
 *  Created on: Aug 29, 2023
 *      Author: smartypc
 */

#include "stdio.h"
struct SData{
	char name[100];
	float marks;
};
int main()
{
	struct SData students[10];
	int i;
	printf("Enter informatin of studends:\n");
	fflush(stdin); fflush(stdout);
	for(i=0;i<10;i++)
	{
		printf("for roll number %d\n",i+1);
		printf("Enter name:");
		fflush(stdin); fflush(stdout);
		scanf("%s",&students[i].name);
		printf("Enter marks:");
		fflush(stdin); fflush(stdout);
		scanf("%f",&students[i].marks);
	}
	printf("Displaying information of students:\n");
	for(i=0;i<10;i++)
	{
		printf("information of roll number %d:\n",i+1);
		printf("name:%s\n",students[i].name);
		printf("mark:%f\n",students[i].marks);
	}


}
