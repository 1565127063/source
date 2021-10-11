#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#define _CRT_SECURE_NO_WARNINGS

struct Student
{
	int id;
	char name[64];
	double score;
};

//
void test1()
{
	struct Student s = { 1, "Tom", 65.5 };
	//�ṹ��ָ�뱣��
	struct Student* p = &s;

	printf("id = %d name = %s score = %.1f\n", p->id, p->name, p->score);
	printf("id = %d name = %s score = %.1f\n", s.id, s.name, s.score);
	//���¶��һ��
	printf("id = %d name = %s score = %.1f\n", (*p).id, (*p).name, (*p).score);
	printf("id = %d name = %s score = %.1f\n", (&s)->id, (&s)->name, (&s)->score);
}

//ָ������ṹ�壬����ֵ
void test2()
{
	struct Student s;
	struct Student* p = &s;
	scanf("%d %s %lf", &p->id, p->name, &p->score);
	printf("id = %d name = %s score = %.2f\n", p->id, p->name, p->score);
}

//�ṹ�崴���ڶ���
void test3()
{
	struct Student* p = malloc(sizeof(struct Student));
	if (p == NULL)
	{
		return;
	}
	scanf("%d %s %lf", &p->id, p->name, &p->score);
	printf("id = %d name = %s score = %.2f\n", p->id, p->name, p->score);
	//�ͷŶ�������
	if (p != NULL)
	{
		free(p);
		p = NULL;
	}
}

//4�ṹ�����鴴���ڶ���
void test4()
{
	printf("������Ԫ�ظ���_");
	int n = 0;
	scanf("%d", &n);
	struct Student* arr = malloc(sizeof(struct Student) * n);

	//��տռ�
	memset(arr, 0, sizeof(struct Student) * n);

	for (int i = 0; i < n; i++)
	{
		printf("���%d��ѧ����ֵ\n", i + 1);
		scanf("%d %s %lf", &arr[i].id, &arr[i].name, &arr[i].score);
	}
	for (int i = 0; i < n; i++)
	{
		printf("id = %d name = %s score = %.2f\n", arr[i].id, arr[i].name, arr[i].score);
	}
	if (arr != NULL)
	{
		free(arr);
		arr = NULL;
	}
}

//ֵ����
void printStudent(struct Student s)
{
	printf("id = %d name = %s score = %.1f\n", s.id, s.name, s.score);
}

//��ַ����  �����޸�ʵ��
void printStudent2(struct Student* s)
{
	printf("id = %d name = %s score = %.1f\n", s->id, s->name, s->score);
}

//�ṹ��ָ���������Ĳ���
void test5()
{
	struct Student s1 = { 1, "Tom", 99 };
	printStudent(s1);
	printStudent2(&s1);
}

//void setStudentArray(struct Student arr[2], int len)
//void setStudentArray(struct Student arr[], int len)
//�������ֶ��ǿ��Ե�
void setStudentArray(struct Student* arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("�����%d��ͬѧ��ֵ\n", i + 1);
		scanf("%d %s %lf", &arr[i].id, arr[i].name, &arr[i].score);
	}
}

//��װһ������ ���ṹ�����鸳ֵ
void test6()
{
	struct Student arr[2];
	//memset(arr, 0, sizeof(struct Student) * 2);
	memset(arr, 0, sizeof(arr));

	int len = sizeof(arr) / sizeof(arr[0]);
	setStudentArray(arr, len);

	for (int i = 0; i < len; i++)
	{
		printf("id = %d name = %s score = %.1f\n", arr[i].id, arr[i].name, arr[i].score);
	}
}

int main()
{
	test6();

	system("pause");
	return EXIT_SUCCESS;
}
