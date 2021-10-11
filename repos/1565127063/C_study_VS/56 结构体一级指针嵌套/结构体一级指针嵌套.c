#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)	
#pragma warning(disable:6031)
#define _CRT_SECURE_NO_WARNINGS

struct Teacher
{
	char* name;	//姓名
	int age;	//年龄
};

//堆区创建老师数组
void test1()
{
	//三个老师的指针放在堆区 申请一片堆区空间
	struct Teacher** teaArray = malloc(sizeof(struct Teacher*) * 3);

	for (int i = 0; i < 3; i++)
	{
		//teaArray[i] -> struct Teacher * 
		teaArray[i] = malloc(sizeof(struct Teacher));//老师也存在堆区
		//老师的姓名存放在堆区
		teaArray[i]->name = malloc(sizeof(char) * 64);

		//格式化
		sprintf(teaArray[i]->name, "Teacher_%d", i + 1);
		teaArray[i]->age = 30 + i;
	}
	for (int i = 0; i < 3; i++)
	{
		printf("姓名: %s 年龄 %d\n", teaArray[i]->name, teaArray[i]->age);
	} 
	for (int i = 0; i < 3; i++)
	{
		if (teaArray[i]->name != NULL)
		{
			//printf("%s被释放了\n", teaArray[i]->name);
			free(teaArray[i]->name);
			teaArray[i]->name = NULL;
		}
		if (teaArray[i] != NULL)
		{
			free(teaArray[i]);
			teaArray[i] = NULL;
		}
	}
	//释放数组
	if (teaArray != NULL)
	{
		free(teaArray);
		teaArray = NULL;
	}
	//几个malloc 就有多少的 free()
}

int main()
{
	test1();

	system("pause");
	return EXIT_SUCCESS;
}