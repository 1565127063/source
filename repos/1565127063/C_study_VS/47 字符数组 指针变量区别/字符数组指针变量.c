#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)	
#pragma warning(disable:6031)
#define _CRT_SECURE_NO_WARNINGS

//�ַ���������ַ���ָ�������
void test1()
{
	char* str = "hello iceage";
	printf("str = %s\n", str);
	//str[0] = 'x';	//error �ַ��������޷��޸�

	char str2[] =  "hello iceage";
	printf("str2 = %s\n", str2);
	str2[0] = 'x';
	printf("str2 = %s\n", str2);
}

int main()
{
	test1();

	system("pause");
	return EXIT_SUCCESS;
}