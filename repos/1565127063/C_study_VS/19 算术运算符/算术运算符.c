#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS


void test1()
{
	int a = 10;
	int b = 3;

	printf("a + b = %d\n", a + b);
	printf("a - b = %d\n", a - b);
	printf("a * b = %d\n", a * b);
	printf("a / b = %d\n", a / b);	//�������γ������� �����Ȼ�����Σ�����С����
}

void test2()
{
	int a = 10;
	int b = 20;
	printf("a / b = %d\n", a / b);	//0

	//a = 10;
	//b = 0;
	//printf("a / b = %d\n", a / b);	//error

	double c = 0.5;
	double d = 0.25;
	printf("c / d = %lf\n", c / d);	//С����ͬ�ĳ�lf

}
//%ȡģ(ȡ��)
void test3()
{
	int a = 10;
	int b = 3;
	printf("a %% b = %d\n", a % b);	//%% ���һ��%  1

	a = 10;
	b = 20;
	printf("a %% b = %d\n", a % b);	//10

	//a = 10;
	//b = 0;
	//printf("a %% b = %d\n", a % b);	//����

	//double c = 0.5;
	//double d = 0.25;
	//printf("c %% d = %lf\n", c % d);	//С��������ȡģ����
}

void test4()
{
	int num = 12345;
	printf("��λ= %d\n", num/10000);	//1.2345
	printf("ǧλ= %d\n", num/1000 %10);	//12.345 %10
	printf("��λ= %d\n", num/100 % 10);	//123.45 %10
	printf("ʮλ= %d\n", num/10 % 10);
	printf("��λ= %d\n", num % 10);		//��λ
}

//�����
void test5()
{
	//���õ���	
	int num1 = 10;
	num1++;		//num1 = num1 +1;
	printf("num1 = %d\n", num1);

	//ǰ�õ���	
	int num2 = 10;
	++num2;		//num2+1 num2=num2+1
	printf("num2 = %d\n", num2);

	//���ζ������������� ��ϼ���������
	int a = 10;
	int b = ++a * 10;	//++a �ȶԱ���++ �ټ�����ʽ
	int d = 10;
	int c = d++ * 10;	//a++	�ȼ�����ʽ �ٱ���++
	printf("a = %d\n", a);
	printf("b = %d\n", b);		//110
	printf("d = %d\n", d);
	printf("c = %d\n", c);		//100

	//��Ҫͬʱ��ǰ��++ �ͺ��� ++ 
	int a1 = 10;
	int b2 = 10;
	b2 = ++a1 * a1++ - ++a1;	
	printf("%d\n", a1);		//13
	printf("%d\n", b2);		//�Ȳ�������a1++ 12*12-12 �ٺ���++
}

int main()
{
	test1();
	test2();
	test3();
	test4();
	test5();
	system("pause");
	return EXIT_SUCCESS;
}