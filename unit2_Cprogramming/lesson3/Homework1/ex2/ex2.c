/*

 * ex2.c
 *
 *  Created on: Aug 1, 2023
 *      Author: smartypc
 */

#include "stdio.h"
int main()
{
	int a;
	printf("Enter a integer: ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&a);
	printf("you entered: %d",a);
}
