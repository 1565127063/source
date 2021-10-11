#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {

	printf("hello\n");
	printf("abc\rdef");	//r 输出光标到行首 abc被覆盖
	printf("\\\\\n");		//两个\\才能输出一个
	printf("abc\tdef");	//水平制表  多一个tab键
	printf("\a");	//警告声
	printf("%%");	//两个才能输出一个
	printf("asdflkj\r111");	// \r 回车

	system("pause");
	return EXIT_SUCCESS;
}
