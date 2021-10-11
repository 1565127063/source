#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS

//1.const 修饰的 *  *p只可读 p可读可写  
// "常量指针" 指向的值是常量*p
void test1()
{
	int a = 10;
	const int* p = &a;	//等价于 int const * p = &a;
	// *p = 20; 此时*p只读 指向的值不可以修改
	int b = 20;
	p = &b;	 //指针指向可以修改  
	printf("%d\n",*p);
	//p 可以指向其他 但是 *p 是不可以修改的
}
//速记   const常量  *指针  按照顺序读
//const int* p = &a;    常量指针  常量在前  指向的值*p固定
//int* const p = &a;	指针常量  指针在前	指向的方向p固定

//2.const 修饰的 p  p只可读 *p可读可写  
//指针常量  存的常量不能改
void test2()
{
	int a = 10;
	int* const p = &a;
	*p = 20;	//指向的值可以修改
	int b = 20; 
	// p = &b; //error 指针的指向不可以修改 

}

//3.const 同时修饰的 *和p
void test3()
{
	//指针指向和指向的值都不可以修改
	int a = 10;
	const int* const p = &a;
	//*p = 20;	  //error 指向的值*p不可以修改
	int b = 20;
	// p = &b;	  //error 指针的指向p不可以修改 
}

int main()
{
	test1();
	system("pause");
	return EXIT_SUCCESS;
}