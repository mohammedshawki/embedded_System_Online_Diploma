/*

 * ex4.c
 *
 *  Created on: Aug 3, 2023
 *      Author: smartypc
 */


#include "stdio.h"
int main()
{
	float a;
	printf("Enter a number: ");
	fflush(stdin); fflush(stdout);
	scanf("%f",&a);	
	if(a>0)
		printf("%.2f is positive",a);
	else if(a==0)
		printf("you entered zero",a);
	else
		printf("%.2f is negative",a);

}
