#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS

//��������������� ������Ӻ�������
//num1 num2 ��ʽ�ϵĲ��� ��û��ʵ�ʵ�ֵ  Ҳ���β�
int add(int num1, int num2) 
{
	int sum = num1 + num2;
	return sum;	//����ֵint����
}

//void ��ʾ��������Ҫ����ֵ
void test1()
{
	//�����ĵ���
	//�﷨ ������ +(����1������2)
	int num1 = 10;
	int num2 = 15;
	int sum = add(num1, num2); //ʵ�ʲ���  ʵ��
	printf("sum = %d\n",sum);

	//return; //����Ҫ����ֵ
}

//����ʹ���ڶ���ǰ��������Ҫ����
//�����Ķ���ֻ��һ�Σ��������������ж��
int get_Max(int num1, int num2);

void test2()
{
	int num1 = 100;
	int num2 = 150;
	int max = get_Max(num1, num2); //ʵ�ʲ���  ʵ��
	printf("max = %d\n", max);
}

int main()
{
	test2();
	system("pause");
	return EXIT_SUCCESS;
}

int get_Max(int num1, int num2)
{
	//˭�󷵻�˭
	return num1 > num2 ? num1 : num2;
}