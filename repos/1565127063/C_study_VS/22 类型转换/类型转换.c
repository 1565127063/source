#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS

//�Զ�ת��(��ʽת��)����ѭһ���Ĺ���, �ɱ���ϵͳ�Զ���ɡ�
void test1()
{
	printf("%d\n",sizeof(5 / 0.2));	//int���Զ�ת��Ϊdouble 8

	int num = 353;	//1 0110 0001
	char ch = num;	//���������λ 0110 0001  �� 97 Ϊa
	printf("%c\n", ch);

	char a = 10;
	short b = 10;
	//char 1�ֽ�  short 2�ֽ�	����ʱ������ת��Ϊint
	printf("%d\n", sizeof(a + b));//4
}
//ǿ������ת�����ѱ��ʽ��������ǿ��ת�����������������
void test2()
{
	int a = 0;
	double b = 3.14f;
	a = (int)b;		//������ǰ��д����Ҫת������ֵ
	printf("%d %.2lf\n",a,b);	//3 3.14 a��ֵ b�������ı� 
	//ǿ��ת��ע��ת��λ��

}

int main()
{
	test1();
	test2();

	system("pause");
	return EXIT_SUCCESS;
}