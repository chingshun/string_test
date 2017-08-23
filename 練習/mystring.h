#include<stdio.h>
#include<stdlib.h>

struct CString
{
	char *p;
	int length;
};
typedef struct CString mystring;

void test(mystring *string); //代刚ㄧ计
int getlength(char *str);
void *copystring(char* target, const char *source);
char *samechar(char *str1, char *str2);

void initstring(mystring *string);						//﹍て计沮跑秖
void withstring(mystring *string, char *str);			//结ぉ﹃
void printstring(mystring *string);						//ゴ﹃
void addstring(mystring *string, char *str);		    //程糤﹃
void run(mystring *string);							    //磅︽﹃
char *findsamestring(mystring *string, char *ch);		//т﹃
void *deletstring(mystring *string, char *ch);			//埃﹃
void myaddstring(mystring *string, char *str, int pos); //ヴ種竚糤