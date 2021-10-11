#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include<string.h>

void test01() {

	//int char if extem void const等
}

//标识符命名规则（变量名的规范）	
//1.不可以是关键字
//2.只能是字母、数字、下划线组成
//3.第一个字符必须是字母或者下划线
//4.标识符的字母区分大小写
void test02() {
	int a = 10;
		//int extern = 10;	error
	int a_b1 = 10;
		//int 123abc = 10;	 error
	//printf("a = %d\n",A);  error
	printf("a = %d\n", a);
	//最好能做到见名知意
	int num1 = 10;
	int num2 = 20;
	int sum = num1 + num2;
	printf("%d = %d + %d\n", sum, num2, sum);
}

int main() {

	test02();
	system("pause");
	return EXIT_SUCCESS;
}