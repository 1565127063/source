#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)	
#pragma warning(disable:6031)
#define _CRT_SECURE_NO_WARNINGS

void up_and_down(int n)
{
	printf("Level %d %p\n", n, &n);
	if (n < 4)
	{
		up_and_down(n + 1);//n=1-4都会调用一次函数，n=4调用完成后 回到n=3
	}
	printf("LEVEL %d %p\n", n, &n);
}

int imin(int a, int b)
{
	return a > b ? b : a;
}

//
void test1()
{
	

}

int main()
{
	test1();

	system("pause");
	return EXIT_SUCCESS;
}