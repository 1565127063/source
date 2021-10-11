#include "test.h"
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)	
#pragma warning(disable:6031)
#define _CRT_SECURE_NO_WARNINGS
#include <time.h>

#define quslen 50

//出题
void setQuestion(void)
{
	//随机数种子
	srand((size_t)time(NULL));

	//产生随机数变量 运算符
	int num1 = 0, num2 = 0;
	char ch = 0;
	char oper[] = { '+','-','*','/' };

	FILE* f_write = fopen("test.txt", "w");
	if (f_write == NULL)
	{
		printf("打开文件失败\n");
		return;
	}
	for (int i = 0; i < quslen; i++)
	{
		//产生随机数 1~100
		num1 = rand() % 100 + 1;
		num2 = rand() % 100 + 1;
		ch = oper[rand() % 4]; //产生0~3的随机数放入数组中 

		//拼接字符串
		char msg[64] = { 0 };
		sprintf(msg, "%d %c %d = \n", num1, ch, num2);

		//写文件
		//printf("%s", msg); //打印测试
		fputs(msg, f_write);
	}
	//关闭文件
	fclose(f_write);
	printf("50道题目生成完毕\n");
}


//解题
void answerQuestion(void)
{
	FILE* fp1 = fopen("test.txt", "r");
	FILE* fp2 = fopen("answer.txt", "w");
	if (!fp1 || !fp2)
	{
		printf("文件打开失败\n");
		return;
	}
	char buf[64] = { 0 };
	//读取文件到结尾
	while (fgets(buf, sizeof(buf), fp1))
	{
		//printf("%s", buf);
		int num1 = 0, num2 = 0;
		char ch = '0';
		//字符串拆分
		sscanf(buf, "%d %c %d  ", &num1, &ch, &num2);
		//printf(" %d %c  %d =  \n", num1, ch, num2);

		float ret = 0;
		switch (ch)
		{
		case '+':
			ret = num1 + num2;
			break;
		case '-':
			ret = num1 - num2;
			break;
		case '*':
			ret = num1 * num2;
			break;
		case '/':
			ret = num1 / num2;
			break;
		}
		//组装新的字符串
		char str[64] = { 0 };
		sprintf(str, "%d %c %d = %.1f\n", num1, ch, num2, ret);
		//printf("ret = %s\n", str);
		//按行写文件
		fputs(str, fp2);

	}
	fclose(fp1);
	fclose(fp2);
	printf("题目解答完毕\n");
}
