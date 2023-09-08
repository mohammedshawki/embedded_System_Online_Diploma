/*
 * Ex5.c
 *
 *  Created on: Sep 8, 2023
 *      Author: smartypc
 */

#include "stdio.h"
struct Sdata{
	char name[100];
	int id;
};
int main(){
	struct Sdata employees[2]={"mohammed", 2005};
	struct Sdata* ptrstr = &employees;
	printf("%s\n%d",ptrstr->name, ptrstr->id);


}
