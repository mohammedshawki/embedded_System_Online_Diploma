/*
 * Ex1.c
 *
 *  Created on: Aug 7, 2023
 *      Author: smartypc
 */


#include "stdio.h"
#include "string.h"
int main()
{
	char a[100];
	char c;
	int i, n=0;
	printf("Enter a string: ");
	fflush(stdin); fflush(stdout);
	gets(a);
	printf("Enter a character to find frequency: ");
	fflush(stdin); fflush(stdout);
	scanf("%c",&c);
	for(i=0;i<sizeof(a)&&a[i]!=0;i++)
	{
		if(c==a[i])
			n++;
	}
			printf("frequency of %c : %d", c, n );


}
