#include "myArry.h"

//给数组分配内存
void allocateSpeace(int** arr, int len)
{
	//**arr 解一次引用
	*arr = malloc(sizeof(int) * len);
	if (*arr == NULL)
	{
		printf("分配失败\n");
		return;
	}

	//清空内存
	memset(*arr, 0, sizeof(int) * len);
}
//给元素赋值
void setArray(int* arr, int len)
{
	printf("请给元素赋值\n");
	for (int  i = 0; i < len; i++)
	{
		scanf("%d", &arr[i]);
	}
}
//给数组排序
void sortArray(int* arr, int len,int flag)
{
	int temp;
	for (int i = 0; i < len-1; i++)
	{
		for (int  j = 0; j < len-1-i; j++)
		{
			if (flag)  //降序
			{
				if (arr[j] < arr[j + 1])
				{
					temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
			else   //升序
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
//遍历数组
void pArray(int* arr, int len)
{
	printf("数组元素为");
	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
//获取最大值/最小值 平均数 总和
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
//释放数组
void freeArray(int** arr) 
{
	if (*arr != NULL)
	{
		free(*arr);
		*arr = NULL;
	}
}