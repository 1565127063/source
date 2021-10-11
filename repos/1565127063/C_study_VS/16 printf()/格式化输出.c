#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS

//printf 是输出一个字符串， putchar 输出一个 char。
void test1()
{
	int num = 10;
	printf("十进制结果 %d\n", num);
	printf("八进制结果 %#o\n", num);
	printf("十六进制结果 %#x\n", num);	//a 输出 16 进制的 int 类型，字母以小写输出
	printf("十六进制结果 %#X\n", num);	//A 输出 16 进制的 int 类型，字母以大写输出
	
	//float		 %f
	//double	%lf
	//char		%c %s
}

void test2()
{
	int a = 123;	//U 10
	int b = 0123;	//O 8
	int c = 0xabc;	//H 16 
	printf("a= %d\n", a);
	printf("b= %#o\n", b);
	printf("c= %#x\n", c);
}

void test3()
{
	//%md  m 指域宽，即对应的输出项在输出设备上所占的字符数
	//n 指精度，用于说明输出的实型数的小数位 默认6

	printf("%5d\n", 123);	//不足补空格 数字右对齐
	printf("%2d\n", 123);	//以数字为准 宽度不足 正常输出
	printf("%05d\n", 123);	//用数字补空位
	printf("%-5d\n", 123);	//数字左对齐
	// printf("%-05d\n", 123)； - 和0 不能同时显示 123 变成 12300
}

int main()
{
	test1();
	test2();
	test3();
	system("pause");
	return EXIT_SUCCESS;
}