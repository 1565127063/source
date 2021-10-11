#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS

//	!  非	 a为0，	则!a 为1
//	&& 与	 a & b	同真为真 否则
//	|| 或	 a | b	a b只要有一个为1，结果为1

//	!  非
void test1()
{
	//0 代表假  只要是非0都是真
	int a = 10;
	printf("!a = %d\n",!a);		//0
	printf("!!a = %d\n", !a);	//1
	printf("!100 = %d\n", !-100);	//0
}

//	&& 与
void test2()
{
	int level = 10;
	int vip = 5;
	printf("level && vip %d\n", level > 5 && vip > 3);

	level = 3;
	vip = 20;
	printf("level && vip %d\n", level > 5 && vip > 3);

	//同真为真  其余为假
	//短路特性 只有表达式1为1 才执行2
	4 < 3 && printf("YES\n");	
	4 > 3 && printf("YES\n");
}

//	|| 或
void test3()
{
	//同假为假  否则为真
	int level = 10;
	int vip = 5;
	printf("level || vip %d\n", level > 5 && vip > 3);
	//短路特性 只有表达式1为0 才执行表达式2
}

//区间描述	num>5 || num <10


int main()
{
		test3();
		system("pause");
		return EXIT_SUCCESS;
}
