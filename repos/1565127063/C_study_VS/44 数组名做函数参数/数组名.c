#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)//必须的
#pragma warning(disable:6031)
#define _CRT_SECURE_NO_WARNINGS

//数组名做函数参数的时候，会退化为指针，指向数组第一个元素的地址
void printf_arr(int* arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d ",arr[i]);
		//printf("%d",*(arr+i));
	}
	printf("\n");
	//printf("printf_arr sizeof(arr) = %d\n", sizeof(arr));
}
void test1()
{
	int  arr[5] = { 1,2,3,4,5 };
	int len = sizeof(arr) / sizeof(int);
	printf_arr(arr, len);
	printf("test1 sizeof(arr) = %d\n", sizeof(arr));
}

//void set_arr(int* arr,int len) 下面更易于理解
void set_arr(int arr[],int len)
{
	printf("输入5个数\n");
	for (int i = 0; i < len; i++)
	{
		scanf("%d", &arr[i]);
		//printf("%d",*(arr+i));
	}
}
void test2()
{
	int arr[5] = { 0 };
	int len = sizeof(arr) / sizeof(int);
	set_arr(arr, len);
	printf("赋值后结果为\n");
	printf_arr(arr, len);
}

//寻找最大值
int max_arr(int arr[], int len)
{
	int maxarr = 0;
	for (int i = 0; i < len; i++)
	{
		if (maxarr < arr[i])
		{
			maxarr = arr[i];
		}
	}
	return maxarr;
}

void test3()
{
	int arr[5] = { 0 };
	int len = sizeof(arr) / sizeof(int);
	set_arr(arr, len);
	printf("赋值后结果为\n");
	printf_arr(arr, len);

	int max_num = max_arr(arr, len);
	printf("max_num = %d\n",max_num);
}
//寻找最大值下标
int max_arr2(int arr[], int len)
{
	int maxarr = 0;
	for (int i = 1; i < len; i++)
	{
		if (arr[maxarr] < arr[i])
		{
			maxarr = i;
		}
	}
	return arr[maxarr];
}
int main()
{
	//test1();
	//test2();
	test3();
	system("pause");
	return EXIT_SUCCESS;
}