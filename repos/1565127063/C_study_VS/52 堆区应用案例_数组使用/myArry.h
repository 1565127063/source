#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)	
#pragma warning(disable:6031)
#define _CRT_SECURE_NO_WARNINGS

//给数组分配内存
void allocateSpeace(int** arr,int len);

//给元素赋值
void setArray(int* arr,int len);

//给数组排序 flag = 0 升序 flag = 1 降序
void sortArray(int* arr, int len, int flag);

//遍历数组
void pArray(int* arr,int len);

//获取最大值/最小值 平均数 总和
int max_Array(int* arr, int len);
int min_Array(int* arr, int len);
int avg_Array(int* arr, int len);
int sum_Array(int* arr, int len);

//释放数组

void freeArray(int** arr);