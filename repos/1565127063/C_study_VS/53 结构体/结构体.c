#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)	
#pragma warning(disable:6031)
#define _CRT_SECURE_NO_WARNINGS

//ѧ��������
//�﷨��struct + �������� + {};
//����ֻ��һ������ û��������ѧ������ �������ֻ��һ��ģ�� ��ռ���ڴ�ռ� 
struct MyStruct
{
	int id;			//ѧ��
	char name[64];	//����	
	double score;	//����
};

//���ʽṹ�����
void test1()
{
	//�����ṹ�����
	struct MyStruct s1 = { 1,"����",99.9 };

	//���ʽṹ���������Ϣ��ͨ�� '.'���ʳ�Ա˳��
	printf("ѧ�ţ� %d\n", s1.id);
	printf("������ %s\n", s1.name);
	printf("������ %.1f\n", s1.score);
}

struct MyStruct2
{
	int id;			//ѧ��
	char name[64];	//����	
	double score;	//����
}stu;	//stu�ǽṹ�����
//stu  = {1,"��ɽ"��79};   ����ֱ�Ӹ�ֵһ���ʼֵ

//��ƽṹ��ʱ��ͬʱ����һ���ṹ�����
void test2()
{
	stu.id = 2;
	//stu.name = "����" ��ʱstu���ǽṹ�� �ǽṹ�����
	strcpy(stu.name, "����");
	stu.score = 89;

	//���ʽṹ���������Ϣ��ͨ�� '.'���ʳ�Ա˳��
	printf("ѧ�ţ� %d\n", stu.id);
	printf("������ %s\n", stu.name);
	printf("������ %.1f\n", stu.score);
}

//�ṹ���Ա��ֵ
void test3()
{
	
	struct MyStruct s1;
	struct MyStruct s2 = { 1,"����",99.9 };

	//1.�����Ա��ֵ
	/*s1.id = s2.id;
	strcpy(s1.name, s2.name);
	s1.source = s2.source;*/

	//2.���帳ֵ   (��ͬ���������ͽṹ�����֮��)
	//s1 = s2;	

	//3.�ڴ濽������memcpy
	memcpy(&s1, &s2, sizeof(struct MyStruct));

	printf("ѧ�ţ� %d\n", s1.id);
	printf("������ %s\n", s1.name);
	printf("������ %.1f\n", s1.score);
}

//�ṹ������Ľ���
void test4()
{
	struct MyStruct s1 = { 2,"����", 88.1 };
	struct MyStruct s2 = { 1,"����",99.9 };

	struct MyStruct temp;
	temp = s1;
	s1 = s2;
	s2 = temp;

	printf("s1����Ϣ ѧ�ţ�%d ����%s ����%.2f\n", s1.id, s1.name, s1.score);
	printf("s2����Ϣ ѧ�ţ�%d ����%s ����%.2f\n", s2.id, s2.name, s2.score);

	/*
	//���ӷ��������м����
	int temp = s1.id;
	s1.id = s2.id;
	s2.id = temp;

	char nameTamp[64];
	strcpy(nameTamp, s1.name);
	strcpy(s1.name, s2.name);
	strcpy(s2.name, nameTamp);

	int scoretemp = s1.source;
	s1.source = s2.source;
	s2.source = scoretemp;

	printf("s1����Ϣ ѧ�ţ�%d ����%s ����%.2f\n",s1.id, s1.name, s1.source);
	printf("s2����Ϣ ѧ�ţ�%d ����%s ����%.2f\n", s2.id, s2.name, s2.source);
	*/
}

//�ṹ������
void test5()
{
	struct MyStruct arr[5] = {
		{1,"С��",100},
		{2,"С��",99},
		{3,"С��",98},
		{4,"С��",97},
		{5,"С��",96}	//���һ����Ա,��д�ɲ�д
	};

	for (int i = 0; i < sizeof(arr) / sizeof(struct MyStruct); i++)
	{
		printf("ѧ�ţ�%d ���� %s ���� %.2f\n", arr[i].id, arr[i].name, arr[i].score);
	}
}

//��ϰ���ã��ɼ���������ͬʱ��Ա��Ӧ

//�ṹ������Ӽ��̻�ȡ��Ϣ
void test6()
{
	struct MyStruct arr[5];
	memset(arr, 0, sizeof(arr));	//������� 

	int len = sizeof(arr) / sizeof(arr[0]);
	printf("���%d��ѧ����ֵ\n", len);
	for (int i = 0; i < len; i++)
	{
		scanf("%d %s %lf", &arr[i].id, arr[i].name, &arr[i].score);	//name ����Ҫ
	}
	for (int i = 0; i < len; i++)
	{
		printf("ѧ�ţ�%d ���� %s ���� %.2f\n", arr[i].id, arr[i].name, arr[i].score);
	}
}

struct Stu
{
	int id;
	int age;
};

struct Tea
{
	int id;
	struct Stu st;	 
};

void test7()
{
	struct Tea t1 = { 100 , {1,18} };
	struct Tea t2 = { 100 , 2,19 };

	printf("��ʦ��ְ���ţ�%d ������ѧ��ѧ�� %d ѧ������ %d\n", t1.id, t1.st.id, t1.st.age);
}

//�ṹ��Ƕ�׽ṹ��
int main()
{
	test7();
	system("pause");
	return EXIT_SUCCESS;
}
