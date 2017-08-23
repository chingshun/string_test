#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<Windows.h>
void main1()
{
	wchar_t ch = L'«Ó';
	printf("%d\n", sizeof(ch));
	setlocale(LC_ALL, "zh-tw");
	wprintf(L"%wc\n", ch);
	wchar_t str[100] = L"µa»æ®Ú¥»½Þ»LJJfs";
	wprintf(L"%s", str);

	system("pause");
}

void main()
{
	MessageBox(0, L"½Þ»L", L"¨ä»æ", 0);
	system("pause");
}