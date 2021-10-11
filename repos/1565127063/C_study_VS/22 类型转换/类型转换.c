#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS

//自动转换(隐式转换)：遵循一定的规则, 由编译系统自动完成。
void test1()
{
	printf("%d\n",sizeof(5 / 0.2));	//int被自动转换为double 8

	int num = 353;	//1 0110 0001
	char ch = num;	//溢出舍弃高位 0110 0001  是 97 为a
	printf("%c\n", ch);

	char a = 10;
	short b = 10;
	//char 1字节  short 2字节	运算时编译器转换为int
	printf("%d\n", sizeof(a + b));//4
}
//强制类型转换：把表达式的运算结果强制转换成所需的数据类型
void test2()
{
	int a = 0;
	double b = 3.14f;
	a = (int)b;		//在数据前面写上需要转换的数值
	printf("%d %.2lf\n",a,b);	//3 3.14 a赋值 b不发生改变 
	//强制转换注意转换位置

}

int main()
{
	test1();
	test2();

	system("pause");
	return EXIT_SUCCESS;
}