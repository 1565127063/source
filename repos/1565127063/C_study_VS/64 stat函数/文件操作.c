#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)	
#pragma warning(disable:6031)
#define _CRT_SECURE_NO_WARNINGS
#define FILENAME "Score.txt"

//ȫ�ֱ��� �ļ��Ƿ�Ϊ��
int fileISEmpty = 0; //1Ϊ�� 0Ϊ�ǿ�

#include <sys/types.h>
#include <sys/stat.h>
int stat(const char* path, struct stat* buf);
#include<time.h>
//stat ��ȡ�ļ�״̬��Ϣ ������ļ�
void test1()
{
	struct stat myStat;
	stat("test1.txt",&myStat);

	printf("�ļ��Ĵ�С��%d\n", myStat.st_size);

	//��ȡatime ����ʱ��
	char* time = ctime(&myStat.st_atime);
	char atime[1024] = { 0 };
#if 0
	//�����з�
	strcpy(atime, time);//��time���Ƶ�atime
	atime[strlen(atime) - 1] = '\0';
	printf("a_time��%s\n", atime);	//һϵ�в���ȥ���˻��з�
#else
	strncpy(atime, time, strlen(time)-1); //-1������\n
	printf("a_time��%s\n", atime);
#endif 

	//��ȡ mtime �޸�ʱ��
	char* time2 = ctime(&myStat.st_mtime);	//����ʱ��
	char mtime[1024] = { 0 };
	strncpy(mtime, time2, strlen(time2) - 1); //-1������\n
	printf("m_time��%s\n", mtime);
}
//�ļ���������ɾ��
void test2()
{
	//rename("������","������")
	rename("test1.txt","test2.txt");

	remove("111.txt");//ɾ���ļ�
}

//��ʾ����
void show_Menu()
{
	printf("*************************************************\n");
	printf("*************   ��ӭʹ��ϵͳ      ***************\n");
	printf("*************   1����¼�����÷�   ***************\n");
	printf("*************   2���鿴�����¼   ***************\n");
	printf("*************   3����ձ�����¼   ***************\n");
	printf("*************   4���˳���ǰ����   ***************\n");
	printf("\n");
}

//��¼�µķ���
void setScore()
{
	printf("����������÷�\n");
	double Score = 0;
	scanf("%lf", &Score);

	FILE * fp = fopen(FILENAME, "a");//w��д a����������
	if (fp == NULL)
	{
		printf("���ļ�ʧ��\n");
		return;
	}
	//��ʽ����ʽд��
	fprintf(fp, "%.3lf\n", Score);
	fclose(fp);

	fileISEmpty = 0;	//�ǿ�
	printf("������¼�ɹ�\n");
	system("pause");
	system("cls");
}

//��ʾ����
void show_Score()
{
	//����޼�¼�ͷ���
	if (fileISEmpty)
	{
		printf("��ǰ��¼Ϊ��\n");
		system("pause");
		system("cls");
		return;
	}
	FILE* fp = fopen(FILENAME, "r");
	if (fp == NULL)
	{
		printf("���ļ�ʧ��\n");
		return;
	}
	int index = 1;
	while (!feof(fp))	//û�ж�ȡ���ļ�βִ��ѭ�� 
	{
		double Score = 0;
		//��ֹ\n����
#if 0
		int ret = fscanf(fp, "%lf\n", &Score);//��ʽ1 
#else
		int ret = fscanf(fp, "%lf", &Score);
		if (ret == -1)
		{
			break;
		}
#endif	
		printf("%d��ķ�����: %.3lf\n", index++, Score);
	}
	fclose(fp);
	system("pause");
	system("cls");
}
//��ռ�¼
void clear_file()
{
	printf("�Ƿ�ȷ����գ� 1-ȷ�� ����-ȡ��\n");
	int ret = 0;
	scanf("%d",&ret);
	if (ret == 1) 
	{
		FILE* fp1 = fopen(FILENAME, "w");
		fclose(fp1);
		fileISEmpty = 1;
		printf("������\n");
		//remove(FILENAME);//ɾ���ļ�
	}
	system("pause");
	system("cls");
}

//Ϊ���ж�
void initFlag()
{
	FILE *fp = fopen(FILENAME, "r");
	if (fp == NULL)
	{
		printf("�ļ���ʧ��\n");
		return;
	}
	char ch = 0;
	ch = fgetc(fp);
	if (ch == EOF)
	{
		fileISEmpty = 1;	//Ϊ��
	}
	else fileISEmpty = 0;
}

//��¼�������� ��ӭ���˳�����
void test3()
{
	int select = 0;
	initFlag();
	while (1)
	{
		show_Menu();
		printf("������ѡ��Ĺ���\n");
		scanf("%d", &select);

		switch (select)
		{
		case 1:
			//��¼����
			setScore();
			break;
		case 2:
			show_Score();
			//�鿴��¼
			break;
		case 3:
			clear_file();
			//��ռ�¼
			break;
		case 4:
			//�˳�ϵͳ
			printf("��ӭ�´�ʹ��\n");
			system("pause");
			exit(0);
			break;
		default:
			system("cls");	//������������ˢ��
			break;
		}
	}
}

int main()
{
	test3();

	//system("pause");
	//return EXIT_SUCCESS;
}