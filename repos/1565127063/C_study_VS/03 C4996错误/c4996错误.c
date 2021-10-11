#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	//主要输出库文件
#include<stdlib.h>	//system头文件

#pragma warning(disable:4996)	//必须的
#pragma warning(disable:6031)	//去警告

int main()
{
	//vs中不建议使用传统c语言库函数，scanf、sprintf
	//解决方法1  #define _CRT_SECURE_NO_WARNINGS
	//解决方法2  #pragme warning(disable:4996)
	//解决方法3  项目属性 c/c++ 预处理器编辑添加  _CRT_SECURE_NO_WARNINGS
	//解决方法4  scnaf   scanf_s
	char buf[1024] = { 0 };
	sprintf(buf, "%s", "hello word\n");
	printf("%s", buf);

	system("pause");
	return 0;
}
