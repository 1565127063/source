#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS

//arr[1] = *(arr+1)
//[]本本质是  *() 的简写
void test1()
{
	int arr[5] = { 1,2,3,4,5 };
	printf("sizeof(arr) = %d\n",sizeof(arr));
	//arr 指向数组首地址
	//printf("%d\n", arr);
	//printf("%d\n", arr+1);	//4bit
	printf("第一个元素 = %d\n",arr[0]);
	printf("第一个元素 = %d\n", *arr);
	//[]本本质是  *() 的简写
	printf("第二个元素 = %d\n", arr[1]);
	printf("第二个元素 = %d\n", *(arr+1));
	//交换仍然正常
	printf("第二个元素 = %d\n", *(1 + arr));
	//printf("第二个元素 = %d\n", 1[arr]);	//转换1*(arr) 不建议

	for (int i = 0; i < 5; i++)
	{
		//printf("%d ",arr[i]);
		printf("%d ", *(arr+i));
	}
	printf("\n");

	//arr 为什么可以是首元素的地址 
	//&arr[0] 到 &*(arr+0) 到 arr
	//但不可以绝对的 arr 就是arr[0]的首地址 sizeof(arr)就不符合
}

//通过指针操控数组
void test2()
{
	int arr[5] = { 1,2,3,4,5 };
	int* p = arr;
	for (int i = 0; i < 5; i++)
	{
		//printf("%d\n",p[i]);
		printf("%d\n", *(p+i));
	}
	//存在的区别
	printf("sizeof(arr) = %d\n", sizeof(arr));	//20
	printf("sizeof(p) = %d\n", sizeof(p));	//4
	
	//访问数组的时候 下标可以是负数
	//int* p2 = arr;//操作数组第一个元素
	int* p2 = &arr[2];
	printf("*p2 = %d\n",*p2);
	printf("*p2 = %d\n", p2[0]);
	printf("*p2 = %d\n", p2[1]);
	printf("*p2 = %d\n", p2[-1]);	//*(p2-1)
	//printf("*p2 = %d\n", p2[-10]); //越界
}
//综合分析
void test3()
{
	int arr[5] = { 1,2,3,4,5 };
	int* p = arr;

	printf("%d\n", *p++);	//1  先*p 输出1 再p++ p偏移一位 地址+4 变成2
	printf("%d\n", (*p)++);	//2  先*p 输出2 再*p++ p=3 覆盖第二位的2
	printf("%d\n", *(p++));	//3  先*p 输出3 p++指向偏移

	for (int i = 0; i < 5; i++)
	{
		//printf("%d\n",p[i]);
		printf("%d\n", arr[i]); //13345
	}

	int arr2[15] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
	printf("%d\n", arr2[*(arr2 + *(arr2 + arr2[3]))]);
	//arr2*(arr2 + arr2[3]) 小括号内 *(arr+4) 首位+4 到5的地址
	// arr2[*(arr2+5)] 
	//arr2[*6] 7
}

int main()
{
	test3();
	system("pause");
	return EXIT_SUCCESS;
}
