#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS

//����ָ��
//	*p = a  *pp = p 
//	**pp = *p = a 
void test1()
{
	int a = 10;
	int* p = &a;
	int** pp = &p;

	printf("a = %d\n", a);			//a��ֵ
	printf("*p = %d\n", *p);		//��ַpָ���ֵ a��ֵ
	printf("**pp = %d\n", **pp);	//**pp��ֵ ��*p  a��ֵ

	printf("&a = %d\n", &a);		//a�ĵ�ַ
	printf("p = %d\n", p);			//p��ֵ ����a�ĵ�ַ
	printf("*pp = %d\n", *pp);		//*pp�ȼ���p  a�ĵ�ַ

	printf("pp = %d\n", pp);		//pp�ĵ�ַ
}

int main()
{

	test1();

	system("pause");
	return EXIT_SUCCESS;
}