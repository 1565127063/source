#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS

//二级指针
//	*p = a  *pp = p 
//	**pp = *p = a 
void test1()
{
	int a = 10;
	int* p = &a;
	int** pp = &p;

	printf("a = %d\n", a);			//a的值
	printf("*p = %d\n", *p);		//地址p指向的值 a的值
	printf("**pp = %d\n", **pp);	//**pp的值 即*p  a的值

	printf("&a = %d\n", &a);		//a的地址
	printf("p = %d\n", p);			//p的值 就是a的地址
	printf("*pp = %d\n", *pp);		//*pp等价与p  a的地址

	printf("pp = %d\n", pp);		//pp的地址
}

int main()
{

	test1();

	system("pause");
	return EXIT_SUCCESS;
}