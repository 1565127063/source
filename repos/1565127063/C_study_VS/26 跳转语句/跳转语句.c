#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS

//break
//1.switch���У���ֹĳ��case������switch�ṹ��
//2.ѭ������У�������ǰ��ѭ����䣬ִ�к������
//3.Ƕ��ѭ���У������������ѭ����䣬ִ�к������
void test1()
{
	//i���Ƶ�����
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)	//j���Ƶ�����
		{
			if (j == 5)
			{
				break;
			}
			printf("*");
		}
		printf("\n");
	}
}
//2.continue ��ֹ����ѭ������ִ����һ��ѭ��
void test2()
{
	//����ż��
	for (int i = 0; i < 100; i++)
	{
		if (i % 2 == 0)
		{
			continue;
			//break�� ��ͬ ִֻ��һ��ѭ��
		}
		printf("%d\r\n", i);
	}

}
//go to ������ʹ��
void test3()
{
	printf("hello1\n");
	printf("hello2\n");

	goto FLAG;

	printf("hello3\n");
	printf("hello4\n");
	printf("hello5\n");
FLAG:
	printf("hello6\n");
	printf("hello7\n");
}

int main()
{
	test1();
	test2();
	test3();
	system("pause");
	return EXIT_SUCCESS;
}
