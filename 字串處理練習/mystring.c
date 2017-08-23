#include "mystring.h"

int mystrlen(char *p)
{
	if (p == NULL)
	{
		return -1;
	}
	int length = 0;
	while (*p != '\0')
	{
		length++;
		p++;
	}
	return length;
}

char *mystrcpy(char *dest, const char *source)
{
	if (dest == NULL || source == NULL)
	{
		return NULL;
	}
	char *destbak = dest;
	while (*source != '\0')
	{
		*dest = *source;

		source++;
		dest++;
	}
	*dest = '\0';
	return destbak;
}

void init(mystring *string)
{
	string->p = NULL;
	string->reallength = 0;
}
void initwithlength(mystring *string, int length)
{
//	string->p = (char *)malloc(length * sizeof(char));
	string->p = (char *)calloc(length, sizeof(char));
	string->reallength = 10;
}
void initwithstring(mystring *string, char *copystring)
{
	int length = strlen(copystring);
	string->p = calloc(length + 1, sizeof(char));
	mystrcpy(string->p, copystring);
	string->reallength = length + 1;
}
void printfstring(mystring *string)
{
	printf("string=%s\n", string->p);
}

void backaddchar(mystring *string, char ch)
{
	if (strlen(string->p) + 1 == string->reallength)
	{
		string->p = realloc(string->p, string->reallength + 1);
		string->reallength += 1;
		string->p[string->reallength - 2] = ch;
		string->p[string->reallength - 1] = '\0';
	}
	else
	{
		int nowlength = mystrlen(string->p);
		string->p[nowlength] = ch;
		string->p[nowlength + 1] = '\0';
	}

	//string->p = realloc(string->p, strlen(string->p));
}

void backaddstring(mystring *string, char *str)
{
	int nowmystringlength = mystrlen(string->p);
	int addstringlength = mystrlen(str);
	if (nowmystringlength + addstringlength + 1 > string->reallength)
	{
		int needaddlength = nowmystringlength + addstringlength + 1 - string->reallength;
		string->p = (char *)realloc(string->p, string->p + needaddlength);
		strcat(string->p, str);
		string->reallength += needaddlength;
	}
	else
	{
		strcat(string->p, str);
	}
}

void run(mystring *string)
{
	system(string->p);
}

char *mystrcat(char *dest, const char *source)
{
	if (dest == NULL || source == NULL)
	{
		return NULL;
	}
	else
	{
		char *destbak = dest;
		while (*dest != '\0')
		{
			dest++;
		}
		while (*source!='\0')
		{
			*dest = *source;
			dest++;
			source++;
		}
		*dest = '\0';
		return destbak;
	}
}