#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {

	printf("hello\n");
	printf("abc\rdef");	//r �����굽���� abc������
	printf("\\\\\n");		//����\\�������һ��
	printf("abc\tdef");	//ˮƽ�Ʊ�  ��һ��tab��
	printf("\a");	//������
	printf("%%");	//�����������һ��
	printf("asdflkj\r111");	// \r �س�

	system("pause");
	return EXIT_SUCCESS;
}
