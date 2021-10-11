#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS

// <>系统的头文件    ""自己写的头文件
#include "test.h"

int my_add(int num1, int num2)
{
	int sum = num1 + num2;
	return sum;
}
int my_sub(int num1, int num2)
{
	int sum = num1 - num2;
	return sum;
}