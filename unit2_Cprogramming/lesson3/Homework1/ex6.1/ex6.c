/*

 * ex6.c
 *
 *  Created on: Aug 1, 2023
 *      Author: smartypc
 */

#include "stdio.h"
int main()
{
	float a, b, x;
	printf("Enter value of a: ");
	fflush(stdin); fflush(stdout);
	scanf("%f",&a);
	printf("Enter value of b: ");
	fflush(stdin); fflush(stdout);
	scanf("%f",&b);
	x=a;
	a=b;
	b=x;
	printf("After swapping, value of a = %f\r\n",a);
    printf("After swapping, value of b = %f",b);
}
