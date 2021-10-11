#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS

//指针数组 数组中每个元素的类型为指针
void test1()
{
	int num1 = 10;
	int num2 = 20;
	int num3 = 30;
	int num4 = 40;

	int* arr[4] = { &num1,&num2,&num3,&num4 };
	int len = sizeof(arr) / sizeof(int*);
	for (int  i = 0; i < len; i++)
	{
		printf("%d\n",*arr[i]);	//[]优先级最高 其次()
		//printf("%d\n",**(arr+i)); //[]本本质是  *() 的简写
	}
}
//
void test2()
{
	char* arr[4] = { "aaa","bbb","ccc","ddd" };
	int len = sizeof(arr) / sizeof(char*);
	for (int i = 0; i < len; i++)
	{
		printf("%s\n", arr[i]);	//第一个a开始  "自带\0
		//printf("%s\n", &arr[i]); //打印首位
	}
}
 
//指针的运算 
void test3()
{ 
	//同一个数组的指针相减可以获取指针间的个数
	// 并且和数组的定义类型无关 int short
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int* p1 = arr;
	int* p2 = &arr[4];
	printf("%d\n",(int)p1 + (int)p2);	//结果还是地址 相加无意义
	printf("%d\n", p2 - p1);	//arr[4] -arr[0] = 4 
	//指针乘除无意义 

	//判断指针是否相等 
	if (p1 == NULL)
	{
		printf("p1是空指针\n");
	}
	else
	{
		printf("p1不是空指针\n");
	}
	if (p1 == p2)
	{
		printf("p1 = p2\n");
	}
	else
	{
		printf("p1 != p2\n");
	}
}

int main()
{
	test1();
	test2();
	test3();
	system("pause");
	return EXIT_SUCCESS;
}