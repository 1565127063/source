#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS


void test1()
{
	char num = -15;
	//-15原码 1000	1111 
	//-15反码 1111  0000 
	//-15补码 1111  0001 
	//原码符号位不变 其余取反再+1

	//有符号输出10进制 有转换
	printf("%d\n", num);	//-15

	//无符号输出 怎么存怎么取 不变
	//1111 0001   241

	printf("%u\n",num & 0x000000ff);	//241
	//按位与	0000 0000 0000 0000 0000 1111 0001
	//32位值	1111 1111 1111 1111 1111 0000 0000
	//结果		1111 1111 1111 1111 1111 1111 0001	
	//变换		0000 0000 0000 0000 0000 1111 1111	&
	//输出		0000 0000 0000 0000 0000 1111 0001
}

void test2()
{
	char num = 0x9b;	//8 16进制不用考虑正负
	//原码=1001 1011	人看到的是原码
	//补码=1001 1011  	计算机存入的补码  
	
	//有符号取	符号位为1时
	//取回时：符号位不变 其余取反再+ 11110 0101
	printf("%d\n",num);		//-101

	//无符号取	取回不用考虑变换
	//printf("%x\n",num);		//0xffffff9b
	printf("%x\n", num & 0x000000ff);	//16进制输出 9b
	printf("%u\n", num & 0x000000ff);	//10进制输出 155
}

int main()
{

	test1();
	test2();
	system("pause");
	return EXIT_SUCCESS;
}