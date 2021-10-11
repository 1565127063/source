#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)	//必须的
#pragma warning(disable:6031)	//去警告
#include <time.h>

//1 无参无反
void func1() //function 函数
{
	printf("func1\n");
}
//2 有参无反
void func2(int num)	//double float随意
{
	printf("func2 = %d\n",num);
}
//3 无参有反
int func3()
{
	printf("func3\n");
	return 10;
}
//4 有参有反
int func4(int num)
{
	int sum = num * 10;
	return sum;
}

void test1()
{
	func1();
	func2(100);
	int ret = func3();	//result
	printf("%d\n",ret);

	ret = func4(10);
	printf("%d\n", ret);
}

//获取随机数字 返回给客户 范围用户传递闭区间
int rendom(int min, int max)
{
	int sum = 0;
	//for (int i = 0; i < 10; i++)
	//{
	//	sum = rand() % (max - min + 1) + min; //闭区间 左边固定 10-30 左边10-21
	//	printf("%d\n",sum);
	//}
	sum = rand() % (max-min+1) + min; //闭区间 左边固定 10-30 左边10-21
	return sum;
}
void test2()
{
	time_t tm = time(NULL);//得到系统时间
	printf("time(NULL) = %lld\n", time(NULL)); //时间戳转换日期工具
	srand((unsigned int)tm);//随机种子只需要设置一次即可
	//unsigned int =  size_t
	int i;
	int j;
	printf("请输入随机数范围\n");
	scanf("%d %d",&i,&j);
	int rand = rendom(i,j);
	printf("获取到的随机数是 %d\n",rand);
}


int main()
{
	test2();
	system("pause");
	return EXIT_SUCCESS;
}