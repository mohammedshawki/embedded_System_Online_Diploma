/*
 * Q9.c
 *
 *  Created on: Aug 24, 2023
 *      Author: smartypc
 */


#include "stdio.h"
#include "string.h"
void rev(char s[], int size);
int main()
{
	char s[100];
	int size;
	printf("Enter ur name:");
	fflush(stdin); fflush(stdout);
	gets(s);
	size=strlen(s);
	rev(s, size);
}
void rev(char s[], int size)
{
	char r[100]="";
	char t[100];
    int i;
	for(i=0;i<=size;i++)
	{
		t[i]= s[i];
		if(	t[i]==' ')
			break;
	}
	t[i]=0;
	strcat(r, s+i);
	strcat(r, " ");
	strcat(r, t);
	printf("after swapping:%s",r);
}
