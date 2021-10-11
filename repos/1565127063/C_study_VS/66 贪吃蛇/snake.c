#include "snake.h"

void init_snake()
{
	//蛇初始为3的身体
	snake.size = 3;

	//设置蛇的位置 
	snake.body[0].x = WIDTH / 2;
	snake.body[0].y = HEIGHT / 2;
	snake.body[1].x = WIDTH / 2 - 1;
	snake.body[1].y = HEIGHT / 2;
	snake.body[2].x = WIDTH / 2 - 2;
	snake.body[2].y = HEIGHT / 2;
}