/*
 * Ex2.c
 *
 *  Created on: Aug 29, 2023
 *      Author: smartypc
 */

#include "stdio.h"
#include "conio.h"
struct Sdistance{
	int feet;
	float inch;
};
int main(){
	struct Sdistance x, y, z;
	int i;
	printf("Enter the information for 1st distance:\n");
	printf("Enter feet:");
	fflush(stdin); fflush(stdout);
	scanf("%d",&x.feet);
	printf("Enter inch:");
	fflush(stdin); fflush(stdout);
	scanf("%f",&x.inch);
	printf("Enter the information for 2nd distance:\n");
	printf("Enter feet:");
	fflush(stdin); fflush(stdout);
	scanf("%d",&y.feet);
	printf("Enter inch:");
	fflush(stdin); fflush(stdout);
	scanf("%f",&y.inch);
	z.feet= x.feet + y.feet;
	z.inch= x.inch + y.inch;
	if(z.inch>=12)
	{
		i = z.inch / 12;
		z.feet +=i;
		z.inch = z.inch -12;
		printf("Sum of distance=%d'-%.1f\"",z.feet, z.inch);
	}
	else
		printf("Sum of distance=%d'-%.1f",z.feet, z.inch);
}
