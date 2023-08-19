/*
 * Q
1.c
 *
 *  Created on: Aug 18, 2023
 *      Author: smartypc
 */


#include "stdio.h"
int main()
{
	char str[100];
	char name[100];
	int a;
	printf("Enter a string: ");
	fflush(stdin); fflush(stdout);
	gets(str);
	printf("Enter your name: ");
	fflush(stdin); fflush(stdout);
	gets(name);
	a = stricmp(str,name);
	if(a==0)
		printf("identical");
	else
		printf("different");

}
