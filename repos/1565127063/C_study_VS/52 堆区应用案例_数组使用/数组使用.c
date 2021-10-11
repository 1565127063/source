#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)	
#pragma warning(disable:6031)
#define _CRT_SECURE_NO_WARNINGS
#include "myArry.h"

int main(){

	int num = 0;
	printf("请输入数组元素个数\n");
	scanf("%d", &num);

	int* arr = NULL;
	allocateSpeace(&arr,num);
	//设置函数
	setArray(arr, num);

	//排序 1降序
	sortArray(arr, num,1);
	//打印函数
	pArray(arr, num);
	//排序 0升序
	sortArray(arr, num, 0);
	//打印函数
	pArray(arr, num);

	//printf("出现异常判断结束的flag\n");

	printf("最大值%d\t 最小值%d\t 平均值%d\t 总和%d\n",
		max_Array(arr, num),
		min_Array(arr, num),
		avg_Array(arr, num),
		sum_Array(arr, num)
	);

	freeArray(&arr);//二级指针需要放一级指针的地址

	system("pause");
	return EXIT_SUCCESS;
}


