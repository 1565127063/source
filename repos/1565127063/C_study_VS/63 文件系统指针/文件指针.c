#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)	
#pragma warning(disable:6031)
#define _CRT_SECURE_NO_WARNINGS

// 3个系统默认文件指针
//stdin   标准输入 默认为当前终端 键盘 scanf getchar
//stdout  标准输出 默认为当前终端 屏幕 printf puts
//stderr  标准出错 默认为当前终端 屏幕 perror

void test1()
{
	int a = 0;
	printf("给a赋值\n");

	//关闭掉系统输入指针
	fclose(stdin);	//禁用键盘

	scanf("%d", &a);
	printf("a= %d\n", a);
}
void test2()
{
	printf("hello1\n");
	printf("hello2\n");
	printf("hello3\n");

	//关闭掉系统输出
	fclose(stdout);	//禁用屏幕  vs崩溃 用来查询printf需要关闭

	printf("hello4\n");
	printf("hello5\n");
	printf("hello6\n");
}

void test3()
{
	FILE* fp = fopen("a.txt", "r");
	if (fp == NULL)
	{
		perror("错误信息");	//错误信息: No such file or directory(目录)
		//printf("打开失败");
		//return;
	}
	fclose(stderr);	//关闭错误调试指针
	perror("错误信息");//因为关闭不显示第二次报错
}

int main()
{
	test3();

	system("pause");
	return EXIT_SUCCESS;
}