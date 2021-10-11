#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)	
#pragma warning(disable:6031)
#define _CRT_SECURE_NO_WARNINGS

//1.typedef的使用
//用途 给数据类型 起别名 两个都可以用

typedef int Mint;
//typedef 原名 别名

//
void test1()
{
	int num1 = 10;
	Mint num2 = 20;
	printf("num1 = %d  num1 = %d\n", num1, num2);
}

//2.typedef可以简化 struct关键字
/* 
struct itcastCPPStudent
{
	char name[64];
	int age;
};

typedef struct itcastCPPStudent Student;
//可以简化
*/

typedef struct itcastCPPStudent
{
	char name[64];
	int age;
}Student;
//Student 是数据类型

void test2()
{
	struct itcastCPPStudent s1 = { "Tom",18 };
	Student s2 = { "Jerry",19 };
}

//3.区分数据类型
void test3()
{
	char* p1, p2;//容易混淆
	//char* p1, *p2 //避免混淆
	printf("sizeof(p1) = %d sizeof(p2) = %d\n", sizeof(p1),sizeof(p2)); //4 1

	typedef char* PCHER;
	PCHER p3, p4;
	printf("sizeof(p3) = %d sizeof(p4) = %d\n", sizeof(p3), sizeof(p4)); //4 4

	//32位下 char 4字节   64位 char 8字节
}

int main()
{
	test3();

	system("pause");
	return EXIT_SUCCESS;
}