#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>	//srand()
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)	//必须的
#pragma warning(disable:6031)

//知道循环次数for 不知道时while

void test1()
{
	//while (num = 1) 判断是否真 不是就等待
	int num = 0;
	while (num<9)
	{
		num++;
		printf("%d\n",num);
	}
	//设置跳出循环的出口 避免while（1）死循环
}

//系统产生1-100随机数猜测
void test2()
{
	//添加随机数种子 否则产生的随机数固定 
	srand((unsigned int) time(NULL));
	//time(NULL) 1970年1月1日至今的秒数 只需要设置一次
	int num = rand() % 100;	//产生0~99随机数
	//printf("%d\n", num);

	int val;
	while (1)
	{
		printf("输入一个1-100的数字\n");
		scanf("%d",&val);
		if (val > num)
		{
			printf("猜测过大\n");
		}
		else if (val < num)
		{
			printf("猜测过小\n");
		}
		else
		{
			printf("恭喜你猜对了，num是%d\n",num);
			break;	//可以退出循环
		}
	}

}

//判断水仙花数
void test3()
{
	//do while 先执行一遍再判断条件 
	//1.先打印所有数
	int num = 100;
	do
	{
		//2.判断水仙花数
		int a, b, c;
		a = num / 100;
		b = num % 10;
		c = num / 10 % 10;
		if (num == a*a*a+b*b*b+c*c*c)
		{
			printf("水仙花数  %d\n", num);
		}
		num++;
	} while (num < 1000);
}

//for循环基本格式
void test4()
{
	for (int num = 0; num < 10; num++)
	{
		printf("%d\n", num);
	}
}

//敲桌游戏
//1-100 个位 十位有7 或者7的倍数敲桌子
void test5()
{
	//7的倍数 %7 == 0；
	//个位有7 %10 == 7；
	//十位有7 70-79  /10==7；
	for (int num = 1; num < 100; num++)
	{
		if (num%7==0 || num%10==0 || num/10==7)
		{
			printf("敲桌子\n");
		}
		else
		{
			printf("%d\n",num);
		}
	}
}

int main()
{
	printf("test\n");
	test3();
	system("pause");
	return EXIT_SUCCESS;
}