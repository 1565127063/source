#pragma once //��ֹͷ�ļ�  �ظ�����
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS
#include "wall.h"

//�ߵ�����
struct BODY
{
	int x;
	int y;
};

//�ߵĽṹ��
struct SNAKE
{
	//�ߵ�����
	struct BODY body[(WIDTH - 2) * (HEIGHT - 2)];
	//�ߵĳ���
	int size;
}snake;

//�ƶ�ƫ����
int offset_X;//x
int offset_Y;//y

//��¼��β������
int tile_X;
int tile_Y;

int isRool; //�ж��Ƿ�ͷβѭ��

void init_snake();
