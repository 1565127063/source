#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)	
#pragma warning(disable:6031)
#define _CRT_SECURE_NO_WARNINGS

// 3��ϵͳĬ���ļ�ָ��
//stdin   ��׼���� Ĭ��Ϊ��ǰ�ն� ���� scanf getchar
//stdout  ��׼��� Ĭ��Ϊ��ǰ�ն� ��Ļ printf puts
//stderr  ��׼���� Ĭ��Ϊ��ǰ�ն� ��Ļ perror

void test1()
{
	int a = 0;
	printf("��a��ֵ\n");

	//�رյ�ϵͳ����ָ��
	fclose(stdin);	//���ü���

	scanf("%d", &a);
	printf("a= %d\n", a);
}
void test2()
{
	printf("hello1\n");
	printf("hello2\n");
	printf("hello3\n");

	//�رյ�ϵͳ���
	fclose(stdout);	//������Ļ  vs���� ������ѯprintf��Ҫ�ر�

	printf("hello4\n");
	printf("hello5\n");
	printf("hello6\n");
}

void test3()
{
	FILE* fp = fopen("a.txt", "r");
	if (fp == NULL)
	{
		perror("������Ϣ");	//������Ϣ: No such file or directory(Ŀ¼)
		//printf("��ʧ��");
		//return;
	}
	fclose(stderr);	//�رմ������ָ��
	perror("������Ϣ");//��Ϊ�رղ���ʾ�ڶ��α���
}

int main()
{
	test3();

	system("pause");
	return EXIT_SUCCESS;
}