#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS	//û����
#pragma warning(disable:4996)	//�����
#pragma warning(disable:6031)	//ȥ����
//scanfʵ����������

//1���������ݵ�����
void test1()
{
	int num = 0;
	printf("��������numֵ\n");
	scanf("%d",&num);	//&ȡ������ַ
	printf("num = %d\n", num);
}

//2���ַ��͵�����
void test2()
{
	char ch = 'a';
	printf("��������charֵ\n");
	scanf("%c", &ch);	//&ȡ������ַ
	printf("char= %c\n", ch);
}

//3�������͵�����
void test3()
{
	double d = 3.14;
	printf("��������dֵ\n");
	scanf("%lf", &d);	//&ȡ������ַ
	printf("d= %.3lf\n", d);
}

//4.�ַ�������
void test4()
{
	/*char str[] = " ";*/
	char str[64] = " ";
	printf("���������ַ���str\n");
	scanf("%s",str);	//����Ҫȡ��ַ��&
	printf("str = %s\n", str);
}

//5.ע������
void test5()
{
	//��Ҫ����������ʱ��10\n ȡ����10  \n������ ���ch

	int num = 0;
	printf("��������numֵ\n");
	scanf("%d", &num);	//&ȡ������ַ
	printf("num = %d\n", num);

	getchar();	//�ӻ�������ȡ��ֵ

	char ch = 'a';
	printf("��������charֵ\n");
	scanf("%c", &ch);	//&ȡ������ַ
	printf("char= %c\n", ch);

	putchar('a');	//����Ļ��ӡ�ַ�
	printf("\n");
}

int main()
{
	test5();

	system("pause");
	return EXIT_SUCCESS;
}