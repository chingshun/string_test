#include<stdio.h>
#include<stdlib.h>

struct CString
{
	char *p;
	int length;
};
typedef struct CString mystring;

void test(mystring *string); //���ը��
int getlength(char *str);
void *copystring(char* target, const char *source);
char *samechar(char *str1, char *str2);

void initstring(mystring *string);						//��l�Ƽƾ��ܶq
void withstring(mystring *string, char *str);			//�ᤩ�r��
void printstring(mystring *string);						//���L�r��
void addstring(mystring *string, char *str);		    //�̫�W���r��
void run(mystring *string);							    //����r��
char *findsamestring(mystring *string, char *ch);		//��ۦP�r��
void *deletstring(mystring *string, char *ch);			//�R���r��
void myaddstring(mystring *string, char *str, int pos); //���N��m�W�[