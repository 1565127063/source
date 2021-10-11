#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include<string.h>

//数据类型
//常用的整型有： short、 int、 long、 long long
void test1() {
	short num1 = 32768;	    //短整形 2 字节 (-2^15 ~ 2^15-1) -32767~32767
	int num2 = 32768;		//整形	4 字节 (-2^31 ~ 2^31-1)  2,147,483,648
	long num3 = 10;			//长整形 win 4字节 linux 4字节（32位） 8字节（64位）
	long long num4 = 10;	//长长整形 8 字节 (-2^63 ~ 2^63-1)
	printf("num1 = %hd\n", num1);	//短整形
	printf("num2 = %d\n", num2);	//整形
	printf("num3 = %ld\n", num3);	//长整形
	printf("num4 = %lld\n", num4);	//长长整形
}

void test2() {
	//定义有符号的变量时，隐藏了增加的关键字signed
	signed int a = 10;
	printf("a = %d\n", a);
	//定义无符号的变量时，需要增加的关键字unsigned
	unsigned int b = 10;
	printf("b = %d\n", b);
}

int main() {

	test1();
	test2();
	system("pause");
	return EXIT_SUCCESS;
}