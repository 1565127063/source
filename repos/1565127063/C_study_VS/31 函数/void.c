#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS

//定义两个整形相加 返回相加后结果函数
//num1 num2 形式上的参数 并没有实际的值  也叫形参
int add(int num1, int num2) 
{
	int sum = num1 + num2;
	return sum;	//返回值int类型
}

//void 表示函数不需要返回值
void test1()
{
	//函数的调用
	//语法 函数名 +(参数1，参数2)
	int num1 = 10;
	int num2 = 15;
	int sum = add(num1, num2); //实际参数  实参
	printf("sum = %d\n",sum);

	//return; //不需要返回值
}

//函数使用在定义前，函数需要声明
//函数的定义只能一次，但是声明可以有多次
int get_Max(int num1, int num2);

void test2()
{
	int num1 = 100;
	int num2 = 150;
	int max = get_Max(num1, num2); //实际参数  实参
	printf("max = %d\n", max);
}

int main()
{
	test2();
	system("pause");
	return EXIT_SUCCESS;
}

int get_Max(int num1, int num2)
{
	//谁大返回谁
	return num1 > num2 ? num1 : num2;
}