#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)	
#pragma warning(disable:6031)
#define _CRT_SECURE_NO_WARNINGS
#include "test.h"

/*
#include <time.h>
	time_t tm = time(NULL);//�õ�ϵͳʱ��
	printf("time(NULL) = %lld\n", time(NULL)); //ʱ���ת�����ڹ���
	srand((unsigned int)tm);//�������ֻ��Ҫ����һ�μ���
	//���Ͷ���unsigned int =  size_t
*/

//��Ŀ����
//����50�������Ŀ����ʽ���� ��1 +1 = 
//���⣺��50����Ŀ���������1~100֮�� ����� + - * /
//���⣺���ó���50����Ŀ����������һ���ļ���


int main()
{
	setQuestion();
	answerQuestion();

	system("pause");
	return EXIT_SUCCESS;
}
