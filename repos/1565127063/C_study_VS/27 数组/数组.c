#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS

//����Ķ���
void test1()
{
	//�����﷨1�� �������� ��������[Ԫ�ظ���]
	int a[10];
	//���鸳ֵ
	a[0] = 100;
	a[1] = 90;
	a[2] = 90;
	a[3] = 90;

	//�����﷨2�� �������� ��������[Ԫ�ظ���]={0,1,2};
	int b[10] = { 10,20,30,40,50,60,70,80,90 };//���ֳ�ʼ�� δ����0
	//int b[10]; //
	//int b[10] = {a[0]=10,a[4]=50,a[8]=90}; //��ʼ���ᱻ����0
	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", b[i]);
	}

	//�����﷨3�� �������� ��������[]={0,1,2}
	//��������﷨	int c[];
	int c[] = { 10,20,30,40,50 };

	//ע������
	int d = 10;
	//int b[d] = {0}; //error Ԫ�ظ���a�����ǳ���
}

//�������;
void test2()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	//1��sizeof(������)  ����ͳ����������ռ���ڴ�ռ��С
	printf("sizeof arr = %d\n", sizeof(arr));//40
	printf("sizeof arr[0] = %d\n", sizeof(arr[0]));//4
	printf("Ԫ�ظ���%d\n", sizeof(arr) / sizeof arr[0]);//10

	//2����������������ȡ������׵�ַ
	//printf("�׵�ַ�� %d\n", arr);
	//printf("�����е�һ��Ԫ�صĵ�ַ�� %d\n", &arr[0]);//19920472
	//printf("�����е�һ��Ԫ�صĵ�ַ�� %d\n", &arr[1]);//19920476
	//��֤��ַ�������ռ� ÿ�ζ���һ��  �����϶��������Ĳ�4

	//3����������һ���������������޸ĵ�
	//arr =100��error �������ǳ���
}

//���� ��ֻС�������
void test3()
{
	int arr[5] = { 200,300,250,500,400 };
	int max = 0;	//�϶����ֵ���±���0
	int len = sizeof(arr) / sizeof(int);
	for (int i = 0; i < len; i++)
	{
		if (arr[i] > arr[max])
		{
			max = i;
		}
	}
	printf("���ص�����%d�ţ�������%d\n",max+1,arr[max]); //���arr[0];
}

//�������
void test4()
{
	int arr[5] = { 200,300,250,500,400 };
	int min = 0;	//�϶���Сֵ���±���0
	int len = sizeof(arr) / sizeof(int);
	printf("�����ֻ��ֵ\n");
	for (int i = 0; i < len; i++)
	{
		scanf_s("%d",&arr[i]);
	}
	for (int i = 0; i < len; i++)
	{
		if (arr[i] < arr[min])
		{
			min = i;
		}
	}
	printf("���������%d�ţ�������%d\n", min+1, arr[min]);//0��ʼ ��ʾ1
}

//9*9�˷���
void test5()
{
	for (int i = 0; i <= 9; i++)
	{
		//printf("�� %d ��\n",i);
		for (int j = 1; j <= i; j++)
		{
			printf("%d*%d=%d ", j, i,i*j);
		}
		printf("\n");
	}
}

//Ԫ������
void test6()
{
	//13542  ���� 24531
	long arr[] = { 1 , 3 , 5  ,4 , 2 };
	int start = 0;
	printf("����ǰ\n");
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	int end = sizeof(arr) / sizeof(int) - 1;
	while (start < end)
	{
		int temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		start++;
		end--;
	}
		//��������
		printf("���ú�\n");
		for (int  i = 0; i < sizeof(arr) / sizeof(int); i++)
		{
			printf("%d ",arr[i]);
		}
		printf("\n");
}

//��ֻС�������
void test03()
{
	int Pig_Buff[5] = { 10,50,66,85,5 };
	int Pig_max = 0;
	int length = sizeof(Pig_Buff) / sizeof(int);
	for (int i = 0; i < length; i++)
	{
		if (Pig_Buff[i] > Pig_Buff[Pig_max])
		{
			Pig_max = i;
		}
	}
	printf("%d\n", Pig_Buff[Pig_max]);
}

//99�˷���
void test04()
{
	int i = 0, j = 0;
	for (i = 0; i <= 9; i++)
	{
		for (j = 1; j <= i; j++)
		{
			printf(" %d * %d = %d ", i, j, i * j);
		}
		printf("\n");
	}

}
//Ԫ������
void test06()
{
	//13542  ���� 24531
	int arr[] = { 1,3,5,4,2 };
	int start = 0;

	for (int i = 0; i < sizeof(arr)/sizeof(int); i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	int end = sizeof(arr) / sizeof(int) - 1; //���һ�������±�
	int temp;
	while (start < end)
	{
		temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		start++; 
		end--;
	}
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int main()
{
	//test2();
	//test3();
	//test4();
	//test6();
	test06();
	system("pause");
	return EXIT_SUCCESS;
}