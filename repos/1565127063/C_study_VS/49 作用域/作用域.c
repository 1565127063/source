#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)	
#pragma warning(disable:6031)
#define _CRT_SECURE_NO_WARNINGS

//1.��ͨ�ֲ�����
//������ʽ��{}���涨��ı������ֲ�����
//���÷�Χ���������{}�����ǿ���ʹ�õ�
//�������ڣ������{}�������ͷŵ� 
//ע������ֲ�����δ��ʼ����ֵ������ģ�vs�²����Է���
void test1()
{
	{
		int a = 10;
	}
	//printf("%d\n", a); a����{}���޷�ʹ��
	
	int b = 10;
	{
		int b = 20;		
		//��ͬ����������  �������������  �ͽ�ԭ��
		printf("b  = %d\n", b); //20 �����걻�ͷ�
	}
	printf("b  = %d\n", b);	//10
}

//2.��ͨȫ�ֱ���
//������ʽ�����������涨��ı�������Ϊȫ�ֱ���
//���÷�Χ����ǰ���ļ��������ļ�������ʹ��(�ӹؼ��� extern)
//�������ڣ���������������ͷ�
//ע�������ͨ��ȫ�ֱ���δ��ʼ�� ���Ϊ0
//g����global ȫ��ȫ�� ����ʱ��һ��g�������
int g_a = 10;
int g_c;
void test2()
{
	printf("test2_g_a = %d\n", g_a);
	printf("test2_g_a = %d\n", g_c);	//δ�����ֵΪ0

	extern int g_b;	//���߱�����ȥ�����ļ��в���g_b�Ĵ���  �ҵ�����ʹ��
	//fatal error LNK1120 : 1 ���޷��������ⲿ���� ���ܾ���δ����
	printf("test2_g_b = %d\n", g_b);
}

////3.��̬�ֲ�����
//������ʽ����{}�ڶ��壬��static���κ󣬳�Ϊ��̬�ֲ�����
//���÷�Χ���������{}�����ǿ���ʹ�õ�
//�������ڣ���������������ͷ�
//ע�������̬�ֲ����� δ��ʼ�� ���Ϊ0, ֻ�ܳ�ʼ��һ��
int* func()
{
	static int s_b = 1000;
	return &s_b;
}
void func2()
{
	int s_d = 2000;			//ÿ�ζ����ʼ�� ֵ�̶�
	static int s_c = 3000;	//ֻ���ʼ��һ��  ���Ի��ۼ�
	s_d++;
	s_c++;
	printf("s_d = %d\n", s_d);
	printf("s_c = %d\n", s_c);
}
void test3()
{
	//s��ʾ�ؼ���  
	static int s_a = 1000;
	printf("s_a = %d\n", s_a);
	int* p = func();
	printf("*p = %d\n", *p);
	func2();
	func2();
	func2();
	func2();
}

//4.��̬ȫ�ֱ���
//������ʽ�����������涨��ı�������static���κ󣬳�Ϊ��̬ȫ�ֱ���
//���÷�Χ����ǰ���ļ�����Ч�������ļ��޷�ʹ�ã�
//�������ڣ���������������ͷ�
//ע�������ͨ��ȫ�ֱ���δ��ʼ�� ���Ϊ0
static int g_s_a = 10000;
static int g_s_c;
void test4()
{
	printf("g_s_a = %d\n", g_s_a);	
	//�����ļ�������޷�ʹ��
	//extern static int g_s_b; //����ͬʱ���� �����޷��ҵ�
	//printf("g_s_b = %d\n", g_s_b); //error
	printf("g_s_c = %d\n", g_s_c);
}

//5.ȫ�ֺ����;�̬����
//Ĭ�������д�Ķ���ȫ�ֺ�������static���κ�ĺ����Ǿ�̬���������ã�
void  test5()
{
	extern void test_fun1();
	test_fun1();

	//��̬�����޷������ļ�ʹ��
	//extern void test_fun2();
	//test_fun2();
}

int main()
{
	test5();

	//printf("main_g_a = %d\n", g_a);
	system("pause");
	return EXIT_SUCCESS;
}
