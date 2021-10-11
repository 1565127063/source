#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)	
#pragma warning(disable:6031)
#define _CRT_SECURE_NO_WARNINGS


//memset 内存设置 (用于清空内存)
void test1()
{
	char buf[32] = "hello world";
	printf("buf = %s\n", buf);

	memset(buf, 'a', 32);
	printf("buf = %s\n", buf);//全部变成a 

	//主要用途，清空内存
	memset(buf, 0, 32);
	printf("buf = %s\n", buf);
}


//打印字符串
void printArray(char* arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%c", arr[i]);
	}
	printf("###\n");
}

//memcpy 内存拷贝(数组赋值)
void test2()
{
	char dst[64] = { 0 };
	char src[64] = "hello\0 world";
	strcpy(dst, src);	//遇到\0结束拷贝
	printArray(dst, sizeof(dst));
	memset(dst, 0, sizeof(dst));	//清空字符串

	//memset(目标,源，长度)
	memcpy(dst, src,sizeof(dst));	//可以复制全部的字节
	printArray(dst, sizeof(dst));

	//用途：给数组进行赋值
	int arr[5] = { 1,2,3,4,5 };
	int arr2[5];
	memcpy(arr2, arr, sizeof(arr));
	for (int i = 0; i < 5; i++)
	{
		printf("arr[%d] = %d\n", i+1, arr2[i]);
	}
}

//memmove
void test3()
{
	//中间三个数从第三个数开始拷贝  第二个数不变
	int arr[5] = { 10,20,30,40,50 };

	//通过内存拷贝实现 没有内存重叠时可以用
	//memcpy(arr + 2, arr + 1, 3 * sizeof(int));	//存在风险 有可能和预期不符

	memmove(arr + 2, arr + 1, 3 * sizeof(int));		//效率低 安全

	for (int i = 0; i < 5; i++)
	{
		printf("%d\n", arr[i]);
	}
}

//memcmp 内存比较
void test4()
{
	static char buf1[32] = "hello\0wofrld";
	static char buf2[32] = "hello\0aaa";

	if (strcmp(buf1,buf2) == 0)	//常用
	{
		printf("strcmp: buf1 = buf2\n");
	}
	else
	{
		printf("strcmp: buf1 != buf2\n");
	}
	//一般来说  strcmp足够用
	if (memcmp(buf1, buf2, sizeof(buf1)) == 0)
	{
		printf("memcmp: buf1 = buf2\n");
	}
	else
	{
		printf("memcmp: buf1 != buf2\n");
	}
}

//malloc   在内存的动态存储区(堆区)中分配一块长度为size字节的连续区域
//申请的内存空间 ，生命周期：整个程序结束才被系统释放
//通常程序员手动释放， 调用函数 free()
void test5()
{
	int* p = NULL;
	p = malloc(sizeof(int));
	//malloc要判断申请的内存是否成功
	if (NULL == p)
	{
		printf("申请失败\n");
		return;
	}
	*p = 1000;	//如果不操作 内容是随机的 
	printf("*p = %d\n", *p);

	//清空内存
	memset(p, 0, 4);
	printf("*p = %d\n", *p);

	//释放内存
	free(p);

}
//设置元素
void setArr(int* arr,int len)
{
	printf("请给数组的元素个数赋值\n");
	for (int i = 0; i < len; i++)
	{
		scanf("%d", &arr[i]);
		//scanf("%d", arr+i); //等价于
	}
}
//打印元素
void prArr(int * arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//实现简易版本 动态数组
void test6()
{
	int num = 0;
	printf("请输入数组的元素个数\n");
	scanf("%d", &num);

	int* arr = malloc(sizeof(int) * num);	//堆区

	if (arr == NULL)
	{
		printf("申请失败\n");
		return;
	}
	//清空内存
	memset(arr, 0, sizeof(int) * num);

	//设置元素
	setArr(arr, num);

	//打印数组
	prArr(arr, num);

	//释放数组
	free(arr);
}

//1.不要返回局部变量的地址
int fun1()
{
	int num = 10;	//栈上分配的  {}后释放了
	return &num;
}
void test7()
{
	int* p = fun1();
	printf("*p = %d\n", *p);//
	printf("*p = %d\n", *p);	//第二次使用就会错误 内存空间不保存
	//总结：结果不重要，内存已经释放，这块内存属于非法操作
}

//2.可以返回静态变量的地址
int fun2()
{
	static int num = 10;	//静态变量会保存
	return &num;
}
void test8()
{
	int* p = fun2();
	printf("*p = %d\n", *p);
	printf("*p = %d\n", *p);
	//总结：结果不重要，内存已经释放，这块内存属于非法操作
}

///3.不要操作已经释放的堆区空间
test9()
{
	//指针在栈上，指向的内容在堆区
	int * p = malloc(sizeof(int));
	printf("p = %d\n", p);

	*p = 1000;

	free(p);
	printf("p = %d\n", p);

	//*p = 2000;	//error 已经释放掉无法操作
}

//4.不要释放野指针
test10()
{
	int* p = malloc(sizeof(int));

	//free(p);
	//free(p);	//此时p属于野指针，无法释放
	if (p != NULL)
	{
		free(p);
		p = NULL;
	}

	free(p);//空指针可以free
}

void allocatSpace(int* pp)
{
	//**p = 1000；
	//printf("%d\n", **p);
}
//同级指针修饰内存失败
test11()
{
	int* p = NULL;
	//allocatSpace(p);	
	//*p = 1000;	//值传递无法修改

	allocatSpace(p);
	//printf("%d\n", *p);
}

//解决上述问题 1.利用函数返回值
int * allocatSpace2()
{
	int* pp = malloc(sizeof(int));
	return pp;
}
void test12()
{
	int* p = NULL;
	p = allocatSpace2();
	*p = 1000;	
	printf("%d\n", *p);
}

//解决上述问题 2.利用高级指针
void allocatSpace3(int **pp)
{
	*pp = malloc(sizeof(int));
}
void freeSpcae(int* pp)
{
	if (pp != NULL)
	{
		free(pp);
		pp = NULL;
	}
}
void test13()
{
	int* p = NULL;
	allocatSpace3(&p);
	*p = 2000;
	printf("%d\n", *p);

	freeSpcae(p);
}

int main()
{
	//test1();
	//test2();
	test5();
	test6();
	test7();
	test8();
	system("pause");
	return EXIT_SUCCESS;
}