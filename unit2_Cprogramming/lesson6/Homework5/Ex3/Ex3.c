/*
 * Ex3.c
 *
 *  Created on: Aug 29, 2023
 *      Author: smartypc
 */

#include "stdio.h"
#include "conio.h"
struct Snumbers{
	double x;    //real part
	double y;    //imaginary part
};
struct Snumbers add(struct Snumbers a, struct Snumbers b)
{
	struct Snumbers c;
	c.x = a.x + b.x;
	c.y = a.y + b.y;
	return c;
}
int main(){
	struct Snumbers a, b, c;
	printf("Enter real and imaginary respectively:");
	fflush(stdin); fflush(stdout);
	scanf("%lf %lf",&a.x, &a.y);
	printf("Enter real and imaginary respectively:");
	fflush(stdin); fflush(stdout);
	scanf("%lf %lf",&b.x, &b.y);
	c = add(a, b);
	printf("sum = %.2lf + %.2lfi",c.x, c.y);
}
