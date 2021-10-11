#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS

//定义方式1 类型说明符 数组名[常量表达式 1][常量表达式 2]
void test1()
{
	int arr[2][3];
	arr[0][0] = 0;
	arr[0][1] = 1;
	arr[0][2] = 2;
	arr[1][0] = 3;
	arr[1][1] = 4;
	arr[1][2] = 5;
	for (int  i = 0; i < 2; i++)
	{
		for (int  j = 0; j < 3; j++)
		{
			printf("%d ",arr[i][j]);
		}
		printf("\n");	//换行位置很关键 换行i
	}
}

//方式2 推荐使用2
void test2()
{
	int arr2[2][3] =
	{
	{1, 2, 3},
	{2, 3, 4}	//最后一行 ，可以省略
	};

	//定义方式3
	int arr3[2][3] = { 1, 2, 3, 4, 5 ,6 };

	//定义方式4
	int arr4[][3] = { 1, 2, 3, 4, 5 ,6, 7 };//只能省略行数 列数不可以省略

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d ", arr4[i][j]);	// 自动补齐7 0 0
		}
		printf("\n");
	}
}

//可查看信息
void test3()
{
	int arr2[2][3] =
	{
	{1, 2, 3},
	{2, 3, 4}	//最后一行 ，可以省略
	};
	//sizeof(arr) 统计整个数组的字符大小
	printf("%d\n",sizeof(arr2));	//24 
	printf("%d\n", sizeof(arr2[0]));	//二维数组一行的字符大小
	printf("%d\n", sizeof(arr2[0][0]));	//二维数组第一个的字符大小

	//统计二维数组的 行数 列数
	printf("二维数组的行数 = %d\n", sizeof(arr2) / sizeof(arr2[0])); //行数
	printf("二维数组的列数 = %d\n", sizeof(arr2[0]) / sizeof(arr2[0][0])); //列数

	//打印首地址
	printf("二维数组的首地址%d\n",&arr2);			//18086416
	printf("二维数组的第一行首地址%d\n", &arr2[0]); //18086416
	printf("二维数组的第一行首地址%d\n", &arr2[1]); //18086428
	printf("二维数组的第一个元素首地址%d\n", &arr2[0][0]); //18086416
	printf("二维数组的第一个元素首地址%d\n", &arr2[0][1]); //18086420
	//二维数组本质也是一维数组
}

//分数管理
void test4()
{
	int source[3][3] =
	{
		{100,70,100},
		{90,80,94},
		{94,86,93}
	};

	char name[3][10] = { "张三", "李四", "王五"};

	//打印每个人的总成绩
	int row = sizeof(source) / sizeof(source[0]);
	int col = sizeof(source[0]) / sizeof(source[0][0]);
	for (int  i = 0; i < row; i++)
	{
		int sum = 0;
		for (int  j = 0; j < col; j++)
		{
			sum += source[i][j];
			//printf("%d\n",sum);
		}
		//printf("第%d个同学总分为%d 平均分为%d\n",i+1,sum,sum / col);
		printf("%s同学总分为%d 平均分为%d\n", name[i], sum, sum / col);
	}
}

int main()
{

	test4();

	system("pause");
	return EXIT_SUCCESS;
}