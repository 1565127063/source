#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS
#include <time.h>

//打字游戏 随机产生英文字母15个（a-z） 错误'-' 正确输出

#define Game_Num 15

void test1()
{
	//1.存放在数组内  结尾\0因此需要+1
	char GameBuff[Game_Num + 1] = { 0 };

	//2. 随机字母 a-z  97~97+25
	srand((size_t)time(NULL)); //随机种子只需要设置一次即可

	for (int  i = 0; i < Game_Num; i++)
	{
		GameBuff[i] = rand() % 26 + 'a'; //rand() % (max - min + 1) + min;
	}
	printf("%s\n", GameBuff);

	//3. 用户打印
	int game_cnt = 0;	//统计正确个数
	int star_time = 0;
	int end_time = 0;
	for (int i = 0; i < Game_Num; i++)
	{
		if (i == 0)
		{
			star_time = time(NULL);
		}
		//char ch = getchar(); getchar必须要回车才显示
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
	printf("准确率为%.2f%%\n",(double)game_cnt / (double)Game_Num *100);
	printf("所用时间为 %d s \n", end_time - star_time);
}


void test01()
{

	int End_Time=0, Start_Time=0, game_cnt=0;

	char GameBuff[Game_Num + 1] = { 0 };

	srand((size_t)time(NULL)); //随机种子只需要设置一次即可

	//随机字母 a-z  97~97+25
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
	printf("完成游戏用了 %d s\n", End_Time - Start_Time);
	printf("准确率 %.2f%%\n", (double)game_cnt / (double)Game_Num*100 );
}

int main()
{
	test1();
	system("pause");
	return EXIT_SUCCESS;
}
