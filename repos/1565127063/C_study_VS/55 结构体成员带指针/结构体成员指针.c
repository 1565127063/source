#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)	
#pragma warning(disable:6031)
#define _CRT_SECURE_NO_WARNINGS

struct Student
{
	int id;	//ѧ��
	char* name;	//����
	int age;	//����
};

void test1()
{
	struct Student s = { 1,"Tom",18 };
	printf("id = %d name = %s age = %d\n", s.id, s.name, s.age);

	//s.name[0] = 'X'; //error char* name[64]���Ը�
}

//��Ҫ�޸ķŵ�����
void test2()
{
	struct Student s = { 1,NULL,18 };
	//���������������ڴ�
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

//�ṹ��ͳ�Ա���ڶ��� 
void test3()
{
	struct Student* p = NULL;
	p = malloc(sizeof(struct Student));

	if (p == NULL)
	{
		return;
	}
	memset(p, 0, sizeof(struct Student));

	//�ṹ���Ա��ֵ
	p->id = 1;
	p->age = 18;
	//��Ҫ����ռ����ܷ�nameָ��
	p->name = malloc(sizeof(char) * 64);
	strcpy(p->name, "Tom");

	printf("id = %d name = %s age = %d\n", p->id, p->name, p->age);

	//�ͷ���Ҫ�Ⱥ�˳�� �ȳ�Ա�������ͷ�
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

//const���νṹ��ָ��
void test4()
{
	struct Student s1 = { 100,"Tom",18 };
	const struct Student* p1 = &s1;	// const����  *ָ��  ����˳���
	//����ָ�� ������ǰ  ָ��ָ���ֵ*p���ܸ�
	//p1->age = 20;	//error
	p1 = &s1;

	struct Student s2 = { 90,"Jerry",22 };
	struct Student* const p2 = &s2;	//ָ�볣�� ָ��һ��
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
