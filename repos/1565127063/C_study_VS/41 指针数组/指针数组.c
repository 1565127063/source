#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS

//ָ������ ������ÿ��Ԫ�ص�����Ϊָ��
void test1()
{
	int num1 = 10;
	int num2 = 20;
	int num3 = 30;
	int num4 = 40;

	int* arr[4] = { &num1,&num2,&num3,&num4 };
	int len = sizeof(arr) / sizeof(int*);
	for (int  i = 0; i < len; i++)
	{
		printf("%d\n",*arr[i]);	//[]���ȼ���� ���()
		//printf("%d\n",**(arr+i)); //[]��������  *() �ļ�д
	}
}
//
void test2()
{
	char* arr[4] = { "aaa","bbb","ccc","ddd" };
	int len = sizeof(arr) / sizeof(char*);
	for (int i = 0; i < len; i++)
	{
		printf("%s\n", arr[i]);	//��һ��a��ʼ  "�Դ�\0
		//printf("%s\n", &arr[i]); //��ӡ��λ
	}
}
 
//ָ������� 
void test3()
{ 
	//ͬһ�������ָ��������Ի�ȡָ���ĸ���
	// ���Һ�����Ķ��������޹� int short
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int* p1 = arr;
	int* p2 = &arr[4];
	printf("%d\n",(int)p1 + (int)p2);	//������ǵ�ַ ���������
	printf("%d\n", p2 - p1);	//arr[4] -arr[0] = 4 
	//ָ��˳������� 

	//�ж�ָ���Ƿ���� 
	if (p1 == NULL)
	{
		printf("p1�ǿ�ָ��\n");
	}
	else
	{
		printf("p1���ǿ�ָ��\n");
	}
	if (p1 == p2)
	{
		printf("p1 = p2\n");
	}
	else
	{
		printf("p1 != p2\n");
	}
}

int main()
{
	test1();
	test2();
	test3();
	system("pause");
	return EXIT_SUCCESS;
}