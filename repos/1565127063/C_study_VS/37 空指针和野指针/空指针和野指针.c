#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS

//��ָ��
void test1()
{
	//ָ�����ָ���ַΪ0�ĵ�ַ
	int * p = NULL;	// #define NULL ((void *)0)

	//����ָ�����ʱ ���Գ�ʼ��ΪNULL

	//�����Է��ʿ�ָ�������
	//printf("%d\n", p); //p��ֵ
	//printf("%d\n",*p); //�ڴ��ַ���0-255֮�䱻ϵͳռ�� �����Է���
}

//Ұָ��
void test2()
{
	//ָ�����ָ��Ƿ����ڴ�����
	int* p = 0xfff;
	//printf("%d\n", p);
	//printf("%d\n", *p);	//error

	int* p1;	//ָ�����δ��ʼ�� ����Ұָ��
	//printf("%d\n", *p1);	//vs����������
}

//void����;
void test3()
{
	//�������޷��������� ԭ���Ǳ�������֪����������ֽ�
	//void a = 10;
	//void ����;�����κ�������ֵ���ͣ������β�
	/*
void fun(void)
{
	printf("\n");
	return 0;
	//���������� return  void
}
fun()	//���Ͻ�
{
	printf("\n");
	//��������
}
*/
}

//������ָ�� ����ָ��
void test4()
{
	void * p = NULL;
	printf("sizeof(p) = %d\n",sizeof(p));	//4

	int num = 10;
	p = &num;
	printf("%d\n",*(int*)p);	//void * ����ֱ�ӽ����� ��Ҫת��int*

	int* p1 = NULL;
	char* p2 = NULL;
	p2 = (int*)p1;	//ǿ������ת��
	p2 = p;	//void *����ǿתҲ�������� 
	//void * ������������ָ�� ��Ϊ����ָ��
}

int main()
{
	test2();
	//test1();
	system("pause");
	return EXIT_SUCCESS;
}
