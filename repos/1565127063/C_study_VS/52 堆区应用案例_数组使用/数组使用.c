#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)	
#pragma warning(disable:6031)
#define _CRT_SECURE_NO_WARNINGS
#include "myArry.h"

int main(){

	int num = 0;
	printf("����������Ԫ�ظ���\n");
	scanf("%d", &num);

	int* arr = NULL;
	allocateSpeace(&arr,num);
	//���ú���
	setArray(arr, num);

	//���� 1����
	sortArray(arr, num,1);
	//��ӡ����
	pArray(arr, num);
	//���� 0����
	sortArray(arr, num, 0);
	//��ӡ����
	pArray(arr, num);

	//printf("�����쳣�жϽ�����flag\n");

	printf("���ֵ%d\t ��Сֵ%d\t ƽ��ֵ%d\t �ܺ�%d\n",
		max_Array(arr, num),
		min_Array(arr, num),
		avg_Array(arr, num),
		sum_Array(arr, num)
	);

	freeArray(&arr);//����ָ����Ҫ��һ��ָ��ĵ�ַ

	system("pause");
	return EXIT_SUCCESS;
}


