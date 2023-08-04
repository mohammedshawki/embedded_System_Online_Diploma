/*

 * ex5.c
 *
 *  Created on: Aug 1, 2023
 *      Author: smartypc
 */

#include "stdio.h"
int main()
{
	char c;
	printf("Enter a character: ");
	fflush(stdin); fflush(stdout);
	scanf("%c", &c);
	printf("ASCII value of %c =%d ",c,c);
}
