#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include<string.h>

//argc	�����б�������
//argv  �����в���

int main(int argc, char* argv[])
{
	printf("�����в�������: %d\n", argc);
	//����ҵ��������1��  ÿ��������
	if (argc > 1)
	{
		int i = 0;
		for (i = 0; i < argc; i++)
		{
			printf("%s\n", argv[i]);
		}
	}
	system("pause");
	return EXIT_SUCCESS;
}