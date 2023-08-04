/*

 * ex4.c
 *
 *  Created on: Aug 1, 2023
 *      Author: smartypc
 */

#include "stdio.h"
int main()
{
	float a, b;
	printf("Enter two numbers: ");
	fflush(stdin); fflush(stdout);
	scanf("%f %f",&a, &b);
	printf("product: %f",a*b);
}
