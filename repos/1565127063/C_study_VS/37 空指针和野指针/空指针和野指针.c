#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS

//空指针
void test1()
{
	//指针变量指向地址为0的地址
	int * p = NULL;	// #define NULL ((void *)0)

	//创建指针变量时 可以初始化为NULL

	//不可以访问空指针的内容
	//printf("%d\n", p); //p的值
	//printf("%d\n",*p); //内存地址编号0-255之间被系统占用 不可以访问
}

//野指针
void test2()
{
	//指针变量指向非法的内存区间
	int* p = 0xfff;
	//printf("%d\n", p);
	//printf("%d\n", *p);	//error

	int* p1;	//指针变量未初始化 属于野指针
	//printf("%d\n", *p1);	//vs不可以运行
}

//void的用途
void test3()
{
	//无类型无法创建变量 原因是编译器不知道分配多少字节
	//void a = 10;
	//void 的用途：修饰函数返回值类型，函数形参
	/*
void fun(void)
{
	printf("\n");
	return 0;
	//不可以运行 return  void
}
fun()	//不严谨
{
	printf("\n");
	//可以运行
}
*/
}

//无类型指针 万能指针
void test4()
{
	void * p = NULL;
	printf("sizeof(p) = %d\n",sizeof(p));	//4

	int num = 10;
	p = &num;
	printf("%d\n",*(int*)p);	//void * 不能直接解引用 需要转换int*

	int* p1 = NULL;
	char* p2 = NULL;
	p2 = (int*)p1;	//强制类型转换
	p2 = p;	//void *不用强转也不出警告 
	//void * 保存任意类型指针 称为万能指针
}

int main()
{
	test2();
	//test1();
	system("pause");
	return EXIT_SUCCESS;
}
