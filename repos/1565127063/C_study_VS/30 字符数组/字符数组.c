#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)	//必须的
#pragma warning(disable:6031)	//去警告

//字符数组定义初始化
void test1()
{
	char arr[50];
	//arr[strlen(arr) - 1] = '\0';
	printf("%d\n", sizeof(arr)); //5  char一个字节 1 * 5
	
	//char arr1[] = { 'H','e','l','l','o' };	//%s 输出乱码
	char arr1[] = { 'H','e','l','l','o','1','\0'};	
	for (int i = 0; i < 6; i++)
	{
		printf("%c",arr1[i]);
	}
	printf("\n");
	printf("%s\n",arr1);	//%s 开始到 \0结束

	char arr2[] = "hello2"; 
	printf("%s\n", arr2);	//%s不会乱码 这种定义形式最方便
}

//字符串统计
void test2()
{
	char str1[32] = "hello world";
	// strlen(str)  统计字符串长度函数  不包括\0
	printf("%d\n",strlen(str1));	//实际字符串长度11
	printf("%d\n",sizeof(str1));	//字符数组个数32

	char str2[] = "hello world";
	printf("%d\n", strlen(str2));	//11
	printf("%d\n", sizeof(str2));	//12 包括 \0 

	char str3[] = "hello\0world"; 
	printf("%d\n", strlen(str3));	//5 遇到\0结束
	printf("%d\n", sizeof(str3));	//12 包括两个\0

	// '\0'后面最好不要连着数字，有可能几个数字连起来刚好是一个转义字符
	// '\ddd' 8 进制转义字符，  d 范围 0~7
	// '\xhh' 16 进制转义字符， h 范围 0~9， a~f， A~F 2 位 16 进制
	// \012 相当于 \n

	/* '//'是2 '\\'是1 1是1 \123是1 abc是3 \xac是1 hehe是4 \0 */
	char str4[] = "//\\1\123abc\xachehe";
	printf("%d\n", strlen(str4));	//13
	printf("%d\n", sizeof(str4));	//14

	char arr[] = "hello word!";
	// strlen(arr) 
	printf("%d\n", strlen(arr));//11

}

//字符串统计
void test3()
{
	//int buf[16] = ""; 等价于
	char buf[16] = { 0 };
	scanf("%s",buf);	//scanf遇到空格时会结束
	printf("%s\n",buf);	//hello world 实际hello 
}
//字符串输入
void test4()
{
	char buf1[16] = { 0 };
	//gets(buf1);	//不推荐使用 不检测数组越界的情况
	fgets(buf1,sizeof(buf1),stdin);	//stdin 标准的输入设备-键盘 
	//输出15+\0
	printf("%s\n", buf1);
}
//字符串输出
void test5()
{
	char buf2[16] = "hello world2";
	//printf("%s\n", buf2);
	//puts(buf2); //自带换行输出 
	fputs(buf2,stdout);	//标准的设备输出-屏幕 不带换行
	printf("\n");
}
int main()
{
	test1();
	test2();
	test3();
	test4();
	test5();
	system("pause");
	return EXIT_SUCCESS;
}
