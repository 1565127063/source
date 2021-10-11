#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)	
#pragma warning(disable:6031)
#define _CRT_SECURE_NO_WARNINGS
#define FILENAME "Score.txt"

//全局变量 文件是否为空
int fileISEmpty = 0; //1为空 0为非空

#include <sys/types.h>
#include <sys/stat.h>
int stat(const char* path, struct stat* buf);
#include<time.h>
//stat 获取文件状态信息 无需打开文件
void test1()
{
	struct stat myStat;
	stat("test1.txt",&myStat);

	printf("文件的大小：%d\n", myStat.st_size);

	//获取atime 访问时间
	char* time = ctime(&myStat.st_atime);
	char atime[1024] = { 0 };
#if 0
	//处理换行符
	strcpy(atime, time);//把time复制到atime
	atime[strlen(atime) - 1] = '\0';
	printf("a_time：%s\n", atime);	//一系列操作去掉了换行符
#else
	strncpy(atime, time, strlen(time)-1); //-1舍弃掉\n
	printf("a_time：%s\n", atime);
#endif 

	//获取 mtime 修改时间
	char* time2 = ctime(&myStat.st_mtime);	//访问时间
	char mtime[1024] = { 0 };
	strncpy(mtime, time2, strlen(time2) - 1); //-1舍弃掉\n
	printf("m_time：%s\n", mtime);
}
//文件重命名、删除
void test2()
{
	//rename("旧名称","新名称")
	rename("test1.txt","test2.txt");

	remove("111.txt");//删除文件
}

//显示界面
void show_Menu()
{
	printf("*************************************************\n");
	printf("*************   欢迎使用系统      ***************\n");
	printf("*************   1、记录比赛得分   ***************\n");
	printf("*************   2、查看往届记录   ***************\n");
	printf("*************   3、清空比赛记录   ***************\n");
	printf("*************   4、退出当前程序   ***************\n");
	printf("\n");
}

//记录新的分数
void setScore()
{
	printf("请输入比赛得分\n");
	double Score = 0;
	scanf("%lf", &Score);

	FILE * fp = fopen(FILENAME, "a");//w是写 a是连续存入
	if (fp == NULL)
	{
		printf("打开文件失败\n");
		return;
	}
	//格式化方式写入
	fprintf(fp, "%.3lf\n", Score);
	fclose(fp);

	fileISEmpty = 0;	//非空
	printf("分数记录成功\n");
	system("pause");
	system("cls");
}

//显示分数
void show_Score()
{
	//如果无记录就返回
	if (fileISEmpty)
	{
		printf("当前记录为空\n");
		system("pause");
		system("cls");
		return;
	}
	FILE* fp = fopen(FILENAME, "r");
	if (fp == NULL)
	{
		printf("打开文件失败\n");
		return;
	}
	int index = 1;
	while (!feof(fp))	//没有读取到文件尾执行循环 
	{
		double Score = 0;
		//防止\n问题
#if 0
		int ret = fscanf(fp, "%lf\n", &Score);//方式1 
#else
		int ret = fscanf(fp, "%lf", &Score);
		if (ret == -1)
		{
			break;
		}
#endif	
		printf("%d届的分数是: %.3lf\n", index++, Score);
	}
	fclose(fp);
	system("pause");
	system("cls");
}
//清空记录
void clear_file()
{
	printf("是否确定清空？ 1-确定 其他-取消\n");
	int ret = 0;
	scanf("%d",&ret);
	if (ret == 1) 
	{
		FILE* fp1 = fopen(FILENAME, "w");
		fclose(fp1);
		fileISEmpty = 1;
		printf("清空完毕\n");
		//remove(FILENAME);//删除文件
	}
	system("pause");
	system("cls");
}

//为空判断
void initFlag()
{
	FILE *fp = fopen(FILENAME, "r");
	if (fp == NULL)
	{
		printf("文件打开失败\n");
		return;
	}
	char ch = 0;
	ch = fgetc(fp);
	if (ch == EOF)
	{
		fileISEmpty = 1;	//为空
	}
	else fileISEmpty = 0;
}

//记录比赛分数 欢迎与退出界面
void test3()
{
	int select = 0;
	initFlag();
	while (1)
	{
		show_Menu();
		printf("请输入选择的功能\n");
		scanf("%d", &select);

		switch (select)
		{
		case 1:
			//记录分数
			setScore();
			break;
		case 2:
			show_Score();
			//查看记录
			break;
		case 3:
			clear_file();
			//清空记录
			break;
		case 4:
			//退出系统
			printf("欢迎下次使用\n");
			system("pause");
			exit(0);
			break;
		default:
			system("cls");	//输入其他数字刷新
			break;
		}
	}
}

int main()
{
	test3();

	//system("pause");
	//return EXIT_SUCCESS;
}