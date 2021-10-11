#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)	
#pragma warning(disable:6031)
#define _CRT_SECURE_NO_WARNINGS

//1.普通局部变量
//作用形式：{}里面定义的变量，局部变量
//作用范围：离最近的{}里面是可以使用的
//生命周期：最近的{}结束后释放掉 
//注意事项：局部变量未初始化，值是随机的，vs下不可以访问
void test1()
{
	{
		int a = 10;
	}
	//printf("%d\n", a); a超出{}后无法使用
	
	int b = 10;
	{
		int b = 20;		
		//不同的作用域下  有重名的情况下  就近原则
		printf("b  = %d\n", b); //20 定义完被释放
	}
	printf("b  = %d\n", b);	//10
}

//2.普通全局变量
//作用形式：函数体外面定义的变量，称为全局变量
//作用范围：当前的文件和其他文件都可以使用(加关键字 extern)
//生命周期：整个程序结束后释放
//注意事项：普通的全局变量未初始化 结果为0
//g代表global 全球全局 定义时加一个g方便理解
int g_a = 10;
int g_c;
void test2()
{
	printf("test2_g_a = %d\n", g_a);
	printf("test2_g_a = %d\n", g_c);	//未定义的值为0

	extern int g_b;	//告诉编译器去其他文件中查找g_b的存在  找到可以使用
	//fatal error LNK1120 : 1 个无法解析的外部命令 可能就是未定义
	printf("test2_g_b = %d\n", g_b);
}

////3.静态局部变量
//作用形式：在{}内定义，用static修饰后，称为静态局部变量
//作用范围：离最近的{}里面是可以使用的
//生命周期：整个程序结束后释放
//注意事项：静态局部变量 未初始化 结果为0, 只能初始化一次
int* func()
{
	static int s_b = 1000;
	return &s_b;
}
void func2()
{
	int s_d = 2000;			//每次都会初始化 值固定
	static int s_c = 3000;	//只会初始化一次  所以会累加
	s_d++;
	s_c++;
	printf("s_d = %d\n", s_d);
	printf("s_c = %d\n", s_c);
}
void test3()
{
	//s表示关键字  
	static int s_a = 1000;
	printf("s_a = %d\n", s_a);
	int* p = func();
	printf("*p = %d\n", *p);
	func2();
	func2();
	func2();
	func2();
}

//4.静态全局变量
//作用形式：函数体外面定义的变量，用static修饰后，称为静态全局变量
//作用范围：当前的文件内有效（其他文件无法使用）
//生命周期：整个程序结束后释放
//注意事项：普通的全局变量未初始化 结果为0
static int g_s_a = 10000;
static int g_s_c;
void test4()
{
	printf("g_s_a = %d\n", g_s_a);	
	//其他文件定义的无法使用
	//extern static int g_s_b; //不能同时修饰 而且无法找到
	//printf("g_s_b = %d\n", g_s_b); //error
	printf("g_s_c = %d\n", g_s_c);
}

//5.全局函数和静态函数
//默认情况下写的都是全局函数，用static修饰后的函数是静态函数（少用）
void  test5()
{
	extern void test_fun1();
	test_fun1();

	//静态函数无法其他文件使用
	//extern void test_fun2();
	//test_fun2();
}

int main()
{
	test5();

	//printf("main_g_a = %d\n", g_a);
	system("pause");
	return EXIT_SUCCESS;
}
