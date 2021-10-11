#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)	
#pragma warning(disable:6031)
#define _CRT_SECURE_NO_WARNINGS

struct Student
{
	int id;	//学号
	char* name;	//姓名
	int age;	//年龄
};

void test1()
{
	struct Student s = { 1,"Tom",18 };
	printf("id = %d name = %s age = %d\n", s.id, s.name, s.age);

	//s.name[0] = 'X'; //error char* name[64]可以改
}

//需要修改放到堆区
void test2()
{
	struct Student s = { 1,NULL,18 };
	//给姓名单独分配内存
	s.name[0] = malloc(sizeof(char) * 64);
	strcpy(s.name, "Tom");

	printf("id = %d name = %s age = %d\n", s.id, s.name, s.age);

	strcpy(s.name, "Jerry");

	printf("id = %d name = %s age = %d\n", s.id, s.name, s.age);

	if (s.name != NULL)
	{
		free(s.name);
		s.name = NULL;
	}
}

//结构体和成员都在堆区 
void test3()
{
	struct Student* p = NULL;
	p = malloc(sizeof(struct Student));

	if (p == NULL)
	{
		return;
	}
	memset(p, 0, sizeof(struct Student));

	//结构体成员赋值
	p->id = 1;
	p->age = 18;
	//需要申请空间后才能放name指针
	p->name = malloc(sizeof(char) * 64);
	strcpy(p->name, "Tom");

	printf("id = %d name = %s age = %d\n", p->id, p->name, p->age);

	//释放需要先后顺序 先成员再整个释放
	if (p->name != NULL)
	{
		free(p->name);
		p->name = NULL;
	}
	if (p != NULL)
	{
		free(p);
		p = NULL;
	}
}

//const修饰结构体指针
void test4()
{
	struct Student s1 = { 100,"Tom",18 };
	const struct Student* p1 = &s1;	// const常量  *指针  按照顺序读
	//常量指针 常量在前  指针指向的值*p不能改
	//p1->age = 20;	//error
	p1 = &s1;

	struct Student s2 = { 90,"Jerry",22 };
	struct Student* const p2 = &s2;	//指针常量 指向一定
	p2->id = 20;
	//p2 = &s2;	//error

	const struct Student* const p3 = &s2;
	//p3->age = 20;	//error
	//p3 = &s2;	//error
}

//

int main()
{
	test4();

	system("pause");
	return EXIT_SUCCESS;
}
