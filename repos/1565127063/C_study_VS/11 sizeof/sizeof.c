#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS

//sizeof ͳ�Ʊ���\�������� ռ�ڴ�ռ�Ĵ�С
void test1() {
	int a = 10;
	/*printf("a���͵Ĵ�С��%d\n", sizeof(a));*/
	printf("int���͵Ĵ�С��%d\n",sizeof(int));
	printf("short���͵Ĵ�С��%d\n", sizeof(short));
	printf("short���͵Ĵ�С��%d\n", sizeof(short));
	printf("long���͵Ĵ�С��%d\n", sizeof(long));
	printf("long long���͵Ĵ�С��%d\n", sizeof(long long));
}


int main() {

	test1();

	system("pause");
	return EXIT_SUCCESS;
}