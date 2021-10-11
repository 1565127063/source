#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)	
#pragma warning(disable:6031)
#define _CRT_SECURE_NO_WARNINGS

void setChar(char* arr, int len)
{
	printf("给字符串赋值\n");
	fgets(arr, len, stdin);
}
//
void test1()
{
	char buf[30] = { 0 };
	//int len = sizeof(buf) / sizeof(char);
	// 1 定义函数给buf赋值
	setChar(buf, sizeof(buf));
	//上一步时就已经加入了\n hello wordl\0000
	//将\n改成\0
	buf[strlen(buf) - 1] = '\0';
	printf("buf = %s\n", buf);

	// 2.自己实现strlen 统计字符个数的函数
	int count = myStrlen(buf);
	printf("strlen = %d\n", strlen(buf));
	printf("%d\n", count);

	// 3. 大小写转换
	printf("转换前 = %s\n", buf);

	changeArr(buf, count);
	
	printf("转换后 = %s\n", buf);
}
//大小写转换
int changeArr(char* arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		if (arr[i] >= 'a' && arr[i]<'z')
		{
			//arr[i] = arr[i] - ('a' - 'A');
			arr[i] = arr[i] - 32;
		}
		else if (arr[i] >= 'A' && arr[i]<='Z')
		{
			//arr[i] = arr[i] + ('a' - 'A');
			arr[i] = arr[i] + 32;
		}
	}
}

int myStrlen(char* arr)
{
	int count = 0;
	while ( arr[count] != '\0')
	{
		count++;
	}
	return count;
	/*while (arr[count++] != '\0')
	{
		//条件不满足也会多一个计算
	}
	return count-1;*/
}

int g_a = 1000;	//全局变量

//写一个函数，可以返回g_a的地址
int* getAddress()
{
	//return &g_a; 等价于下面
	int* p = &g_a;
	return p;
}

//
void test3()
{
	int* p = getAddress();
	printf("g_a = %d\n", g_a);
	printf("*p = %d\n", *p);
	*p = 2000;
	printf("g_a = %d\n", g_a);
	printf("*p = %d\n", *p);
}

int main()
{
	test1();

	system("pause");
	return EXIT_SUCCESS;
}