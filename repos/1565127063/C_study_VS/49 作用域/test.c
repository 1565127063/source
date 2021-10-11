#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)	
#pragma warning(disable:6031)
#define _CRT_SECURE_NO_WARNINGS

//c语言下  普通全局变量都隐藏的加了关键字 extern

int g_b = 20;   //extern int g_b = 20; 等价于

//静态的全局变量也只能在本文件使用
static int g_s_b = 20000;

void test_fun1()
{
	printf("hello fun1\n");
}

static void test_fun2()
{
	printf("hello fun2\n");
}