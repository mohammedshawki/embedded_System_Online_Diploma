/*

 * ex5.c
 *
 *  Created on: Aug 3, 2023
 *      Author: smartypc
 */


#include "stdio.h"
int main()
{
	char c;
	printf("Enter a character: ");
	fflush(stdin); fflush(stdout);
	scanf("%c",&c);
	if((c<'a'&&c>'z')||(c<'A'&&c>'Z'))
		printf("%c is an alphabet",c);
	else
		printf("%c is not alphabet",c);
}
