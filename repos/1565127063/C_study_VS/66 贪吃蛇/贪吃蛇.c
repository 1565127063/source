#pragma once //防止头文件  重复包含
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS

#include<windows.h>
#include "snake.h"
#include "food.h"
#include <time.h>
#include <conio.h>	//_getch 头文件 控制台输入输出操作

int sleepTime = 200;//刷新时间
int score = 0;

//光标定位
void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	//设置控制台光标位置
	//所有的资源都可以叫句柄GetStdHandle
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
//更新显示
void update()
{
	for (int i = 0; i < snake.size; i++)
	{
		gotoxy(snake.body[i].x, snake.body[i].y);
		if (i == 0)
		{
			//蛇头
			printf("@");
		}
		else printf("#");//蛇身
	}
	//显示食物
	gotoxy(food.x, food.y);
	printf("X");

	//将移动前蛇尾的位置改为空格 
	if (tile_X != 0 && tile_Y!= 0)//防止第一次出现bug，画完食物后马上画空格的bug
	{
		gotoxy(tile_X, tile_Y);//第一次执行时 gotoxy直接被return
		printf(" ");
	}
	if (isRool)
	{
		gotoxy(snake.body[0].x, snake.body[0].y);
		printf("@");
	}
	gotoxy(WIDTH + 1, HEIGHT - 3);
	printf("当前难度： %d\n", 200-sleepTime);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);//得分颜色
	gotoxy(WIDTH+1, HEIGHT-2);
	printf("得分 ： %d\n", score);
}

//死亡检测
void ganmeOver(int mode)
{
	//身体触碰
	if (mode ==1)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		//避免吃身体被覆盖蛇头符号
		gotoxy(snake.body[0].x, snake.body[0].y);
		printf("@");//putchar("@")
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);//结束提示
	//碰墙
	gotoxy(0, HEIGHT + 1);
	printf("弟弟，你没了啊！\n");
	system("pause");
	exit(1);	//退出程序
}

//贪吃蛇程序模块：主程序、墙、蛇、食物
int main()
{
	//去掉控制台光标
	CONSOLE_CURSOR_INFO cci;
	cci.bVisible = FALSE;
	cci.dwSize = sizeof(cci);
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);

	//随机种子
	//printf("时间戳 = %d\n", time(NULL));//调试时间戳 记录出现bug时间
	srand((unsigned int)time(NULL)); 

	//设置墙颜色 
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);

	initWait();//初始化墙

	init_snake();//初始化蛇

	init_Food(); //初始化食物

	update(); //更新显示

	//记录蛇移动方向
	char key = 'd';
	//解决冲突按键 不允许180°
	static char prekey;

	while (snake.body[0].x >= 1 && snake.body[0].x <=  WIDTH-2 && 
		snake.body[0].y >=1  && snake.body[0].y <= HEIGHT-2 )
	{
		if (_kbhit())	//如果没有键盘输入 返回0 有输入 返回1
		{
			key = _getch();	//key = getchar();
		}
		if (key == 'd' && prekey == 'a' || key == 'a' && prekey == 'd' || 
			key == 'w' && prekey == 's' || key == 's' && prekey == 'w')
		{
			key = prekey;
		}
		else
		{
			prekey = key;
		}

		switch (key)
		{
		case 'w':
			offset_X = 0;
			offset_Y = -1;
			break;
		case 'a':
			offset_X = -1;
			offset_Y = 0;
			break;
		case 's':
			offset_X = 0;
			offset_Y = 1;
			break;
		case 'd':
			offset_X = 1;
			offset_Y = 0;
			break;
		}

		//蛇是否吃到自己的身体
		for (int i = 1; i < snake.size; i++)	//不能从0开始
		{
			if (snake.body[0].x == snake.body[i].x &&
				snake.body[0].y == snake.body[i].y)
			{
				ganmeOver(1);
			}
		}
		//蛇和食物碰撞  后面的移动蛇身代码已经添加一个节点

		if (snake.body[0].x == food.x && snake.body[0].y == food.y)
		{
			snake.size++;	//蛇头位置到了食物位置，而且尾巴+1 数组涨了一个，尾部赋值,变成#号完成变长
			score += 100;
			sleepTime -= 10;
			init_Food();//随机新的食物
		}

		//记录移动前蛇尾的坐标
		tile_X = snake.body[snake.size - 1].x;
		tile_Y = snake.body[snake.size - 1].y;

		for (int i = snake.size - 1; i > 0; i--)
		{
			//蛇从最后一个身体向前移动
			snake.body[i].x = snake.body[i - 1].x;
			snake.body[i].y = snake.body[i - 1].y;
		}
		//移动蛇头
		snake.body[0].x += offset_X;
		snake.body[0].y += offset_Y;

		//检测头尾是否一个坐标
		if (snake.body[0].x == tile_X && snake.body[0].y == tile_Y)
		{
			isRool = 1; //是头尾循环
		}
		else  isRool = 0;

		update(); //更新显示
		Sleep(sleepTime);//单位ms
	}
	ganmeOver(0);
	//system("pause");
	//getchar();
	return EXIT_SUCCESS;
} 
