#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include "mystring.h"

void main()
{
	mystring string1;
	initwithstring(&string1, "note");
	printfstring(&string1);
	//backaddchar(&string1, 'd');
	backaddstring(&string1, "pad");
	run(&string1);


	system("pause");
}