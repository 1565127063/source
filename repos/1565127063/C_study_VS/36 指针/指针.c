#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS

//指针的定义
void test1()
{
	//创建普通变量
	int a = 10;
	//创建指针变量 此时是野指针
	int* p; 
	//指针和普通变量建立关系 
	p = &a;		//p存入a的地址	指针的指向
	//指针操作内存
	*p = 20;	//*p修改a对应的地址 指针指向的值

	printf("%d\n",a);
	printf("%d\n",*p);
	//printf("%d\n",p);	//方便查看地址距离
	//printf("%d\n",&a);
	//printf("%p\n",p);	//打印地址  16进制

	//注意事项 * 和 & 同时出现 从右往左依次抵消
	//*p为什么是a? 依据p = &a;   * p = *&a;  * p = a;
}

//指针的空间大小 
//4个字节(32位) 8个字节(64位) 
void test2()
{
	//不管原来类型是什么，指针只需要4个字节（32位）存放地址编号就够
	printf("sizeof int * = %d\n", sizeof(int *));
	printf("sizeof char * = %d\n", sizeof(char *));
	printf("sizeof double * = %d\n", sizeof(double *));
	printf("sizeof long * = %d\n", sizeof(long *));
	printf("sizeof short * = %d\n", sizeof(short *));
	//调试器边上修改 debug x86
}


void test3()
{
	int a = 10;
	int* p;
	p = &a;
	printf("%d", a);
	printf("p=%d,&p=%d", p, &p);

}

int main()
{
	test1();
	test2();
	test3();
	system("pause");
	return EXIT_SUCCESS;
}
