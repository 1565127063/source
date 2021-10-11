#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS

//冒泡排序
void test1()
{
	int arr[] = {9, 4, 3, 2, 5, 8, 7, 1, 6};
	int len = sizeof(arr) / sizeof(int) ;	//元素个数
	for (int i = 0; i < len-1; i++)		//排序轮数
	{
		for (int  j = 0; j < len-i-1; j++)
		{
			if (arr[j] >arr[j+1])	//需要改降序改符号就好
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	for (int  i = 0; i < len; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}


void  test2()
{
	int PP_Buf[] = { 15,859,233,55,215,996,251,365,378,455 };
	int len = sizeof(PP_Buf) / sizeof(int);
	for (int i = 0; i < len; i++)
	{
		printf("%d ", PP_Buf[i]);
	}
	printf("\n");

	for (int i = 0; i < len-1; i++)
	{
		for (int j = 0; j < len - i - 1;j++)
		{
			if (PP_Buf[j]>PP_Buf[j+1])
			{
				PP_Buf[j] = PP_Buf[j] + PP_Buf[j + 1];
				PP_Buf[j + 1] = PP_Buf[j] - PP_Buf[j + 1];
				PP_Buf[j] = PP_Buf[j] - PP_Buf[j + 1];
			}
		}
	}
	for (int i = 0; i < len; i++)
	{
		printf("%d ", PP_Buf[i]);
	}
	printf("\n");

	
}





int main()
{

	test2();

	system("pause");
	return EXIT_SUCCESS;
}