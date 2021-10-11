#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS

//1.值传递
//函数的传递，实现函数：交换两个数据
void my_Swap(int num1, int num2)
{
	int temp = num1;
	num1 = num2;
	num2 = temp;
	printf("num1 = %d\n",num1);		//20
	printf("num2 = %d\n", num2);	//10
}
//值传递  形参修改不了实参
void test1()
{
	int a = 10;
	int b = 20;
	my_Swap(a, b);
	printf("a = %d b = %d\n",a,b); //a b 未修改
}
void my_Swap2(int* p1, int* p2)
{
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
	printf("p1 = %d\n", *p1);		//20
	printf("p2 = %d\n", *p2);		//10
}

//2.地址传递
//形参和实参同时修改
void test2()
{
	int a = 10;
	int b = 20;
	my_Swap2(&a, &b);
	printf("a = %d b = %d\n", a, b); //
}
int main()
{
	test1();
	test2();
	system("pause");
	return EXIT_SUCCESS;
}
