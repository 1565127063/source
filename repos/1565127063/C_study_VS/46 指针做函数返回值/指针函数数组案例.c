#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)	
#pragma warning(disable:6031)
#define _CRT_SECURE_NO_WARNINGS

//ð������
void bubbleStort(int* arr, int len)
{
	//����
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

//��ӡ����
void printfArr(int *arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//��ϰ����װ�������¸����鸳ֵ ����  �ҵ����ֵ ��Сֵ �ܺ� ƽ����
void myScanf(int* arr, int len)
{
	printf("�����鸳ֵ\n");
	for (int i = 0; i < len; i++)
	{
		scanf("%d", &arr[i]);
	}
}

//�����Сֵ
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

//�ܺͣ�ƽ��ֵ
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
	//1.����ʵ������
	int len = sizeof(arr) / sizeof(int);
	printf("����ǰ�Ľ��Ϊ��\n");
	printfArr(arr, len);
	bubbleStort(arr, len);

	//2.��ӡ����
	printf("�����Ľ��Ϊ��\n");
	printfArr(arr, len);
	max_min(arr, len);
	sum_avg(arr, len);

	//3. �ٴθ�ֵ
	myScanf(arr, len);
	printf("��ֵ��Ľ��Ϊ��\n");
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