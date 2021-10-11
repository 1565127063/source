#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)	
#pragma warning(disable:6031)
#define _CRT_SECURE_NO_WARNINGS

//代码区  全局区  栈区  堆区 

//全局变量  全局区
int g_a = 10;
int g_b = 20;

//全局常量  全局区
const int g_c_a = 100;
const int g_c_b = 200;

void test1()
{
	//局部变量  栈区
	int a = 10, b = 20;
	printf("a的地址=%d b的地址=%d\n",&a,&b);//

	printf("g_a的地址=%d g_b的地址=%d\n", &g_a, &g_b);

	//静态局部变量  全局区
	static int s_a = 20;
	static int s_b = 10;
	printf("s_a的地址=%d s_b的地址=%d\n", &s_a, &s_b);

	//常量在 全局区中
	printf("字符串常量地址： %d\n", &"hello world");
	printf("字符串常量地址： %d\n", &"hello world2");

	//全局常量 全局区
	printf("g_c_a常量地址： %d\n", &g_c_a);
	printf("g_c_a常量地址： %d\n", &g_c_b);

	//局部常量  栈区
	//总结：只要有局部  就是放在栈区
	const int c_a = 100;
	const int c_b = 200;
	printf("c_a常量地址： %d\n", &c_a);
	printf("c_a常量地址： %d\n", &c_b);

	//堆区
	char* p = malloc(64);
	printf("p的地址 = %d\n", p);
}

int main()
{
	test1();

	system("pause");
	return EXIT_SUCCESS;
}
