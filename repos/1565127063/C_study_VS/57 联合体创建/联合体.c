#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)	
#pragma warning(disable:6031)
#define _CRT_SECURE_NO_WARNINGS

//联合体创建
union Data
{
	int a;		//4
	short b;	//2
	char c;		//1
};

void test1()
{
	printf("sizeof Data = %d\n", sizeof(union Data));	//4 最大的类型int

	union Data D1;
	D1.a = 10;
	D1.b = 20;
	D1.c = 30;
	printf("%d\n", D1.a + D1.b + D1.c);	//90  最后一次用 这个空间就是最后一个30
}

void test2()
{
	union Data D2;
	D2.a = 0x01020304;	//低位字节数据放在低地址端
	printf("D2.a =  %#x\n", D2.a);	//0x1020304	
	printf("D2.b =  %#x\n", D2.b);	//0x304
	printf("D2.b =  %#x\n", D2.c);	//0x4
}

void test3()
{
	union Data D3;
	D3.a = 0x01020304;
	D3.b = 0x0102;
	D3.c = 0x01;
	printf("%#x\n", D3.a + D3.b + D3.c);//0x1020203
}

int main()
{
	test3();

	system("pause");
	return EXIT_SUCCESS;
}