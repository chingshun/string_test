#include<stdio.h>
#include<stdlib.h>
#include"mystring.h"

void main()
{
	mystring string;
	initstring(&string);
	withstring(&string, "no");
	//printstring(&string);
	//addstring(&string, "ad");
	//printstring(&string);
	//run(&string);
	//char *same = findsamestring(&string, "epa");
	//test(&string);
	//deletstring(&string, "pad");
	myaddstring(&string, "tepad", 2);
	//test(&string);
	//printstring(&string);


	run(&string);
	system("pause");
}