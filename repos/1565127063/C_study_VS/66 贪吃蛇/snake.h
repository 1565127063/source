#pragma once //防止头文件  重复包含
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS
#include "wall.h"

//蛇的身体
struct BODY
{
	int x;
	int y;
};

//蛇的结构体
struct SNAKE
{
	//蛇的数组
	struct BODY body[(WIDTH - 2) * (HEIGHT - 2)];
	//蛇的长度
	int size;
}snake;

//移动偏移量
int offset_X;//x
int offset_Y;//y

//记录蛇尾的坐标
int tile_X;
int tile_Y;

int isRool; //判断是否头尾循环

void init_snake();
