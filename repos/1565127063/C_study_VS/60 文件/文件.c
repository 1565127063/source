#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)	
#pragma warning(disable:6031)
#define _CRT_SECURE_NO_WARNINGS


//打开文件
void test1()
{
	//写文件
	FILE* f_write = fopen("test1.txt", "w");//没有也会创建

	//如果写文件，磁盘已满了才会空
	//如果读文件，文件不存在返回空指针
	if (NULL == f_write)
	{
		printf("文件打开失败\n");
		return;
	}
	//写文件具体操作

	//关闭文件
	fclose(f_write);
}


//写文件 fputc
void test2()
{
	//打开文件
	FILE* f_write = fopen("test1.txt", "w");
	//FILE* f_write = fopen("test2.txt", "wb");
	if (NULL == f_write)
	{
		printf("文件打开失败\n");
		return;
	}
	//写文件
	char buf[32] = "hello Fileword\n";//

	int i = 0;
	while (buf[i] != '\0')
	{
		fputc(buf[i], f_write);
		i++;
	}
	//关闭文件
	fclose(f_write);
}

//读文件
void test3()
{
	FILE* f_read = fopen("test1.txt", "r");
	if (NULL == f_read)
	{
		printf("文件打开文件失败\n");
		return;
	}
	//文件尾的标志 EOF  end of file
	char ch = 0;
	//如果读取信息不是尾部就一直读取并放入ch中
	while ((ch = fgetc(f_read)) != EOF)
	{
		printf("%c", ch);
	}
}

//案例需求 ：输入的所有内容都会输入到文件中，直到输入：quit才结束
void test4()
{
	FILE* f_write = fopen("a.txt", "w");
	if (NULL == f_write)
	{
		printf("打开文件失败\n");
		return;
	}
	while (1)
	{
		char buf[128] = { 0 };
		fgets(buf, sizeof(buf), stdin);
		//如果输入正确就退出循环
		if ((strncmp(buf, ":quit", 5)) == 0)
		{
			break;
		}
		//buf -> hello world\n\0
		int i = 0;
		while (buf[i] != '\0')
		{
			fputc(buf[i++], f_write);//文件内字符放入buf
		}
		//关闭文件
		fclose(f_write);
	}
}

//按行来写文件
void test5()
{
	FILE* f_write = fopen("test5.txt", "w");
	if (NULL == f_write)
	{
		printf("文件打开失败\n");
		return;
	}
	char* buf1[] = { "无边落木萧萧下\n","不尽长江滚滚来\n" ,"万里悲秋常作客\n","百年多病独登台\n" };
	for (int i = 0; i < sizeof(buf1) / sizeof(char*); i++)
	{
		fputs(buf1[i], f_write);//注意没有""
	}
	//关闭文件
	fclose(f_write);
}

//读文件
void test6()
{
	FILE * f_read = fopen("test5.txt", "r");
	if (NULL == f_read)
	{
		printf("读文件失败\n");
		return;
	}
	//feof(FILE *) 判断是否读取到结束尾 返回0说明当前是文件尾 

//自定义条件编译
#if 0
	char buf2[1024] = { 0 };
	while (!feof(f_read))
	{
		char * ret = fgets(buf2,sizeof(buf2),f_read);
		if (ret == NULL)
		{
			break;
		}
		//1.将\n 改成 \0
		buf2[strlen(buf2) - 1] = '\0';
		printf("%s\n", buf2);
	}
#else
	//优化代码 直接判断 读到会返回真
	char buf2[1024] = { 0 };
	while (fgets(buf2,sizeof(buf2),f_read))
	{
		buf2[strlen(buf2) - 1] = '\0';
		printf("%s\n", buf2);
	}
#endif 

	//关闭文件
	fclose(f_read);
}


int main()
{
	test6();

	system("pause");
	return EXIT_SUCCESS;
}