#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS

//1.������ͬ��+1����Ծ�ֽ� ��ͬ
void test1()
{
	int* p1 = NULL;
	printf("%d\n",p1);			//0
	printf("%d\n", p1+1);		//4
	char* p2 = NULL;	
	printf("%d\n", p2);			//0
	printf("%d\n", p2 + 1);		//1
	double* p3 = NULL;
	printf("%d\n", p3);			//0
	printf("%d\n", p3 + 1);		//8
}

//2.������ʱ��ȡ�����ֽڲ�ͬ
void test2()
{
	//16�������ٶ����ֽڴ�� 
	//1������4λ 2������һ���ֽ�bit �պ�4���ֽ�
	int num = 0x01020304;
	int* p = &num;
	printf("*p = %#x\n",*p);	//*p = 0x1020304
	short* p2 = &num;
	printf("*p = %#x\n", *p2);	//0x0304
	char* p3 = &num;
	printf("*p = %#x\n", *p3);	//0x4
}

//3.
void test3()
{

}

//4.
void test4()
{

}


int main()
{

	test2();

	system("pause");
	return EXIT_SUCCESS;
}