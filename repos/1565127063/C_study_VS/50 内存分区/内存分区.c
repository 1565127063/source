#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)	
#pragma warning(disable:6031)
#define _CRT_SECURE_NO_WARNINGS

//������  ȫ����  ջ��  ���� 

//ȫ�ֱ���  ȫ����
int g_a = 10;
int g_b = 20;

//ȫ�ֳ���  ȫ����
const int g_c_a = 100;
const int g_c_b = 200;

void test1()
{
	//�ֲ�����  ջ��
	int a = 10, b = 20;
	printf("a�ĵ�ַ=%d b�ĵ�ַ=%d\n",&a,&b);//

	printf("g_a�ĵ�ַ=%d g_b�ĵ�ַ=%d\n", &g_a, &g_b);

	//��̬�ֲ�����  ȫ����
	static int s_a = 20;
	static int s_b = 10;
	printf("s_a�ĵ�ַ=%d s_b�ĵ�ַ=%d\n", &s_a, &s_b);

	//������ ȫ������
	printf("�ַ���������ַ�� %d\n", &"hello world");
	printf("�ַ���������ַ�� %d\n", &"hello world2");

	//ȫ�ֳ��� ȫ����
	printf("g_c_a������ַ�� %d\n", &g_c_a);
	printf("g_c_a������ַ�� %d\n", &g_c_b);

	//�ֲ�����  ջ��
	//�ܽ᣺ֻҪ�оֲ�  ���Ƿ���ջ��
	const int c_a = 100;
	const int c_b = 200;
	printf("c_a������ַ�� %d\n", &c_a);
	printf("c_a������ַ�� %d\n", &c_b);

	//����
	char* p = malloc(64);
	printf("p�ĵ�ַ = %d\n", p);
}

int main()
{
	test1();

	system("pause");
	return EXIT_SUCCESS;
}
