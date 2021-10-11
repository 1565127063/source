#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS

//arr[1] = *(arr+1)
//[]��������  *() �ļ�д
void test1()
{
	int arr[5] = { 1,2,3,4,5 };
	printf("sizeof(arr) = %d\n",sizeof(arr));
	//arr ָ�������׵�ַ
	//printf("%d\n", arr);
	//printf("%d\n", arr+1);	//4bit
	printf("��һ��Ԫ�� = %d\n",arr[0]);
	printf("��һ��Ԫ�� = %d\n", *arr);
	//[]��������  *() �ļ�д
	printf("�ڶ���Ԫ�� = %d\n", arr[1]);
	printf("�ڶ���Ԫ�� = %d\n", *(arr+1));
	//������Ȼ����
	printf("�ڶ���Ԫ�� = %d\n", *(1 + arr));
	//printf("�ڶ���Ԫ�� = %d\n", 1[arr]);	//ת��1*(arr) ������

	for (int i = 0; i < 5; i++)
	{
		//printf("%d ",arr[i]);
		printf("%d ", *(arr+i));
	}
	printf("\n");

	//arr Ϊʲô��������Ԫ�صĵ�ַ 
	//&arr[0] �� &*(arr+0) �� arr
	//�������Ծ��Ե� arr ����arr[0]���׵�ַ sizeof(arr)�Ͳ�����
}

//ͨ��ָ��ٿ�����
void test2()
{
	int arr[5] = { 1,2,3,4,5 };
	int* p = arr;
	for (int i = 0; i < 5; i++)
	{
		//printf("%d\n",p[i]);
		printf("%d\n", *(p+i));
	}
	//���ڵ�����
	printf("sizeof(arr) = %d\n", sizeof(arr));	//20
	printf("sizeof(p) = %d\n", sizeof(p));	//4
	
	//���������ʱ�� �±�����Ǹ���
	//int* p2 = arr;//���������һ��Ԫ��
	int* p2 = &arr[2];
	printf("*p2 = %d\n",*p2);
	printf("*p2 = %d\n", p2[0]);
	printf("*p2 = %d\n", p2[1]);
	printf("*p2 = %d\n", p2[-1]);	//*(p2-1)
	//printf("*p2 = %d\n", p2[-10]); //Խ��
}
//�ۺϷ���
void test3()
{
	int arr[5] = { 1,2,3,4,5 };
	int* p = arr;

	printf("%d\n", *p++);	//1  ��*p ���1 ��p++ pƫ��һλ ��ַ+4 ���2
	printf("%d\n", (*p)++);	//2  ��*p ���2 ��*p++ p=3 ���ǵڶ�λ��2
	printf("%d\n", *(p++));	//3  ��*p ���3 p++ָ��ƫ��

	for (int i = 0; i < 5; i++)
	{
		//printf("%d\n",p[i]);
		printf("%d\n", arr[i]); //13345
	}

	int arr2[15] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
	printf("%d\n", arr2[*(arr2 + *(arr2 + arr2[3]))]);
	//arr2*(arr2 + arr2[3]) С������ *(arr+4) ��λ+4 ��5�ĵ�ַ
	// arr2[*(arr2+5)] 
	//arr2[*6] 7
}

int main()
{
	test3();
	system("pause");
	return EXIT_SUCCESS;
}
