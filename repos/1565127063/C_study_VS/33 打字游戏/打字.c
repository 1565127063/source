#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS
#include <time.h>

//������Ϸ �������Ӣ����ĸ15����a-z�� ����'-' ��ȷ���

#define Game_Num 15

void test1()
{
	//1.�����������  ��β\0�����Ҫ+1
	char GameBuff[Game_Num + 1] = { 0 };

	//2. �����ĸ a-z  97~97+25
	srand((size_t)time(NULL)); //�������ֻ��Ҫ����һ�μ���

	for (int  i = 0; i < Game_Num; i++)
	{
		GameBuff[i] = rand() % 26 + 'a'; //rand() % (max - min + 1) + min;
	}
	printf("%s\n", GameBuff);

	//3. �û���ӡ
	int game_cnt = 0;	//ͳ����ȷ����
	int star_time = 0;
	int end_time = 0;
	for (int i = 0; i < Game_Num; i++)
	{
		if (i == 0)
		{
			star_time = time(NULL);
		}
		//char ch = getchar(); getchar����Ҫ�س�����ʾ
		char ch = _getch();
		if (ch == GameBuff[i])
		{
			printf("%c",ch);
			game_cnt++;
		}
		else
		{
			printf("%c", '-');
		}
	}
	printf("\n");
	end_time = time(NULL);
	printf("׼ȷ��Ϊ%.2f%%\n",(double)game_cnt / (double)Game_Num *100);
	printf("����ʱ��Ϊ %d s \n", end_time - star_time);
}


void test01()
{

	int End_Time=0, Start_Time=0, game_cnt=0;

	char GameBuff[Game_Num + 1] = { 0 };

	srand((size_t)time(NULL)); //�������ֻ��Ҫ����һ�μ���

	//�����ĸ a-z  97~97+25
	for (int i = 0; i < Game_Num + 1; i++)
	{
		GameBuff[i] = rand() % 26 + 'a';
	}
	printf("%s\n", GameBuff);

	for (int i = 0; i < Game_Num; i++)
	{
		if (i == 0)
		{
			Start_Time = time(NULL);
		}
		char User_ch = _getch();

		if (User_ch == GameBuff[i])
		{
			printf("%c", User_ch);
			game_cnt++;
		}
		else
		{
			printf("%c", '-');
		}
	}
	printf("\n");
	End_Time = time(NULL);
	printf("�����Ϸ���� %d s\n", End_Time - Start_Time);
	printf("׼ȷ�� %.2f%%\n", (double)game_cnt / (double)Game_Num*100 );
}

int main()
{
	test1();
	system("pause");
	return EXIT_SUCCESS;
}
