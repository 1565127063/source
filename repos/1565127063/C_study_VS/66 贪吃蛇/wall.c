#include "wall.h"

//��ʼ��ǽ
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
			printf("\t̰���ߴ���ս");
		}
		if (i == 6)
		{
			printf("\t�����ϣ�w");
		}
		if (i == 7)
		{
			printf("\t�����£�s");
		}
		if (i == 8)
		{
			printf("\t������a");
		}
		if (i == 9)
		{
			printf("\t�����ң�d");
		}
		if (i == 13)
		{
			printf("\t2000�־��Ǿ�������");
		}
		printf("\n");
	}
}