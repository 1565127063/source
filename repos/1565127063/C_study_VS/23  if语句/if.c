#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS	
#pragma warning(disable:4996)	
#pragma warning(disable:6031)	

//1、单行if
void test1()
{
	int source;
	printf("输入您的分数\n");
	scanf("%d", &source);	//不要加 \n
	printf("您输入的分数是 %d 分\n", source);
	if (source > 600)
		printf("1\n");
	else
	{
		printf("!1\n");
	}
}

//2 多行if
void test2()
{
	int source;
	printf("输入您的分数\n");
	scanf("%d", &source);	//不要加\n
	printf("您输入的分数是 %d分\n", source);

	if (source >= 600)
	{
		printf("1\n");
		if (source >= 670 && source < 700)
		{
			printf("985\n");
		}
		else if (source <= 670 && source > 620)
		{
			printf("211\n");
		}
	}
	else if (source >= 700)
		printf("c9\n");
	else if (source >= 500)
		printf("2\n");
	else if (source > 400)
		printf("3\n");
	else
		printf("0\n");
}

// 3 注意事项
void test3()
{
	int a=2, b=1;
	if (a > b)		//1 if (a > b); 分号不能加 否则后面的语句不判断直接运行
		printf("a > b\n");
		//printf("a > b\n");
	// 2 if 不加{} 只能识别一句命令

	//3 对比操作中要 == 号  if（num = 1）
}

//三只小猪称体重
void test4()
{
	int a;
	int b;
	int c;
	printf("请输入三个整数abc\n");
	scanf("%d %d %d",&a,&b,&c);		//scanf内千万不要加\n
	printf("a=%d b=%d c=%d\n",a,b,c);
	if (a > b)
	{
		if (b>c)
		{
			printf("a>b>c\n");
		}
		else if (b < c)
		{
			if(a > c)
			{
				printf("a>c>b\n");
			}
			else
			{
				printf("c>a>b\n");
			}
		}
	}
	else if (a < b)
	{
		if (a > c)
		{
			printf(" b>a>c\n");
		}
		else if (a < c)
		{
			if (b > c)
			{
				printf("b>c>a\n");
			}
			else
			{
				printf("c>b>a\n");
			}
		}
	}
	else if (a == b)
	{
		if (a>c)
		{
			printf("a=b>c");
		}
		else if(a<c)
		{
			printf("c>a=b");
		}
	}
}

//三目运算符
void test5()
{
	int a = 10;
	int b = 20;
	int c = 0;
	c = a > b ? a : b;	//如果a>b 1执行a 0执行b
	printf("c= %d\n",c);	//20

	//优点 短小整洁 缺点 用嵌套语句不够清晰
}

//switch语句
void test6()
{	
	//9-10
	//7-8
	//5-6
	//<5
	int source;		//条件 只能是整数或者char形式
	printf("给电影打分(1-10)\n");
	scanf("%d",&source);
	switch (source)
	{
	case 10:
	case 9:
		printf("经典必看\n");
		break;	//结束当前case语句
	case 8:
	case 7:
		printf("非常好\n");
		break;
	case 6:
	case 5:
		printf("一般\n");
		break;
	default:	//默认
		printf("烂片\n");
		break;
	}
	//多条件语句判断 switch执行效率高，结构清晰
	//缺点 数据类型局限  判断区间麻烦
}


int main()
{
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	system("pause");
	return EXIT_SUCCESS;
}

