#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS

void test1() {
	char ch = 'a';
	//�ַ��ͱ����õ�����
	//ֻ����һ���ַ��������ַ���������ת���ַ�
	printf("ch = %c\n", ch);
	printf("char���͵Ĵ�С��%d\n", sizeof(ch));	//1���ֽ�
	//ASCII��
	printf("%d\n", ch);	//97
	//char Ҳ��ΪС����
	ch = 98;
	printf("%c\n", ch);
	//A65 a97 ���ƻ���  32��ֵ

	//char sh = "abcd";
	//printf("ch = %c\n", sh);//���ص�һ���ַ��ĵ�ַ���
}
void test02() {
	char ch = 'a';
	printf("ת��ǰ ch=%c\n", ch);
	ch = ch - 32;
	printf("ת���� ch=%c\n", ch);
}

void test03() {
	char ch1 = 'Z';
	printf("ת��ǰ ch1=%c\n", ch1);
	ch1 = ch1 + 32;
	printf("ת���� ch1=%c\n", ch1);
}

int main() {

	test1();
	test02();
	test03();
	system("pause");
	return EXIT_SUCCESS;
}