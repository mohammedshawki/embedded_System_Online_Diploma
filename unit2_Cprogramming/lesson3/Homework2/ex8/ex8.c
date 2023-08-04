/*
 * ex8.c
 *
 *  Created on: Aug 3, 2023
 *      Author: smartypc
 */


#include"stdio.h"
int main()
{
	char c;
	float a, b;
	printf("Enter operator either + or - or * or / : ");
	fflush(stdin); fflush(stdout);
	scanf("%c",&c);
	printf("Enter two operands: ");
	fflush(stdin); fflush(stdout);
	scanf("%f %f",&a, &b);
	switch(c)
	{
	case'+':
	printf("%.1f + %.1f = %.1f",a, b, a+b);
	break;
	case'-':
	printf("%.1f - %.1f = %.1f",a, b, a-b);
	break;
	case'*':
	printf("%.1f * %.1f = %.1f",a, b, a*b);
	break;
	case'/':
	printf("%.1f / %.1f = %.1f",a, b, a/b);
	break;
	default:
		printf("Error! operator is not correct");

	}
}
