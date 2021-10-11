#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS

//数组的定义
void test1()
{
	//定义语法1： 数据类型 数组名称[元素个数]
	int a[10];
	//数组赋值
	a[0] = 100;
	a[1] = 90;
	a[2] = 90;
	a[3] = 90;

	//定义语法2； 数据类型 数组名称[元素个数]={0,1,2};
	int b[10] = { 10,20,30,40,50,60,70,80,90 };//部分初始化 未定义0
	//int b[10]; //
	//int b[10] = {a[0]=10,a[4]=50,a[8]=90}; //初始化会被定义0
	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", b[i]);
	}

	//定义语法3； 数据类型 数组名称[]={0,1,2}
	//不允许的语法	int c[];
	int c[] = { 10,20,30,40,50 };

	//注意事项
	int d = 10;
	//int b[d] = {0}; //error 元素个数a必须是常量
}

//数组的用途
void test2()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	//1、sizeof(数组名)  可以统计整个数组占用内存空间大小
	printf("sizeof arr = %d\n", sizeof(arr));//40
	printf("sizeof arr[0] = %d\n", sizeof(arr[0]));//4
	printf("元素个数%d\n", sizeof(arr) / sizeof arr[0]);//10

	//2、利用数组名，获取数组的首地址
	//printf("首地址： %d\n", arr);
	//printf("数组中第一个元素的地址： %d\n", &arr[0]);//19920472
	//printf("数组中第一个元素的地址： %d\n", &arr[1]);//19920476
	//验证地址是连续空间 每次都不一样  但都肯定是连续的差4

	//3、数组名是一个常量，不可以修改的
	//arr =100；error 数组名是常量
}

//案例 五只小猪称体重
void test3()
{
	int arr[5] = { 200,300,250,500,400 };
	int max = 0;	//认定最大值的下标是0
	int len = sizeof(arr) / sizeof(int);
	for (int i = 0; i < len; i++)
	{
		if (arr[i] > arr[max])
		{
			max = i;
		}
	}
	printf("最重的猪是%d号，重量是%d\n",max+1,arr[max]); //输出arr[0];
}

//最轻的猪
void test4()
{
	int arr[5] = { 200,300,250,500,400 };
	int min = 0;	//认定最小值的下标是0
	int len = sizeof(arr) / sizeof(int);
	printf("请给五只猪赋值\n");
	for (int i = 0; i < len; i++)
	{
		scanf_s("%d",&arr[i]);
	}
	for (int i = 0; i < len; i++)
	{
		if (arr[i] < arr[min])
		{
			min = i;
		}
	}
	printf("最轻的猪是%d号，重量是%d\n", min+1, arr[min]);//0开始 显示1
}

//9*9乘法表
void test5()
{
	for (int i = 0; i <= 9; i++)
	{
		//printf("第 %d 行\n",i);
		for (int j = 1; j <= i; j++)
		{
			printf("%d*%d=%d ", j, i,i*j);
		}
		printf("\n");
	}
}

//元素逆置
void test6()
{
	//13542  逆置 24531
	long arr[] = { 1 , 3 , 5  ,4 , 2 };
	int start = 0;
	printf("逆置前\n");
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	int end = sizeof(arr) / sizeof(int) - 1;
	while (start < end)
	{
		int temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		start++;
		end--;
	}
		//便历函数
		printf("逆置后\n");
		for (int  i = 0; i < sizeof(arr) / sizeof(int); i++)
		{
			printf("%d ",arr[i]);
		}
		printf("\n");
}

//五只小猪称体重
void test03()
{
	int Pig_Buff[5] = { 10,50,66,85,5 };
	int Pig_max = 0;
	int length = sizeof(Pig_Buff) / sizeof(int);
	for (int i = 0; i < length; i++)
	{
		if (Pig_Buff[i] > Pig_Buff[Pig_max])
		{
			Pig_max = i;
		}
	}
	printf("%d\n", Pig_Buff[Pig_max]);
}

//99乘法表
void test04()
{
	int i = 0, j = 0;
	for (i = 0; i <= 9; i++)
	{
		for (j = 1; j <= i; j++)
		{
			printf(" %d * %d = %d ", i, j, i * j);
		}
		printf("\n");
	}

}
//元素逆置
void test06()
{
	//13542  逆置 24531
	int arr[] = { 1,3,5,4,2 };
	int start = 0;

	for (int i = 0; i < sizeof(arr)/sizeof(int); i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	int end = sizeof(arr) / sizeof(int) - 1; //最后一个数的下标
	int temp;
	while (start < end)
	{
		temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		start++; 
		end--;
	}
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int main()
{
	//test2();
	//test3();
	//test4();
	//test6();
	test06();
	system("pause");
	return EXIT_SUCCESS;
}