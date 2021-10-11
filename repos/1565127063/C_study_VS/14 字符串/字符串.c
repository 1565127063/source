#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS

//字符串常量
void test1()
{
	printf("%s\n", "hello word");
	//双引号引起的字符串自带结束标志  
	printf("sizeof=%d\n", sizeof("hello world"));//12

	//%s输出字符串需要  从哪开始 输出到哪
	//" " 会返回字符串第一个字符的地址   遇到\0结束（自带一个\0）
	printf("%s\n","hello\0world");	//\0结束标志
	printf("%s\n", "\0helloworld");	//空白
}

//字符串变量
void test2()
{
	//字符数组
	char str[] = "hello word";
	printf("sizeof=%d\n", sizeof(str));
	str[0] = 'X';	//表示第一个字符
	printf("%s\n", str);	//Xello word
}

void test3()
{
	char a1 = 'a';
	char a2[] = "a";
	//a1属于字符    a2属于字符串 
	//a1占用1个字节    a2占用2个字节
}

int main()
{
	test1();
	test2();
	test3();
	system("pause");
	return EXIT_SUCCESS;
}