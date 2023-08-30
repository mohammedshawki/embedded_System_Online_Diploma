/*
 * Ex1.c
 *
 *  Created on: Aug 28, 2023
 *      Author: smartypc
 */

#include "stdio.h"
#include "conio.h"
struct SData{
	char name[20];
	int roll;
	float mark;
};
int main()
{
	struct SData students;
	printf("Enter information of students:");
	fflush(stdin); fflush(stdout);
	printf("\nEnter name:");
	fflush(stdin); fflush(stdout);
	scanf("%s",&students.name);
	printf("Enter roll number:");
	fflush(stdin); fflush(stdout);
	scanf("%d",&students.roll);
	printf("Enter marks:");
	fflush(stdin); fflush(stdout);
	scanf("%f",&students.mark);
	printf("Displaying information:\n");
	printf("name:%s\nroll:%d\nmark:%.2f",students.name, students.roll, students.mark);
}
