#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS


void test1()
{
	int a = 10;
	int b = 3;

	printf("a + b = %d\n", a + b);
	printf("a - b = %d\n", a - b);
	printf("a * b = %d\n", a * b);
	printf("a / b = %d\n", a / b);	//两个整形除法计算 结果仍然是整形（舍弃小数）
}

void test2()
{
	int a = 10;
	int b = 20;
	printf("a / b = %d\n", a / b);	//0

	//a = 10;
	//b = 0;
	//printf("a / b = %d\n", a / b);	//error

	double c = 0.5;
	double d = 0.25;
	printf("c / d = %lf\n", c / d);	//小数相同改成lf

}
//%取模(取余)
void test3()
{
	int a = 10;
	int b = 3;
	printf("a %% b = %d\n", a % b);	//%% 输出一个%  1

	a = 10;
	b = 20;
	printf("a %% b = %d\n", a % b);	//10

	//a = 10;
	//b = 0;
	//printf("a %% b = %d\n", a % b);	//崩溃

	//double c = 0.5;
	//double d = 0.25;
	//printf("c %% d = %lf\n", c % d);	//小数不可以取模运算
}

void test4()
{
	int num = 12345;
	printf("万位= %d\n", num/10000);	//1.2345
	printf("千位= %d\n", num/1000 %10);	//12.345 %10
	printf("百位= %d\n", num/100 % 10);	//123.45 %10
	printf("十位= %d\n", num/10 % 10);
	printf("个位= %d\n", num % 10);		//个位
}

//运算符
void test5()
{
	//后置递增	
	int num1 = 10;
	num1++;		//num1 = num1 +1;
	printf("num1 = %d\n", num1);

	//前置递增	
	int num2 = 10;
	++num2;		//num2+1 num2=num2+1
	printf("num2 = %d\n", num2);

	//单次独立增加无区别 混合计算有区别
	int a = 10;
	int b = ++a * 10;	//++a 先对变量++ 再计算表达式
	int d = 10;
	int c = d++ * 10;	//a++	先计算表达式 再本身++
	printf("a = %d\n", a);
	printf("b = %d\n", b);		//110
	printf("d = %d\n", d);
	printf("c = %d\n", c);		//100

	//不要同时有前置++ 和后置 ++ 
	int a1 = 10;
	int b2 = 10;
	b2 = ++a1 * a1++ - ++a1;	
	printf("%d\n", a1);		//13
	printf("%d\n", b2);		//先不看后置a1++ 12*12-12 再后置++
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