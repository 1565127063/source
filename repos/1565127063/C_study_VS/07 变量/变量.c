#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include<string.h>

//�����������ʹ���ڱ�д����֮ǰ��һЩ�ƻ�
//�������������ڷ��������ڳ����е�С����
//�������δ���������� C�����޷�ͨ������
void test01() {
	int a = 10;
	printf("a = %d\n", a);
	a = 20;
	printf("a = %d\n", a);
}
void test02() {
	int b;	//����������ʼֵ�Ļ�ֵ������ģ���vs�޷�����
	printf("b= %d\n", b);	//�����0
}
//�����Ķ�����ʹ��ǰ�������Զ�����
//�����Ķ����ڱ���ʹ�ú���Ҫ��ʾ����������ؼ��� extern
void test03() 
{
	extern int g_a;	//���߱�����g_a������Ҫ���� ���Һ���Բ�ѯ��  ��Ҫ����
	printf("g_a = %d\n", g_a);
}
int g_a = 100;

int main() {

	test01();
	/*test02();*/
	test03();

	system("pause");
	return EXIT_SUCCESS;
}