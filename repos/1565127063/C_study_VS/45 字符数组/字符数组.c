#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)	
#pragma warning(disable:6031)
#define _CRT_SECURE_NO_WARNINGS

void setChar(char* arr, int len)
{
	printf("���ַ�����ֵ\n");
	fgets(arr, len, stdin);
}
//
void test1()
{
	char buf[30] = { 0 };
	//int len = sizeof(buf) / sizeof(char);
	// 1 ���庯����buf��ֵ
	setChar(buf, sizeof(buf));
	//��һ��ʱ���Ѿ�������\n hello wordl\0000
	//��\n�ĳ�\0
	buf[strlen(buf) - 1] = '\0';
	printf("buf = %s\n", buf);

	// 2.�Լ�ʵ��strlen ͳ���ַ������ĺ���
	int count = myStrlen(buf);
	printf("strlen = %d\n", strlen(buf));
	printf("%d\n", count);

	// 3. ��Сдת��
	printf("ת��ǰ = %s\n", buf);

	changeArr(buf, count);
	
	printf("ת���� = %s\n", buf);
}
//��Сдת��
int changeArr(char* arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		if (arr[i] >= 'a' && arr[i]<'z')
		{
			//arr[i] = arr[i] - ('a' - 'A');
			arr[i] = arr[i] - 32;
		}
		else if (arr[i] >= 'A' && arr[i]<='Z')
		{
			//arr[i] = arr[i] + ('a' - 'A');
			arr[i] = arr[i] + 32;
		}
	}
}

int myStrlen(char* arr)
{
	int count = 0;
	while ( arr[count] != '\0')
	{
		count++;
	}
	return count;
	/*while (arr[count++] != '\0')
	{
		//����������Ҳ���һ������
	}
	return count-1;*/
}

int g_a = 1000;	//ȫ�ֱ���

//дһ�����������Է���g_a�ĵ�ַ
int* getAddress()
{
	//return &g_a; �ȼ�������
	int* p = &g_a;
	return p;
}

//
void test3()
{
	int* p = getAddress();
	printf("g_a = %d\n", g_a);
	printf("*p = %d\n", *p);
	*p = 2000;
	printf("g_a = %d\n", g_a);
	printf("*p = %d\n", *p);
}

int main()
{
	test1();

	system("pause");
	return EXIT_SUCCESS;
}