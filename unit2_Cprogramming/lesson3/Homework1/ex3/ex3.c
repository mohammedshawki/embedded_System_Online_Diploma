/*

 * ex3.c
 *
 *  Created on: Aug 1, 2023
 *      Author: smartypc
 */

#include "stdio.h"
int main()
{
	int a, b;
	printf("Enter two integers");
	fflush(stdin); fflush(stdout);
	scanf("%d %d",&a, &b);
	printf("sum: %d",a+b);
}
