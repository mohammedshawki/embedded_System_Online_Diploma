/*

\ * ex3.c
 *
 *  Created on: Aug 3, 2023
 *      Author: smartypc
 */

#include "stdio.h"
int main()
{
	float a, b, c;
	printf("Enter three numbers: ");
	fflush(stdin); fflush(stdout);
	scanf("%f %f %f",&a, &b, &c);
	if(a>b&&a>c)
		printf("the largest number is %f",a);
	if(b>a&&b>c)
		printf("the largest number is %f",b);
	if(c>a&&c>b)
		printf("the largest number is %f",c);


}
