#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS

//	!  ��	 aΪ0��	��!a Ϊ1
//	&& ��	 a & b	ͬ��Ϊ�� ����
//	|| ��	 a | b	a bֻҪ��һ��Ϊ1�����Ϊ1

//	!  ��
void test1()
{
	//0 �����  ֻҪ�Ƿ�0������
	int a = 10;
	printf("!a = %d\n",!a);		//0
	printf("!!a = %d\n", !a);	//1
	printf("!100 = %d\n", !-100);	//0
}

//	&& ��
void test2()
{
	int level = 10;
	int vip = 5;
	printf("level && vip %d\n", level > 5 && vip > 3);

	level = 3;
	vip = 20;
	printf("level && vip %d\n", level > 5 && vip > 3);

	//ͬ��Ϊ��  ����Ϊ��
	//��·���� ֻ�б��ʽ1Ϊ1 ��ִ��2
	4 < 3 && printf("YES\n");	
	4 > 3 && printf("YES\n");
}

//	|| ��
void test3()
{
	//ͬ��Ϊ��  ����Ϊ��
	int level = 10;
	int vip = 5;
	printf("level || vip %d\n", level > 5 && vip > 3);
	//��·���� ֻ�б��ʽ1Ϊ0 ��ִ�б��ʽ2
}

//��������	num>5 || num <10


int main()
{
		test3();
		system("pause");
		return EXIT_SUCCESS;
}
