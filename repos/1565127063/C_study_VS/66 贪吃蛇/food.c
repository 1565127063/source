#include "food.h"

void init_Food()
{
	int flag;//Ĭ��0 ����ͻ 1λ�ó�ͻ
	while (1)
	{
		flag = 0;
		//x 1-58 y 1-28
		food.x = rand() % (WIDTH - 2) + 1;	//���rand 58 ��0-57 ��+1Ϊ 1-58
		food.y = rand() % (HEIGHT - 2) + 1;
		for (int i = 0; i < snake.size; i++)
		{
			if (snake.body[i].x == food.x && snake.body[i].y == food.y)
			{
				flag = 1;
				break;
			}
		}		
		//�����⵽���ظ� �����½���while1 ����µ�ֵ
		if (flag == 0)
		{
			//ȫ��û���ظ�
			break;//�˳�while��ѭ��
		}
	}
}
