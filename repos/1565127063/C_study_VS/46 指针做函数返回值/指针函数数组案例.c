#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)	
#pragma warning(disable:6031)
#define _CRT_SECURE_NO_WARNINGS

//冒泡排序
void bubbleStort(int* arr, int len)
{
	//升序
	for (int i = 0; i < len-1; i++)
	{
		for (int j = 0; j < len-i-1; j++)
		{
			if (arr[j] > arr[j+1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

}

//打印数组
void printfArr(int *arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//练习：封装函数重新给数组赋值 排序  找到最大值 最小值 总和 平均数
void myScanf(int* arr, int len)
{
	printf("给数组赋值\n");
	for (int i = 0; i < len; i++)
	{
		scanf("%d", &arr[i]);
	}
}

//最大最小值
void max_min(int* arr, int len)
{
	int max = 0, min = 1000;
	for (int i = 0; i < len; i++)
	{
		if (arr[i] > arr[max])
		{
			max = i;
		}
		if (arr[i] < arr[min])
		{
			min = i;
		}
	}
	printf("max = %d min = %d\n", arr[max], arr[min]);
}

//总和，平均值
void sum_avg(int* arr, int len)
{
	float sum = 0;
	float avg = 0;
	for (int i = 0; i < len; i++)
	{
		sum = sum + arr[i];
	}
	avg = sum / len;
	printf("sum = %.2f avg = %.2f\n", sum, avg);
}

//
void test1()
{
	int arr[10] = { 9,5,7,2,6,8,1,3,4,12 };
	//1.函数实现排序
	int len = sizeof(arr) / sizeof(int);
	printf("排序前的结果为：\n");
	printfArr(arr, len);
	bubbleStort(arr, len);

	//2.打印数组
	printf("排序后的结果为：\n");
	printfArr(arr, len);
	max_min(arr, len);
	sum_avg(arr, len);

	//3. 再次赋值
	myScanf(arr, len);
	printf("赋值后的结果为：\n");
	printfArr(arr, len);
	max_min(arr, len);
	sum_avg(arr, len);
}

int main()
{
	test1();

	system("pause");
	return EXIT_SUCCESS;
}