#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	//��Ҫ������ļ�
#include<stdlib.h>	//systemͷ�ļ�

#pragma warning(disable:4996)	//�����
#pragma warning(disable:6031)	//ȥ����

int main()
{
	//vs�в�����ʹ�ô�ͳc���Կ⺯����scanf��sprintf
	//�������1  #define _CRT_SECURE_NO_WARNINGS
	//�������2  #pragme warning(disable:4996)
	//�������3  ��Ŀ���� c/c++ Ԥ�������༭���  _CRT_SECURE_NO_WARNINGS
	//�������4  scnaf   scanf_s
	char buf[1024] = { 0 };
	sprintf(buf, "%s", "hello word\n");
	printf("%s", buf);

	system("pause");
	return 0;
}
