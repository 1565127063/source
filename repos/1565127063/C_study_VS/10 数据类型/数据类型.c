#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include<string.h>

//��������
//���õ������У� short�� int�� long�� long long
void test1() {
	short num1 = 32768;	    //������ 2 �ֽ� (-2^15 ~ 2^15-1) -32767~32767
	int num2 = 32768;		//����	4 �ֽ� (-2^31 ~ 2^31-1)  2,147,483,648
	long num3 = 10;			//������ win 4�ֽ� linux 4�ֽڣ�32λ�� 8�ֽڣ�64λ��
	long long num4 = 10;	//�������� 8 �ֽ� (-2^63 ~ 2^63-1)
	printf("num1 = %hd\n", num1);	//������
	printf("num2 = %d\n", num2);	//����
	printf("num3 = %ld\n", num3);	//������
	printf("num4 = %lld\n", num4);	//��������
}

void test2() {
	//�����з��ŵı���ʱ�����������ӵĹؼ���signed
	signed int a = 10;
	printf("a = %d\n", a);
	//�����޷��ŵı���ʱ����Ҫ���ӵĹؼ���unsigned
	unsigned int b = 10;
	printf("b = %d\n", b);
}

int main() {

	test1();
	test2();
	system("pause");
	return EXIT_SUCCESS;
}