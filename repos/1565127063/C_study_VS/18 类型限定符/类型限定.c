#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS

//1.extern ����һ�������� extern �����ı���û�н����洢�ռ�
void test1()
{
	//����������������ʱ����û�з���������ڴ�ռ�
	//��������ⲿ�����ľֲ�����ʹ�ó�ʼֵ�趨��
	extern int g_a;
	printf("%d\n",g_a);
}

int g_a = 100;

// 2.const ����һ��������������ֵ�����޸�
void test2()
{
	const int num = 123;
	//num = 345; �޷��޸�
	printf("%d\n", num);
}

// 3.volatile
void test3()
{
	volatile int num = 10;
	//volatile ��ֹ�������Ż����� �����в���
	num = 20;
	num = 30;
	num = 40;
	num = 50;
	//printf("%d\n", num);
}

// 4.register ����Ĵ������� �п��мĴ�����Ч��û�п��в���Ч
void test4()
{	//Ƶ��ʹ�õı������뵽�Ĵ��� ������ȡ��ַ�Ĳ���

	register int num = 222;
	//
	//printf("%p\n", &num);
}

int main()
{

	test2();
	
	system("pause");
	return EXIT_SUCCESS;
}