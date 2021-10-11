#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include<string.h>

//argc	命令行变量数量
//argv  命令行参数

int main(int argc, char* argv[])
{
	printf("命令行参数变量: %d\n", argc);
	//如果我的命令大于1条  每条命令都输出
	if (argc > 1)
	{
		int i = 0;
		for (i = 0; i < argc; i++)
		{
			printf("%s\n", argv[i]);
		}
	}
	system("pause");
	return EXIT_SUCCESS;
}