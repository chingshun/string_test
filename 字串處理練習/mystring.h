#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct CString
{
	char *p;
	int reallength;
};
typedef struct CString mystring;




void init(mystring *string);
void initwithlength(mystring *string,int length);
void initwithstring(mystring *string,char *copystring);
void printfstring(mystring *string);
void backaddchar(mystring *string, char ch);
void backaddstring(mystring *string,char *str);
void run(mystring *string);