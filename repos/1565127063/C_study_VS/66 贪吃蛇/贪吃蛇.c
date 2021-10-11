#pragma once //��ֹͷ�ļ�  �ظ�����
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS

#include<windows.h>
#include "snake.h"
#include "food.h"
#include <time.h>
#include <conio.h>	//_getch ͷ�ļ� ����̨�����������

int sleepTime = 200;//ˢ��ʱ��
int score = 0;

//��궨λ
void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	//���ÿ���̨���λ��
	//���е���Դ�����Խо��GetStdHandle
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
//������ʾ
void update()
{
	for (int i = 0; i < snake.size; i++)
	{
		gotoxy(snake.body[i].x, snake.body[i].y);
		if (i == 0)
		{
			//��ͷ
			printf("@");
		}
		else printf("#");//����
	}
	//��ʾʳ��
	gotoxy(food.x, food.y);
	printf("X");

	//���ƶ�ǰ��β��λ�ø�Ϊ�ո� 
	if (tile_X != 0 && tile_Y!= 0)//��ֹ��һ�γ���bug������ʳ������ϻ��ո��bug
	{
		gotoxy(tile_X, tile_Y);//��һ��ִ��ʱ gotoxyֱ�ӱ�return
		printf(" ");
	}
	if (isRool)
	{
		gotoxy(snake.body[0].x, snake.body[0].y);
		printf("@");
	}
	gotoxy(WIDTH + 1, HEIGHT - 3);
	printf("��ǰ�Ѷȣ� %d\n", 200-sleepTime);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);//�÷���ɫ
	gotoxy(WIDTH+1, HEIGHT-2);
	printf("�÷� �� %d\n", score);
}

//�������
void ganmeOver(int mode)
{
	//���崥��
	if (mode ==1)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		//��������屻������ͷ����
		gotoxy(snake.body[0].x, snake.body[0].y);
		printf("@");//putchar("@")
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);//������ʾ
	//��ǽ
	gotoxy(0, HEIGHT + 1);
	printf("�ܵܣ���û�˰���\n");
	system("pause");
	exit(1);	//�˳�����
}

//̰���߳���ģ�飺������ǽ���ߡ�ʳ��
int main()
{
	//ȥ������̨���
	CONSOLE_CURSOR_INFO cci;
	cci.bVisible = FALSE;
	cci.dwSize = sizeof(cci);
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);

	//�������
	//printf("ʱ��� = %d\n", time(NULL));//����ʱ��� ��¼����bugʱ��
	srand((unsigned int)time(NULL)); 

	//����ǽ��ɫ 
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);

	initWait();//��ʼ��ǽ

	init_snake();//��ʼ����

	init_Food(); //��ʼ��ʳ��

	update(); //������ʾ

	//��¼���ƶ�����
	char key = 'd';
	//�����ͻ���� ������180��
	static char prekey;

	while (snake.body[0].x >= 1 && snake.body[0].x <=  WIDTH-2 && 
		snake.body[0].y >=1  && snake.body[0].y <= HEIGHT-2 )
	{
		if (_kbhit())	//���û�м������� ����0 ������ ����1
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

		//���Ƿ�Ե��Լ�������
		for (int i = 1; i < snake.size; i++)	//���ܴ�0��ʼ
		{
			if (snake.body[0].x == snake.body[i].x &&
				snake.body[0].y == snake.body[i].y)
			{
				ganmeOver(1);
			}
		}
		//�ߺ�ʳ����ײ  ������ƶ���������Ѿ����һ���ڵ�

		if (snake.body[0].x == food.x && snake.body[0].y == food.y)
		{
			snake.size++;	//��ͷλ�õ���ʳ��λ�ã�����β��+1 ��������һ����β����ֵ,���#����ɱ䳤
			score += 100;
			sleepTime -= 10;
			init_Food();//����µ�ʳ��
		}

		//��¼�ƶ�ǰ��β������
		tile_X = snake.body[snake.size - 1].x;
		tile_Y = snake.body[snake.size - 1].y;

		for (int i = snake.size - 1; i > 0; i--)
		{
			//�ߴ����һ��������ǰ�ƶ�
			snake.body[i].x = snake.body[i - 1].x;
			snake.body[i].y = snake.body[i - 1].y;
		}
		//�ƶ���ͷ
		snake.body[0].x += offset_X;
		snake.body[0].y += offset_Y;

		//���ͷβ�Ƿ�һ������
		if (snake.body[0].x == tile_X && snake.body[0].y == tile_Y)
		{
			isRool = 1; //��ͷβѭ��
		}
		else  isRool = 0;

		update(); //������ʾ
		Sleep(sleepTime);//��λms
	}
	ganmeOver(0);
	//system("pause");
	//getchar();
	return EXIT_SUCCESS;
} 
