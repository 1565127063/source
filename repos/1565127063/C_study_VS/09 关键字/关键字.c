#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include<string.h>

void test01() {

	//int char if extem void const��
}

//��ʶ���������򣨱������Ĺ淶��	
//1.�������ǹؼ���
//2.ֻ������ĸ�����֡��»������
//3.��һ���ַ���������ĸ�����»���
//4.��ʶ������ĸ���ִ�Сд
void test02() {
	int a = 10;
		//int extern = 10;	error
	int a_b1 = 10;
		//int 123abc = 10;	 error
	//printf("a = %d\n",A);  error
	printf("a = %d\n", a);
	//�������������֪��
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