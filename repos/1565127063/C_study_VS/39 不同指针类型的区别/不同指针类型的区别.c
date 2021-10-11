#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS

//1.步长不同，+1后跳跃字节 不同
void test1()
{
	int* p1 = NULL;
	printf("%d\n",p1);			//0
	printf("%d\n", p1+1);		//4
	char* p2 = NULL;	
	printf("%d\n", p2);			//0
	printf("%d\n", p2 + 1);		//1
	double* p3 = NULL;
	printf("%d\n", p3);			//0
	printf("%d\n", p3 + 1);		//8
}

//2.解引用时，取出的字节不同
void test2()
{
	//16进制最少多少字节存放 
	//1个数字4位 2个数字一个字节bit 刚好4个字节
	int num = 0x01020304;
	int* p = &num;
	printf("*p = %#x\n",*p);	//*p = 0x1020304
	short* p2 = &num;
	printf("*p = %#x\n", *p2);	//0x0304
	char* p3 = &num;
	printf("*p = %#x\n", *p3);	//0x4
}

//3.
void test3()
{

}

//4.
void test4()
{

}


int main()
{

	test2();

	system("pause");
	return EXIT_SUCCESS;
}