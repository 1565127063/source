#include "wall.h"

//初始化墙
void initWait()
{
	//i=o j=o i=WIDTH-1 j=HEIGHT-1
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			if (i==0 || i== HEIGHT-1 || j==0 ||j==WIDTH-1)
			{
				printf("*");
			}
			else
			{
				printf(" ");
			}
		}
		if (i== 5)
		{
			printf("\t贪吃蛇大作战");
		}
		if (i == 6)
		{
			printf("\t控制上：w");
		}
		if (i == 7)
		{
			printf("\t控制下：s");
		}
		if (i == 8)
		{
			printf("\t控制左：a");
		}
		if (i == 9)
		{
			printf("\t控制右：d");
		}
		if (i == 13)
		{
			printf("\t2000分就是绝顶高手");
		}
		printf("\n");
	}
}