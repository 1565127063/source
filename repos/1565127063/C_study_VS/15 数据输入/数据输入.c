#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS	//没有用
#pragma warning(disable:4996)	//必须的
#pragma warning(disable:6031)	//去警告
//scanf实现数据输入

//1、整形数据的输入
void test1()
{
	int num = 0;
	printf("重新输入num值\n");
	scanf("%d",&num);	//&取变量地址
	printf("num = %d\n", num);
}

//2、字符型的输入
void test2()
{
	char ch = 'a';
	printf("重新输入char值\n");
	scanf("%c", &ch);	//&取变量地址
	printf("char= %c\n", ch);
}

//3、浮点型的输入
void test3()
{
	double d = 3.14;
	printf("重新输入d值\n");
	scanf("%lf", &d);	//&取变量地址
	printf("d= %.3lf\n", d);
}

//4.字符串输入
void test4()
{
	/*char str[] = " ";*/
	char str[64] = " ";
	printf("重新输入字符串str\n");
	scanf("%s",str);	//不需要取地址符&
	printf("str = %s\n", str);
}

//5.注意事项
void test5()
{
	//需要分两次输入时，10\n 取走了10  \n还留下 变成ch

	int num = 0;
	printf("重新输入num值\n");
	scanf("%d", &num);	//&取变量地址
	printf("num = %d\n", num);

	getchar();	//从缓冲区获取数值

	char ch = 'a';
	printf("重新输入char值\n");
	scanf("%c", &ch);	//&取变量地址
	printf("char= %c\n", ch);

	putchar('a');	//向屏幕打印字符
	printf("\n");
}

int main()
{
	test5();

	system("pause");
	return EXIT_SUCCESS;
}