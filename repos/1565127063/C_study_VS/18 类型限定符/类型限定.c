#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS

//1.extern 声明一个变量， extern 声明的变量没有建立存储空间
void test1()
{
	//变量的声明，声明时，并没有分配变量给内存空间
	//不允许对外部变量的局部声明使用初始值设定项
	extern int g_a;
	printf("%d\n",g_a);
}

int g_a = 100;

// 2.const 定义一个常量，常量的值不能修改
void test2()
{
	const int num = 123;
	//num = 345; 无法修改
	printf("%d\n", num);
}

// 3.volatile
void test3()
{
	volatile int num = 10;
	//volatile 防止编译器优化代码 会逐行操作
	num = 20;
	num = 30;
	num = 40;
	num = 50;
	//printf("%d\n", num);
}

// 4.register 定义寄存器变量 有空闲寄存器生效；没有空闲不生效
void test4()
{	//频繁使用的变量加入到寄存器 不可以取地址的操作

	register int num = 222;
	//
	//printf("%p\n", &num);
}

int main()
{

	test2();
	
	system("pause");
	return EXIT_SUCCESS;
}