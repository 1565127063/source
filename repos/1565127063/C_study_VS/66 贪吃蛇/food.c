#include "food.h"

void init_Food()
{
	int flag;//默认0 不冲突 1位置冲突
	while (1)
	{
		flag = 0;
		//x 1-58 y 1-28
		food.x = rand() % (WIDTH - 2) + 1;	//随机rand 58 即0-57 再+1为 1-58
		food.y = rand() % (HEIGHT - 2) + 1;
		for (int i = 0; i < snake.size; i++)
		{
			if (snake.body[i].x == food.x && snake.body[i].y == food.y)
			{
				flag = 1;
				break;
			}
		}		
		//如果检测到有重复 就重新进入while1 随机新的值
		if (flag == 0)
		{
			//全部没有重复
			break;//退出while的循环
		}
	}
}
