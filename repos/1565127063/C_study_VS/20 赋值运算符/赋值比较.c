#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS

//赋值运算
//将 = 右边的值 赋给 = 左边
//左值： 只能在=左边的值 
//右值： 只能在=右边的值
void test1()
{
	int a = 10;
	a = 20;
	int b = 20;
	b = a;	//b是左值 a也是左值 20右值

	a += 2;	// a= a + 2
	printf("%d\n", a);	//12

	a = 10;
	a -= 2;
	printf("%d\n", a);	//8

	a = 10;
	a *= 2;
	printf("%d\n", a);	//20

	a = 10;
	a /= 2;
	printf("%d\n", a);	//5

	int num = 10;
	num *= 3 + 5;	//num = num * (3+5)  80
	printf("%d\n", num);	// 混合运算等号右边视为整体

}

//0 代表假  除了0都是真
void test2()
{
	int a = 10;
	int b = 20;
	printf("a == b %d\n", a == b);	//判断中  ==
	printf("a != b %d\n", a != b);
	printf("a > b  %d\n", a > b);
	printf("a < b  %d\n", a < b);
}

//优先级越高数值越小
void test3()
{
	//算数
//1		[] () . ->								左到右	--
//2		- ~ ++ -- *(p) & ! (类型) sizeof		右到左	单目运算符
//3		/ * %									左到右	双目运算符
//4		+ -										左到右	双目
//5		<< >>									左到右	双目
//6		> >= < <=								左到右	双目
//7		== !=									左到右	双目
//8		&										左到右	双目
//9		^										左到右	双目
//10	|										左到右	双目
//11	&&										左到右	双目
//12	||										左到右	双目
//13	?;										右到左	三目运算符
//14	== /=  *= %= += -= <<= >>= &= ^= |=		右到左	--
//15	,
}

void test4()
{
	//
	int a = 10;
	printf("%d\n", ++a * 10);	//110
	printf("%d\n", a = 23 > 24);		//0
	printf("%d\n", 1 || 1 & 0);		//1
	a += a -= a *= a /= 5;		//0  右到左
	printf("%d\n", a);

	int num = 0;
	num = 1, 2, 3, 4;
	printf("%d\n", num);	//1
	int num1 = (1, 2, 3, 4);
	printf("%d\n", num1);	//4
}

int main()
{
	test1();
	test2();
	test3();
	test4();
	system("pause");
	return EXIT_SUCCESS;
}