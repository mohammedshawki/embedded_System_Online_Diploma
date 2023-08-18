/*
 * Ex3.c
 *
 *  Created on: Aug 17, 2023
 *      Author: smartypc
 */

#include "stdio.h"
void rev();
int main()
{
	printf("Enter a sentence");
	fflush(stdin); fflush(stdout);
    rev();

}
void rev()
{
	char c;
	scanf("%c",&c);
	if(c!= '\n')
	{
		rev();
		printf("%c",c);
	}
}
