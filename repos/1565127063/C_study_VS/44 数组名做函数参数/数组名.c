#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)//�����
#pragma warning(disable:6031)
#define _CRT_SECURE_NO_WARNINGS

//������������������ʱ�򣬻��˻�Ϊָ�룬ָ�������һ��Ԫ�صĵ�ַ
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

//void set_arr(int* arr,int len) ������������
void set_arr(int arr[],int len)
{
	printf("����5����\n");
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
	printf("��ֵ����Ϊ\n");
	printf_arr(arr, len);
}

//Ѱ�����ֵ
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
	printf("��ֵ����Ϊ\n");
	printf_arr(arr, len);

	int max_num = max_arr(arr, len);
	printf("max_num = %d\n",max_num);
}
//Ѱ�����ֵ�±�
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