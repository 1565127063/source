#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)	
#pragma warning(disable:6031)
#define _CRT_SECURE_NO_WARNINGS

//����������ڴ�
void allocateSpeace(int** arr,int len);

//��Ԫ�ظ�ֵ
void setArray(int* arr,int len);

//���������� flag = 0 ���� flag = 1 ����
void sortArray(int* arr, int len, int flag);

//��������
void pArray(int* arr,int len);

//��ȡ���ֵ/��Сֵ ƽ���� �ܺ�
int max_Array(int* arr, int len);
int min_Array(int* arr, int len);
int avg_Array(int* arr, int len);
int sum_Array(int* arr, int len);

//�ͷ�����

void freeArray(int** arr);