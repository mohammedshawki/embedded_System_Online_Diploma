/*

 * Ex3.c
 *
 *  Created on: Aug 7, 2023
 *      Author: smartypc
 */

#include "stdio.h"
int main()
{
	char a[100];
	int i, j=0, temp;
	printf("Enter the string: ");
	fflush(stdin); fflush(stdout);
	gets(a);
	i = 0;
	j = strlen(a)-1;
	while(i<j)
	{
		temp = a[i];
		a[i] = a[j];
		a[j] = temp;
		i++;
		j--;
	}
    printf("\nReverse string is: %s",a);
    return 0;
}
