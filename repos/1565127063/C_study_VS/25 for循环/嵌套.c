#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS

//���10*10����
void test1()
{
	int i, j;
	//i���Ƶ�����
	for ( i = 0; i < 10; i++)
	{
		for ( j = 0; j < 10; j++)	//j���Ƶ�����
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
