#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS

//��ֵ����
//�� = �ұߵ�ֵ ���� = ���
//��ֵ�� ֻ����=��ߵ�ֵ 
//��ֵ�� ֻ����=�ұߵ�ֵ
void test1()
{
	int a = 10;
	a = 20;
	int b = 20;
	b = a;	//b����ֵ aҲ����ֵ 20��ֵ

	a += 2;	// a= a + 2
	printf("%d\n", a);	//12

	a = 10;
	a -= 2;
	printf("%d\n", a);	//8

	a = 10;
	a *= 2;
	printf("%d\n", a);	//20

	a = 10;
	a /= 2;
	printf("%d\n", a);	//5

	int num = 10;
	num *= 3 + 5;	//num = num * (3+5)  80
	printf("%d\n", num);	// �������Ⱥ��ұ���Ϊ����

}

//0 �����  ����0������
void test2()
{
	int a = 10;
	int b = 20;
	printf("a == b %d\n", a == b);	//�ж���  ==
	printf("a != b %d\n", a != b);
	printf("a > b  %d\n", a > b);
	printf("a < b  %d\n", a < b);
}

//���ȼ�Խ����ֵԽС
void test3()
{
	//����
//1		[] () . ->								����	--
//2		- ~ ++ -- *(p) & ! (����) sizeof		�ҵ���	��Ŀ�����
//3		/ * %									����	˫Ŀ�����
//4		+ -										����	˫Ŀ
//5		<< >>									����	˫Ŀ
//6		> >= < <=								����	˫Ŀ
//7		== !=									����	˫Ŀ
//8		&										����	˫Ŀ
//9		^										����	˫Ŀ
//10	|										����	˫Ŀ
//11	&&										����	˫Ŀ
//12	||										����	˫Ŀ
//13	?;										�ҵ���	��Ŀ�����
//14	== /=  *= %= += -= <<= >>= &= ^= |=		�ҵ���	--
//15	,
}

void test4()
{
	//
	int a = 10;
	printf("%d\n", ++a * 10);	//110
	printf("%d\n", a = 23 > 24);		//0
	printf("%d\n", 1 || 1 & 0);		//1
	a += a -= a *= a /= 5;		//0  �ҵ���
	printf("%d\n", a);

	int num = 0;
	num = 1, 2, 3, 4;
	printf("%d\n", num);	//1
	int num1 = (1, 2, 3, 4);
	printf("%d\n", num1);	//4
}

int main()
{
	test1();
	test2();
	test3();
	test4();
	system("pause");
	return EXIT_SUCCESS;
}