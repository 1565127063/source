#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include<string.h>

//声明变量会促使你在编写程序之前做一些计划
//声明变量有助于发现隐藏在程序中的小错误
//如果事先未声明变量， C程序将无法通过编译
void test01() {
	int a = 10;
	printf("a = %d\n", a);
	a = 20;
	printf("a = %d\n", a);
}
void test02() {
	int b;	//不给变量初始值的话值是随机的，且vs无法访问
	printf("b= %d\n", b);	//定义给0
}
//变量的定义在使用前，属于自动声明
//变量的定义在变量使用后，需要显示声明，例如关键字 extern
void test03() 
{
	extern int g_a;	//告诉编译器g_a定义需要查找 查找后可以查询到  不要报错
	printf("g_a = %d\n", g_a);
}
int g_a = 100;

int main() {

	test01();
	/*test02();*/
	test03();

	system("pause");
	return EXIT_SUCCESS;
}