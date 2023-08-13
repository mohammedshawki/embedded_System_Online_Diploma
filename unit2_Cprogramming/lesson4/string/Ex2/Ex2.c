/*

 * Ex2.c
 *
 *  Created on: Aug 7, 2023
 *      Author: smartypc
 */


#include "stdio.h"
int main()
{
	char a[100];
	int i, length=0;
	printf("Enter a string: ");
	fflush(stdin); fflush(stdout);
	gets(a);
	for(i=0;a[i]!=0;i++)
	{
		length++;
	}
	printf("Length of string: %d",length);
}
