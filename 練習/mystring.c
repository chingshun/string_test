#include<stdio.h>
#include<stdlib.h>
#include"mystring.h"

/*-------------------------------------------------------------------------------------------*/
void test(mystring *string)
{
	printf("string = %s\n", string->p);
	printf("string->p = %p\n", string->p);
	printf("string->length = %d\n", string->length);
}

int getlength(char *str)
{
	if (str == NULL)
	{
		return 0;
	}
	else
	{
		int i = 1;
		while (*str != '\0')
		{
			str++;
			i++;
		}
		return i;
	}
}

void *copystring(char* target, const char *source)
{
	if (target == NULL || source == NULL)
	{
		return NULL;
	}
	char *oritar = target;
	//printf("%d %d\n", getlength(target), getlength(source));
	if (getlength(target) < getlength(source))
	{
		target = (char *)realloc(target, getlength(source));
	}
	printf("%d %d\n", sizeof(target), sizeof(source));
	while (*source != '\0')
	{
		*target = *source;
		target++;
		source++;
	}
	*target = '\0';
	target = oritar;
	return oritar;
}

char *samechar(char *str1, char *str2)
{
	if (*str1 == *str2)
	{
		return str1;
	}
	return NULL;
}
/*-------------------------------------------------------------------------------------------*/
void initstring(mystring *string)
{
	string->p = NULL;
	string->length = 0;
}

void withstring(mystring *string, char *str)
{
	string->p = (char *)calloc(getlength(str), sizeof(char));
	string->length = getlength(str);
	char *origin = string->p;
	char *p = str;
	while (*p != '\0')
	{
		*string->p = *p;
		p++;
		string->p++;
	}
	*string->p = '\0';
	string->p = origin;
}

void printstring(mystring *string)
{
	printf("%s\n", string->p);
}

void addstring(mystring *string, char *str)
{
	if (string->p != NULL && str != NULL)
	{
		string->p = (char *)realloc(string->p, string->length + getlength(str) - 1);
		char *orip = string->p;
		int strleng = getlength(str);
		for (int i = 0; i < string->length - 1; i++)
		{
			string->p++;
		}
		while (*str != '\0')
		{
			*string->p = *str;
			string->p++;
			str++;
		}
		*string->p = '\0';
		string->length = string->length + strleng - 1;
		string->p = orip;
	}

}

void run(mystring *string)
{
	system(string->p);
}

char *findsamestring(mystring *string, char *ch)
{
	if (string->p == NULL || ch == NULL || (string->length < getlength(ch)))
	{
		return NULL;
	}
	char *oristr = string->p;
	while (oristr + getlength(ch) - 2 != '\0')
	{
		for (int i = 0; i < getlength(ch) - 1; i++)
		{
			if (samechar(oristr + i, ch + i) != NULL)
			{
				if (i == getlength(ch) - 2)
				{
					return oristr;
				}
			}
			else
			{
				break;
			}
		}
		oristr++;
	}
	return NULL;
}

void *deletstring(mystring *string, char *ch)
{
	char *samestr = findsamestring(string, ch);
	if (samestr == NULL)
	{
		return;
	}
	else
	{
		while (*(samestr + getlength(ch) - 1) != '\0')
		{
			//printf("%c", *(samestr + getlength(ch) - 1));
			*samestr = *(samestr + getlength(ch) - 1);
			samestr++;
		}
		*samestr = '\0';
		string->length = string->length - getlength(ch) + 1;
		//*samestr = *(samestr + getlength(ch) - 1);
	}
}

void myaddstring(mystring *string, char *str, int pos)
{
	if (pos > string->length || pos < 0 || str == NULL)
	{
		return;
	}
	else
	{
		int totallength = string->length + getlength(str) - 1;
		string->p = (char *)realloc(string->p, totallength);
		char *p = string->p;
		p[totallength - 1] = '\0';
		string->length = string->length + getlength(str) - 1;
		for (int i = totallength - 2; i > pos ; i--)
		{
			p[i] = p[i - getlength(str) + 1];
		}
		int length = getlength(str)-1;

		for (int i = pos; i < pos + length; i++)
		{	
			p[i] = *str;
			str++;
		}
	}
}