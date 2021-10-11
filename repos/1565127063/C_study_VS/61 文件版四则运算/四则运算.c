#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)	
#pragma warning(disable:6031)
#define _CRT_SECURE_NO_WARNINGS
#include "test.h"

/*
#include <time.h>
	time_t tm = time(NULL);//得到系统时间
	printf("time(NULL) = %lld\n", time(NULL)); //时间戳转换日期工具
	srand((unsigned int)tm);//随机种子只需要设置一次即可
	//类型定义unsigned int =  size_t
*/

//题目需求：
//产生50道随机题目，形式如下 ：1 +1 = 
//出题：出50道题目，随机数在1~100之间 运算符 + - * /
//解题：利用程序将50道题目解析存入另一个文件中


int main()
{
	setQuestion();
	answerQuestion();

	system("pause");
	return EXIT_SUCCESS;
}
