#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS

//printf �����һ���ַ����� putchar ���һ�� char��
void test1()
{
	int num = 10;
	printf("ʮ���ƽ�� %d\n", num);
	printf("�˽��ƽ�� %#o\n", num);
	printf("ʮ�����ƽ�� %#x\n", num);	//a ��� 16 ���Ƶ� int ���ͣ���ĸ��Сд���
	printf("ʮ�����ƽ�� %#X\n", num);	//A ��� 16 ���Ƶ� int ���ͣ���ĸ�Դ�д���
	
	//float		 %f
	//double	%lf
	//char		%c %s
}

void test2()
{
	int a = 123;	//U 10
	int b = 0123;	//O 8
	int c = 0xabc;	//H 16 
	printf("a= %d\n", a);
	printf("b= %#o\n", b);
	printf("c= %#x\n", c);
}

void test3()
{
	//%md  m ָ�������Ӧ�������������豸����ռ���ַ���
	//n ָ���ȣ�����˵�������ʵ������С��λ Ĭ��6

	printf("%5d\n", 123);	//���㲹�ո� �����Ҷ���
	printf("%2d\n", 123);	//������Ϊ׼ ��Ȳ��� �������
	printf("%05d\n", 123);	//�����ֲ���λ
	printf("%-5d\n", 123);	//���������
	// printf("%-05d\n", 123)�� - ��0 ����ͬʱ��ʾ 123 ��� 12300
}

int main()
{
	test1();
	test2();
	test3();
	system("pause");
	return EXIT_SUCCESS;
}