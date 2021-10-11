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
	//结构体指针保存
	struct Student* p = &s;

	printf("id = %d name = %s score = %.1f\n", p->id, p->name, p->score);
	printf("id = %d name = %s score = %.1f\n", s.id, s.name, s.score);
	//以下多此一举
	printf("id = %d name = %s score = %.1f\n", (*p).id, (*p).name, (*p).score);
	printf("id = %d name = %s score = %.1f\n", (&s)->id, (&s)->name, (&s)->score);
}

//指针输入结构体，赋初值
void test2()
{
	struct Student s;
	struct Student* p = &s;
	scanf("%d %s %lf", &p->id, p->name, &p->score);
	printf("id = %d name = %s score = %.2f\n", p->id, p->name, p->score);
}

//结构体创建在堆区
void test3()
{
	struct Student* p = malloc(sizeof(struct Student));
	if (p == NULL)
	{
		return;
	}
	scanf("%d %s %lf", &p->id, p->name, &p->score);
	printf("id = %d name = %s score = %.2f\n", p->id, p->name, p->score);
	//释放堆区数据
	if (p != NULL)
	{
		free(p);
		p = NULL;
	}
}

//4结构体数组创建在堆区
void test4()
{
	printf("请输入元素个数_");
	int n = 0;
	scanf("%d", &n);
	struct Student* arr = malloc(sizeof(struct Student) * n);

	//清空空间
	memset(arr, 0, sizeof(struct Student) * n);

	for (int i = 0; i < n; i++)
	{
		printf("请给%d个学生赋值\n", i + 1);
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

//值传递
void printStudent(struct Student s)
{
	printf("id = %d name = %s score = %.1f\n", s.id, s.name, s.score);
}

//地址传递  可以修改实参
void printStudent2(struct Student* s)
{
	printf("id = %d name = %s score = %.1f\n", s->id, s->name, s->score);
}

//结构体指针做函数的参数
void test5()
{
	struct Student s1 = { 1, "Tom", 99 };
	printStudent(s1);
	printStudent2(&s1);
}

//void setStudentArray(struct Student arr[2], int len)
//void setStudentArray(struct Student arr[], int len)
//以上两种都是可以的
void setStudentArray(struct Student* arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("请给第%d个同学赋值\n", i + 1);
		scanf("%d %s %lf", &arr[i].id, arr[i].name, &arr[i].score);
	}
}

//封装一个函数 给结构体数组赋值
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
