/*
 * Ex5.c
 *
 *  Created on: Sep 8, 2023
 *      Author: smartypc
 */

#include "stdio.h"
#define pi 3.1415926
#define area(rad) (pi*rad*rad)
int main(){
	float r;
	printf("Enter the radius:");
	fflush(stdin); fflush(stdout);
	scanf("%f",&r);
	printf("Area = %.2f",area(r));
}
