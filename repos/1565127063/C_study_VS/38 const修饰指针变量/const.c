#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS

//1.const ���ε� *  *pֻ�ɶ� p�ɶ���д  
// "����ָ��" ָ���ֵ�ǳ���*p
void test1()
{
	int a = 10;
	const int* p = &a;	//�ȼ��� int const * p = &a;
	// *p = 20; ��ʱ*pֻ�� ָ���ֵ�������޸�
	int b = 20;
	p = &b;	 //ָ��ָ������޸�  
	printf("%d\n",*p);
	//p ����ָ������ ���� *p �ǲ������޸ĵ�
}
//�ټ�   const����  *ָ��  ����˳���
//const int* p = &a;    ����ָ��  ������ǰ  ָ���ֵ*p�̶�
//int* const p = &a;	ָ�볣��  ָ����ǰ	ָ��ķ���p�̶�

//2.const ���ε� p  pֻ�ɶ� *p�ɶ���д  
//ָ�볣��  ��ĳ������ܸ�
void test2()
{
	int a = 10;
	int* const p = &a;
	*p = 20;	//ָ���ֵ�����޸�
	int b = 20; 
	// p = &b; //error ָ���ָ�򲻿����޸� 

}

//3.const ͬʱ���ε� *��p
void test3()
{
	//ָ��ָ���ָ���ֵ���������޸�
	int a = 10;
	const int* const p = &a;
	//*p = 20;	  //error ָ���ֵ*p�������޸�
	int b = 20;
	// p = &b;	  //error ָ���ָ��p�������޸� 
}

int main()
{
	test1();
	system("pause");
	return EXIT_SUCCESS;
}