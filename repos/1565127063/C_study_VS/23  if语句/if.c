#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS	
#pragma warning(disable:4996)	
#pragma warning(disable:6031)	

//1������if
void test1()
{
	int source;
	printf("�������ķ���\n");
	scanf("%d", &source);	//��Ҫ�� \n
	printf("������ķ����� %d ��\n", source);
	if (source > 600)
		printf("1\n");
	else
	{
		printf("!1\n");
	}
}

//2 ����if
void test2()
{
	int source;
	printf("�������ķ���\n");
	scanf("%d", &source);	//��Ҫ��\n
	printf("������ķ����� %d��\n", source);

	if (source >= 600)
	{
		printf("1\n");
		if (source >= 670 && source < 700)
		{
			printf("985\n");
		}
		else if (source <= 670 && source > 620)
		{
			printf("211\n");
		}
	}
	else if (source >= 700)
		printf("c9\n");
	else if (source >= 500)
		printf("2\n");
	else if (source > 400)
		printf("3\n");
	else
		printf("0\n");
}

// 3 ע������
void test3()
{
	int a=2, b=1;
	if (a > b)		//1 if (a > b); �ֺŲ��ܼ� ����������䲻�ж�ֱ������
		printf("a > b\n");
		//printf("a > b\n");
	// 2 if ����{} ֻ��ʶ��һ������

	//3 �ԱȲ�����Ҫ == ��  if��num = 1��
}

//��ֻС�������
void test4()
{
	int a;
	int b;
	int c;
	printf("��������������abc\n");
	scanf("%d %d %d",&a,&b,&c);		//scanf��ǧ��Ҫ��\n
	printf("a=%d b=%d c=%d\n",a,b,c);
	if (a > b)
	{
		if (b>c)
		{
			printf("a>b>c\n");
		}
		else if (b < c)
		{
			if(a > c)
			{
				printf("a>c>b\n");
			}
			else
			{
				printf("c>a>b\n");
			}
		}
	}
	else if (a < b)
	{
		if (a > c)
		{
			printf(" b>a>c\n");
		}
		else if (a < c)
		{
			if (b > c)
			{
				printf("b>c>a\n");
			}
			else
			{
				printf("c>b>a\n");
			}
		}
	}
	else if (a == b)
	{
		if (a>c)
		{
			printf("a=b>c");
		}
		else if(a<c)
		{
			printf("c>a=b");
		}
	}
}

//��Ŀ�����
void test5()
{
	int a = 10;
	int b = 20;
	int c = 0;
	c = a > b ? a : b;	//���a>b 1ִ��a 0ִ��b
	printf("c= %d\n",c);	//20

	//�ŵ� ��С���� ȱ�� ��Ƕ����䲻������
}

//switch���
void test6()
{	
	//9-10
	//7-8
	//5-6
	//<5
	int source;		//���� ֻ������������char��ʽ
	printf("����Ӱ���(1-10)\n");
	scanf("%d",&source);
	switch (source)
	{
	case 10:
	case 9:
		printf("����ؿ�\n");
		break;	//������ǰcase���
	case 8:
	case 7:
		printf("�ǳ���\n");
		break;
	case 6:
	case 5:
		printf("һ��\n");
		break;
	default:	//Ĭ��
		printf("��Ƭ\n");
		break;
	}
	//����������ж� switchִ��Ч�ʸߣ��ṹ����
	//ȱ�� �������;���  �ж������鷳
}


int main()
{
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	system("pause");
	return EXIT_SUCCESS;
}

