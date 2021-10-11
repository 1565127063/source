#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)	
#pragma warning(disable:6031)
#define _CRT_SECURE_NO_WARNINGS


//���ļ�
void test1()
{
	//д�ļ�
	FILE* f_write = fopen("test1.txt", "w");//û��Ҳ�ᴴ��

	//���д�ļ������������˲Ż��
	//������ļ����ļ������ڷ��ؿ�ָ��
	if (NULL == f_write)
	{
		printf("�ļ���ʧ��\n");
		return;
	}
	//д�ļ��������

	//�ر��ļ�
	fclose(f_write);
}


//д�ļ� fputc
void test2()
{
	//���ļ�
	FILE* f_write = fopen("test1.txt", "w");
	//FILE* f_write = fopen("test2.txt", "wb");
	if (NULL == f_write)
	{
		printf("�ļ���ʧ��\n");
		return;
	}
	//д�ļ�
	char buf[32] = "hello Fileword\n";//

	int i = 0;
	while (buf[i] != '\0')
	{
		fputc(buf[i], f_write);
		i++;
	}
	//�ر��ļ�
	fclose(f_write);
}

//���ļ�
void test3()
{
	FILE* f_read = fopen("test1.txt", "r");
	if (NULL == f_read)
	{
		printf("�ļ����ļ�ʧ��\n");
		return;
	}
	//�ļ�β�ı�־ EOF  end of file
	char ch = 0;
	//�����ȡ��Ϣ����β����һֱ��ȡ������ch��
	while ((ch = fgetc(f_read)) != EOF)
	{
		printf("%c", ch);
	}
}

//�������� ��������������ݶ������뵽�ļ��У�ֱ�����룺quit�Ž���
void test4()
{
	FILE* f_write = fopen("a.txt", "w");
	if (NULL == f_write)
	{
		printf("���ļ�ʧ��\n");
		return;
	}
	while (1)
	{
		char buf[128] = { 0 };
		fgets(buf, sizeof(buf), stdin);
		//���������ȷ���˳�ѭ��
		if ((strncmp(buf, ":quit", 5)) == 0)
		{
			break;
		}
		//buf -> hello world\n\0
		int i = 0;
		while (buf[i] != '\0')
		{
			fputc(buf[i++], f_write);//�ļ����ַ�����buf
		}
		//�ر��ļ�
		fclose(f_write);
	}
}

//������д�ļ�
void test5()
{
	FILE* f_write = fopen("test5.txt", "w");
	if (NULL == f_write)
	{
		printf("�ļ���ʧ��\n");
		return;
	}
	char* buf1[] = { "�ޱ���ľ������\n","��������������\n" ,"���ﱯ�ﳣ����\n","����ಡ����̨\n" };
	for (int i = 0; i < sizeof(buf1) / sizeof(char*); i++)
	{
		fputs(buf1[i], f_write);//ע��û��""
	}
	//�ر��ļ�
	fclose(f_write);
}

//���ļ�
void test6()
{
	FILE * f_read = fopen("test5.txt", "r");
	if (NULL == f_read)
	{
		printf("���ļ�ʧ��\n");
		return;
	}
	//feof(FILE *) �ж��Ƿ��ȡ������β ����0˵����ǰ���ļ�β 

//�Զ�����������
#if 0
	char buf2[1024] = { 0 };
	while (!feof(f_read))
	{
		char * ret = fgets(buf2,sizeof(buf2),f_read);
		if (ret == NULL)
		{
			break;
		}
		//1.��\n �ĳ� \0
		buf2[strlen(buf2) - 1] = '\0';
		printf("%s\n", buf2);
	}
#else
	//�Ż����� ֱ���ж� �����᷵����
	char buf2[1024] = { 0 };
	while (fgets(buf2,sizeof(buf2),f_read))
	{
		buf2[strlen(buf2) - 1] = '\0';
		printf("%s\n", buf2);
	}
#endif 

	//�ر��ļ�
	fclose(f_read);
}


int main()
{
	test6();

	system("pause");
	return EXIT_SUCCESS;
}