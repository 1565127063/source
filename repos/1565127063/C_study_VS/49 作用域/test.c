#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)	
#pragma warning(disable:6031)
#define _CRT_SECURE_NO_WARNINGS

//c������  ��ͨȫ�ֱ��������صļ��˹ؼ��� extern

int g_b = 20;   //extern int g_b = 20; �ȼ���

//��̬��ȫ�ֱ���Ҳֻ���ڱ��ļ�ʹ��
static int g_s_b = 20000;

void test_fun1()
{
	printf("hello fun1\n");
}

static void test_fun2()
{
	printf("hello fun2\n");
}