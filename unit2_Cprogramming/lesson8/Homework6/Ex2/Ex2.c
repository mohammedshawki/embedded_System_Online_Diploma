/*
 * Ex2.c
 *
 *  Created on: Sep 5, 2023
 *      Author: smartypc
 */

#include "stdio.h"
int main()
{
	char alph[27];
	char* Pc = alph;
	int i;
	printf("The alphabets are:\n");
	for(i=0;i<26;i++)
	{
		*Pc= i+'A';
		printf("%c ",*Pc);
		Pc++;
	}
}
