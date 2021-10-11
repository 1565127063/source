#include "myArry.h"

//����������ڴ�
void allocateSpeace(int** arr, int len)
{
	//**arr ��һ������
	*arr = malloc(sizeof(int) * len);
	if (*arr == NULL)
	{
		printf("����ʧ��\n");
		return;
	}

	//����ڴ�
	memset(*arr, 0, sizeof(int) * len);
}
//��Ԫ�ظ�ֵ
void setArray(int* arr, int len)
{
	printf("���Ԫ�ظ�ֵ\n");
	for (int  i = 0; i < len; i++)
	{
		scanf("%d", &arr[i]);
	}
}
//����������
void sortArray(int* arr, int len,int flag)
{
	int temp;
	for (int i = 0; i < len-1; i++)
	{
		for (int  j = 0; j < len-1-i; j++)
		{
			if (flag)  //����
			{
				if (arr[j] < arr[j + 1])
				{
					temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
			else   //����
			{
				if (arr[j] > arr[j + 1])
				{
					temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}

		}
	}
	printf("\n");
}
//��������
void pArray(int* arr, int len)
{
	printf("����Ԫ��Ϊ");
	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
//��ȡ���ֵ/��Сֵ ƽ���� �ܺ�
int max_Array(int* arr, int len)
{
	int max = 0;
	for (int i = 1; i < len; i++)
	{
		if (arr[max]<arr[i])
		{
			max = i;
		}
	}
	return arr[max];
}
int min_Array(int* arr, int len) 
{
	int min = 0;
	for (int i = 0; i < len; i++)
	{
		if (arr[min] > arr[i])
		{
			min = i;
		}
	}
	return arr[min];
}
int sum_Array(int* arr, int len)
{
	int sum = 0;
	for (int  i = 0; i < len; i++)
	{
		sum = sum + arr[i];
	}
	return sum;
}
int avg_Array(int* arr, int len) 
{
	/*int sum = 0, avg = 0;
	for (int i = 0; i < len; i++)
	{
		sum += arr[i];
		//sum = sum + arr[i];
	}
	return sum/len;*/
	return sum_Array(arr, len) / len;
}
//�ͷ�����
void freeArray(int** arr) 
{
	if (*arr != NULL)
	{
		free(*arr);
		*arr = NULL;
	}
}