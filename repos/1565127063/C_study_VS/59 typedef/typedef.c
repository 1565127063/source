#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)	
#pragma warning(disable:6031)
#define _CRT_SECURE_NO_WARNINGS

//1.typedef��ʹ��
//��; ���������� ����� ������������

typedef int Mint;
//typedef ԭ�� ����

//
void test1()
{
	int num1 = 10;
	Mint num2 = 20;
	printf("num1 = %d  num1 = %d\n", num1, num2);
}

//2.typedef���Լ� struct�ؼ���
/* 
struct itcastCPPStudent
{
	char name[64];
	int age;
};

typedef struct itcastCPPStudent Student;
//���Լ�
*/

typedef struct itcastCPPStudent
{
	char name[64];
	int age;
}Student;
//Student ����������

void test2()
{
	struct itcastCPPStudent s1 = { "Tom",18 };
	Student s2 = { "Jerry",19 };
}

//3.������������
void test3()
{
	char* p1, p2;//���׻���
	//char* p1, *p2 //�������
	printf("sizeof(p1) = %d sizeof(p2) = %d\n", sizeof(p1),sizeof(p2)); //4 1

	typedef char* PCHER;
	PCHER p3, p4;
	printf("sizeof(p3) = %d sizeof(p4) = %d\n", sizeof(p3), sizeof(p4)); //4 4

	//32λ�� char 4�ֽ�   64λ char 8�ֽ�
}

int main()
{
	test3();

	system("pause");
	return EXIT_SUCCESS;
}