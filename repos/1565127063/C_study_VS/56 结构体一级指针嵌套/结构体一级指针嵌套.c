#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)	
#pragma warning(disable:6031)
#define _CRT_SECURE_NO_WARNINGS

struct Teacher
{
	char* name;	//����
	int age;	//����
};

//����������ʦ����
void test1()
{
	//������ʦ��ָ����ڶ��� ����һƬ�����ռ�
	struct Teacher** teaArray = malloc(sizeof(struct Teacher*) * 3);

	for (int i = 0; i < 3; i++)
	{
		//teaArray[i] -> struct Teacher * 
		teaArray[i] = malloc(sizeof(struct Teacher));//��ʦҲ���ڶ���
		//��ʦ����������ڶ���
		teaArray[i]->name = malloc(sizeof(char) * 64);

		//��ʽ��
		sprintf(teaArray[i]->name, "Teacher_%d", i + 1);
		teaArray[i]->age = 30 + i;
	}
	for (int i = 0; i < 3; i++)
	{
		printf("����: %s ���� %d\n", teaArray[i]->name, teaArray[i]->age);
	} 
	for (int i = 0; i < 3; i++)
	{
		if (teaArray[i]->name != NULL)
		{
			//printf("%s���ͷ���\n", teaArray[i]->name);
			free(teaArray[i]->name);
			teaArray[i]->name = NULL;
		}
		if (teaArray[i] != NULL)
		{
			free(teaArray[i]);
			teaArray[i] = NULL;
		}
	}
	//�ͷ�����
	if (teaArray != NULL)
	{
		free(teaArray);
		teaArray = NULL;
	}
	//����malloc ���ж��ٵ� free()
}

int main()
{
	test1();

	system("pause");
	return EXIT_SUCCESS;
}