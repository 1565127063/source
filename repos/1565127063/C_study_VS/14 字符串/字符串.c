#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS

//�ַ�������
void test1()
{
	printf("%s\n", "hello word");
	//˫����������ַ����Դ�������־  
	printf("sizeof=%d\n", sizeof("hello world"));//12

	//%s����ַ�����Ҫ  ���Ŀ�ʼ �������
	//" " �᷵���ַ�����һ���ַ��ĵ�ַ   ����\0�������Դ�һ��\0��
	printf("%s\n","hello\0world");	//\0������־
	printf("%s\n", "\0helloworld");	//�հ�
}

//�ַ�������
void test2()
{
	//�ַ�����
	char str[] = "hello word";
	printf("sizeof=%d\n", sizeof(str));
	str[0] = 'X';	//��ʾ��һ���ַ�
	printf("%s\n", str);	//Xello word
}

void test3()
{
	char a1 = 'a';
	char a2[] = "a";
	//a1�����ַ�    a2�����ַ��� 
	//a1ռ��1���ֽ�    a2ռ��2���ֽ�
}

int main()
{
	test1();
	test2();
	test3();
	system("pause");
	return EXIT_SUCCESS;
}