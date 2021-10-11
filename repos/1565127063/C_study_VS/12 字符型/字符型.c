#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS

void test1() {
	char ch = 'a';
	//字符型变量用单引号
	//只能有一个字符，不能字符串，可以转义字符
	printf("ch = %c\n", ch);
	printf("char类型的大小：%d\n", sizeof(ch));	//1个字节
	//ASCII码
	printf("%d\n", ch);	//97
	//char 也称为小整形
	ch = 98;
	printf("%c\n", ch);
	//A65 a97 逆推回来  32差值

	//char sh = "abcd";
	//printf("ch = %c\n", sh);//返回第一个字符的地址编号
}
void test02() {
	char ch = 'a';
	printf("转换前 ch=%c\n", ch);
	ch = ch - 32;
	printf("转换后 ch=%c\n", ch);
}

void test03() {
	char ch1 = 'Z';
	printf("转换前 ch1=%c\n", ch1);
	ch1 = ch1 + 32;
	printf("转换后 ch1=%c\n", ch1);
}

int main() {

	test1();
	test02();
	test03();
	system("pause");
	return EXIT_SUCCESS;
}