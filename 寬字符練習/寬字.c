#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<Windows.h>
void main1()
{
	wchar_t ch = L'��';
	printf("%d\n", sizeof(ch));
	setlocale(LC_ALL, "zh-tw");
	wprintf(L"%wc\n", ch);
	wchar_t str[100] = L"�a��ڥ��޻LJJfs";
	wprintf(L"%s", str);

	system("pause");
}

void main()
{
	MessageBox(0, L"�޻L", L"���", 0);
	system("pause");
}