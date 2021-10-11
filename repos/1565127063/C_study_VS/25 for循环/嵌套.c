#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS

//输出10*10矩阵
void test1()
{
	int i, j;
	//i控制的行数
	for ( i = 0; i < 10; i++)
	{
		for ( j = 0; j < 10; j++)	//j控制的列数
		{
			printf("*");
		}
		printf("\n");
	}
}

int main()
{
	test1();
	system("pause");
	return EXIT_SUCCESS;
}
