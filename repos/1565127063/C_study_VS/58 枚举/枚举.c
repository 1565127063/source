#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)	
#pragma warning(disable:6031)
#define _CRT_SECURE_NO_WARNINGS

enum POKER { HOGTAO = 2, HEITAO = 7, MEIHUA, FANGKUAI };

//
void test1()
{
	enum POKER poker;
	poker = HOGTAO;

	printf("%d\n", poker);//2
	printf("%d\n", HEITAO);//7
	printf("%d\n", MEIHUA);//8
	printf("%d\n", FANGKUAI);//9

	//FANGKUAI = 4 //error
}

enum BOOL { FALSE, TRUE };
//等价于
#define False0 0;
#define True0 1;

//为定义从第一个为0开始累加
void test2()
{
	enum BOOL Flag;
	Flag = FALSE;
	if (Flag)
	{
		printf("Flag 为真\n");
	}
	else
	{
		printf("Flag 为假\n");
	}
}

//枚举名字可以省略
enum 
{
	WIDTH = 600,
	HEIGHT = 500
};

void test3()
{
	printf("游戏高度为%d\n", HEIGHT);
	printf("游戏宽度为%d\n", WIDTH);
}

int main()
{
	test3();

	system("pause");
	return EXIT_SUCCESS;
}