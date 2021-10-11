#include "test.h"
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)	
#pragma warning(disable:6031)
#define _CRT_SECURE_NO_WARNINGS
#include <time.h>

#define quslen 50

//����
void setQuestion(void)
{
	//���������
	srand((size_t)time(NULL));

	//������������� �����
	int num1 = 0, num2 = 0;
	char ch = 0;
	char oper[] = { '+','-','*','/' };

	FILE* f_write = fopen("test.txt", "w");
	if (f_write == NULL)
	{
		printf("���ļ�ʧ��\n");
		return;
	}
	for (int i = 0; i < quslen; i++)
	{
		//��������� 1~100
		num1 = rand() % 100 + 1;
		num2 = rand() % 100 + 1;
		ch = oper[rand() % 4]; //����0~3����������������� 

		//ƴ���ַ���
		char msg[64] = { 0 };
		sprintf(msg, "%d %c %d = \n", num1, ch, num2);

		//д�ļ�
		//printf("%s", msg); //��ӡ����
		fputs(msg, f_write);
	}
	//�ر��ļ�
	fclose(f_write);
	printf("50����Ŀ�������\n");
}


//����
void answerQuestion(void)
{
	FILE* fp1 = fopen("test.txt", "r");
	FILE* fp2 = fopen("answer.txt", "w");
	if (!fp1 || !fp2)
	{
		printf("�ļ���ʧ��\n");
		return;
	}
	char buf[64] = { 0 };
	//��ȡ�ļ�����β
	while (fgets(buf, sizeof(buf), fp1))
	{
		//printf("%s", buf);
		int num1 = 0, num2 = 0;
		char ch = '0';
		//�ַ������
		sscanf(buf, "%d %c %d  ", &num1, &ch, &num2);
		//printf(" %d %c  %d =  \n", num1, ch, num2);

		float ret = 0;
		switch (ch)
		{
		case '+':
			ret = num1 + num2;
			break;
		case '-':
			ret = num1 - num2;
			break;
		case '*':
			ret = num1 * num2;
			break;
		case '/':
			ret = num1 / num2;
			break;
		}
		//��װ�µ��ַ���
		char str[64] = { 0 };
		sprintf(str, "%d %c %d = %.1f\n", num1, ch, num2, ret);
		//printf("ret = %s\n", str);
		//����д�ļ�
		fputs(str, fp2);

	}
	fclose(fp1);
	fclose(fp2);
	printf("��Ŀ������\n");
}
