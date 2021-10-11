#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS

//浮点型常量，不要在浮点型常量中间加空格
//正号可以省略。 可以没有小数点（如， 2E5） 或指数部分（如，19.28），但是不能同时省略两者。
void test1() 
{
	printf("1.56E+12\n");
	printf("2.87e-3\n");
	printf("sizeof 3.14=%d\n", sizeof(3.14));  //默认小数是double 8
	printf("sizeof 3.14 f =%d\n", sizeof(3.14f)); //最后+f变成float 4
}
//浮点型变量 
void test2() {
	float a = 3.1415f;
	printf("a= %f\n", a); //%f 保留6位小数
	printf("a= %.2f\n", a); //%.2f 保留2位小数
	printf("sizeof a=%d\n", sizeof(a));

	double b = 3.1415;
	printf("b= %lf\n", b); //%lf double形的表示
	printf("b= %.3lf\n", b); //%.3lf double （四舍五入）
	printf("sizeof b=%d\n", sizeof(b));

	float PI = 3.1415926358;
	printf("PI= %.10f\n", PI);
	double PI2 = 3.1415926358;
	printf("PI2 = %.10f\n", PI2);

	//科学计数法
	float f1 = 3e2;		//3*10^2
	printf("f1 = %.10f\n", f1);
	float f2 = 3e-2;	//3*10^(-2）
	printf("f1 = %f\n", f2);
}


int main() {

	test1();
	test2();
	system("pause");
	return EXIT_SUCCESS;
}