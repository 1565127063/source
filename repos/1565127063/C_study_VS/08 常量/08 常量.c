#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include<string.h>

#define DAY 7
void test1() {
	//�����������ڼ䲻�����޸ĵ�ֵ
	//1.��ֵ���� 100 200 3.14 1.1
	//2.�ַ�����  'a' 'b' '\n'
	//3.�ַ�������	"hello!" "abc"
	//4.���ų������곣����
		printf("һ�ܵ�������%d��\n", DAY); 
			//DAY = 14;	�����޷�����
	//5.const���εı���
		const int month = 12;
		//month = 24;	const���κ��޷��޸�
		printf("һ��һ����%d��\n",month);
}

int main() {
	
	test1();

	system("pause");
	return EXIT_SUCCESS;
}