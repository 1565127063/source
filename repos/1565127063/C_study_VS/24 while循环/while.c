#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>	//srand()
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)	//�����
#pragma warning(disable:6031)

//֪��ѭ������for ��֪��ʱwhile

void test1()
{
	//while (num = 1) �ж��Ƿ��� ���Ǿ͵ȴ�
	int num = 0;
	while (num<9)
	{
		num++;
		printf("%d\n",num);
	}
	//��������ѭ���ĳ��� ����while��1����ѭ��
}

//ϵͳ����1-100������²�
void test2()
{
	//������������ ���������������̶� 
	srand((unsigned int) time(NULL));
	//time(NULL) 1970��1��1����������� ֻ��Ҫ����һ��
	int num = rand() % 100;	//����0~99�����
	//printf("%d\n", num);

	int val;
	while (1)
	{
		printf("����һ��1-100������\n");
		scanf("%d",&val);
		if (val > num)
		{
			printf("�²����\n");
		}
		else if (val < num)
		{
			printf("�²��С\n");
		}
		else
		{
			printf("��ϲ��¶��ˣ�num��%d\n",num);
			break;	//�����˳�ѭ��
		}
	}

}

//�ж�ˮ�ɻ���
void test3()
{
	//do while ��ִ��һ�����ж����� 
	//1.�ȴ�ӡ������
	int num = 100;
	do
	{
		//2.�ж�ˮ�ɻ���
		int a, b, c;
		a = num / 100;
		b = num % 10;
		c = num / 10 % 10;
		if (num == a*a*a+b*b*b+c*c*c)
		{
			printf("ˮ�ɻ���  %d\n", num);
		}
		num++;
	} while (num < 1000);
}

//forѭ��������ʽ
void test4()
{
	for (int num = 0; num < 10; num++)
	{
		printf("%d\n", num);
	}
}

//������Ϸ
//1-100 ��λ ʮλ��7 ����7�ı���������
void test5()
{
	//7�ı��� %7 == 0��
	//��λ��7 %10 == 7��
	//ʮλ��7 70-79  /10==7��
	for (int num = 1; num < 100; num++)
	{
		if (num%7==0 || num%10==0 || num/10==7)
		{
			printf("������\n");
		}
		else
		{
			printf("%d\n",num);
		}
	}
}

int main()
{
	printf("test\n");
	test3();
	system("pause");
	return EXIT_SUCCESS;
}