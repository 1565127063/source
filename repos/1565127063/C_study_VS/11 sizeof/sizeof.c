#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS

//sizeof 统计变量\数据类型 占内存空间的大小
void test1() {
	int a = 10;
	/*printf("a类型的大小：%d\n", sizeof(a));*/
	printf("int类型的大小：%d\n",sizeof(int));
	printf("short类型的大小：%d\n", sizeof(short));
	printf("short类型的大小：%d\n", sizeof(short));
	printf("long类型的大小：%d\n", sizeof(long));
	printf("long long类型的大小：%d\n", sizeof(long long));
}


int main() {

	test1();

	system("pause");
	return EXIT_SUCCESS;
}