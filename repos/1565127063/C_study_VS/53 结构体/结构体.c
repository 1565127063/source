#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)	
#pragma warning(disable:6031)
#define _CRT_SECURE_NO_WARNINGS

//学生的类型
//语法：struct + 类型名称 + {};
//下面只是一个类型 没有真正的学生存在 这个类型只是一个模具 不占据内存空间 
struct MyStruct
{
	int id;			//学号
	char name[64];	//名字	
	double score;	//分数
};

//访问结构体变量
void test1()
{
	//创建结构体变量
	struct MyStruct s1 = { 1,"张三",99.9 };

	//访问结构体变量的信息，通过 '.'访问成员顺序
	printf("学号： %d\n", s1.id);
	printf("姓名： %s\n", s1.name);
	printf("分数： %.1f\n", s1.score);
}

struct MyStruct2
{
	int id;			//学号
	char name[64];	//名字	
	double score;	//分数
}stu;	//stu是结构体变量
//stu  = {1,"张山"，79};   可以直接赋值一遍初始值

//设计结构体时，同时创建一个结构体变量
void test2()
{
	stu.id = 2;
	//stu.name = "李四" 此时stu不是结构体 是结构体变量
	strcpy(stu.name, "李四");
	stu.score = 89;

	//访问结构体变量的信息，通过 '.'访问成员顺序
	printf("学号： %d\n", stu.id);
	printf("姓名： %s\n", stu.name);
	printf("分数： %.1f\n", stu.score);
}

//结构体成员赋值
void test3()
{
	
	struct MyStruct s1;
	struct MyStruct s2 = { 1,"张三",99.9 };

	//1.逐个成员赋值
	/*s1.id = s2.id;
	strcpy(s1.name, s2.name);
	s1.source = s2.source;*/

	//2.整体赋值   (相同的数据类型结构体变量之间)
	//s1 = s2;	

	//3.内存拷贝函数memcpy
	memcpy(&s1, &s2, sizeof(struct MyStruct));

	printf("学号： %d\n", s1.id);
	printf("姓名： %s\n", s1.name);
	printf("分数： %.1f\n", s1.score);
}

//结构体变量的交换
void test4()
{
	struct MyStruct s1 = { 2,"王五", 88.1 };
	struct MyStruct s2 = { 1,"张三",99.9 };

	struct MyStruct temp;
	temp = s1;
	s1 = s2;
	s2 = temp;

	printf("s1的信息 学号：%d 姓名%s 分数%.2f\n", s1.id, s1.name, s1.score);
	printf("s2的信息 学号：%d 姓名%s 分数%.2f\n", s2.id, s2.name, s2.score);

	/*
	//复杂方法创建中间变量
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

	printf("s1的信息 学号：%d 姓名%s 分数%.2f\n",s1.id, s1.name, s1.source);
	printf("s2的信息 学号：%d 姓名%s 分数%.2f\n", s2.id, s2.name, s2.source);
	*/
}

//结构体数组
void test5()
{
	struct MyStruct arr[5] = {
		{1,"小红",100},
		{2,"小黄",99},
		{3,"小蓝",98},
		{4,"小绿",97},
		{5,"小白",96}	//最后一个成员,可写可不写
	};

	for (int i = 0; i < sizeof(arr) / sizeof(struct MyStruct); i++)
	{
		printf("学号：%d 姓名 %s 分数 %.2f\n", arr[i].id, arr[i].name, arr[i].score);
	}
}

//练习布置：成绩升序排序，同时人员对应

//结构体数组从键盘获取信息
void test6()
{
	struct MyStruct arr[5];
	memset(arr, 0, sizeof(arr));	//清空命令 

	int len = sizeof(arr) / sizeof(arr[0]);
	printf("请给%d个学生赋值\n", len);
	for (int i = 0; i < len; i++)
	{
		scanf("%d %s %lf", &arr[i].id, arr[i].name, &arr[i].score);	//name 不需要
	}
	for (int i = 0; i < len; i++)
	{
		printf("学号：%d 姓名 %s 分数 %.2f\n", arr[i].id, arr[i].name, arr[i].score);
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

	printf("老师的职工号：%d 所带的学生学号 %d 学生年龄 %d\n", t1.id, t1.st.id, t1.st.age);
}

//结构体嵌套结构体
int main()
{
	test7();
	system("pause");
	return EXIT_SUCCESS;
}
