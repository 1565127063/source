#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)	//�����
#pragma warning(disable:6031)	//ȥ����
#include <time.h>

//1 �޲��޷�
void func1() //function ����
{
	printf("func1\n");
}
//2 �в��޷�
void func2(int num)	//double float����
{
	printf("func2 = %d\n",num);
}
//3 �޲��з�
int func3()
{
	printf("func3\n");
	return 10;
}
//4 �в��з�
int func4(int num)
{
	int sum = num * 10;
	return sum;
}

void test1()
{
	func1();
	func2(100);
	int ret = func3();	//result
	printf("%d\n",ret);

	ret = func4(10);
	printf("%d\n", ret);
}

//��ȡ������� ���ظ��ͻ� ��Χ�û����ݱ�����
int rendom(int min, int max)
{
	int sum = 0;
	//for (int i = 0; i < 10; i++)
	//{
	//	sum = rand() % (max - min + 1) + min; //������ ��߹̶� 10-30 ���10-21
	//	printf("%d\n",sum);
	//}
	sum = rand() % (max-min+1) + min; //������ ��߹̶� 10-30 ���10-21
	return sum;
}
void test2()
{
	time_t tm = time(NULL);//�õ�ϵͳʱ��
	printf("time(NULL) = %lld\n", time(NULL)); //ʱ���ת�����ڹ���
	srand((unsigned int)tm);//�������ֻ��Ҫ����һ�μ���
	//unsigned int =  size_t
	int i;
	int j;
	printf("�������������Χ\n");
	scanf("%d %d",&i,&j);
	int rand = rendom(i,j);
	printf("��ȡ����������� %d\n",rand);
}


int main()
{
	test2();
	system("pause");
	return EXIT_SUCCESS;
}