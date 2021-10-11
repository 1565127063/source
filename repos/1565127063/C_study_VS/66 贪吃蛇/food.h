#pragma once //防止头文件  重复包含
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS
#include "wall.h"
#include "snake.h"
//

struct FOOD
{
	int x;
	int y;
}food;

//初始化函数
void init_Food();
