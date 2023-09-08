/*
 * Ex3.c
 *
 *  Created on: Sep 5, 2023
 *      Author: smartypc
 */

#include "stdio.h"
#include "string.h"
int main()
{
	char str[50];
	char rstr[50];
	char* Pstr=str;
	char* Prstr=rstr;
	int i = 0;
	printf("input a string:");
	fflush(stdin); fflush(stdout);
	gets(str);
	while(*Pstr)
	{
		Pstr++;
		i++;
	}
	while(i>0)
	{
		Pstr--;
		*Prstr=*Pstr;
		Prstr++;
		i--;
	}
	*Prstr='\0';
	printf("reverse of string:%s",rstr);


}
