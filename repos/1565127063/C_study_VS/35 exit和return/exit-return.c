#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS


void test1()
{
	printf("hello5\n");
	printf("hello4\n");

	//return;   //退出当前的函数
	exit(0);	//退出整个程序

	printf("hello3\n");
	printf("hello2\n");
	printf("hello1\n");
}

int main()
{
	printf("hello1\n");
	printf("hello2\n");
	
	test1();

	printf("hello3\n");
	printf("hello4\n");
	printf("hello5\n");

	system("pause");
	return EXIT_SUCCESS;
}