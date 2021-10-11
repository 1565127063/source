#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS

#include "test.h" //包含头文件

//移植性高 
void test1()
{
	int mat = my_add(10, 20);
	printf("%d\n",mat);
	int sut = my_sub(18, 4);
	printf("%d\n", sut);
}

int main()
{
	test1();
	system("pause");
	return EXIT_SUCCESS;
}