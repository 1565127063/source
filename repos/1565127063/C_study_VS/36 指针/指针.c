#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS

//ָ��Ķ���
void test1()
{
	//������ͨ����
	int a = 10;
	//����ָ����� ��ʱ��Ұָ��
	int* p; 
	//ָ�����ͨ����������ϵ 
	p = &a;		//p����a�ĵ�ַ	ָ���ָ��
	//ָ������ڴ�
	*p = 20;	//*p�޸�a��Ӧ�ĵ�ַ ָ��ָ���ֵ

	printf("%d\n",a);
	printf("%d\n",*p);
	//printf("%d\n",p);	//����鿴��ַ����
	//printf("%d\n",&a);
	//printf("%p\n",p);	//��ӡ��ַ  16����

	//ע������ * �� & ͬʱ���� �����������ε���
	//*pΪʲô��a? ����p = &a;   * p = *&a;  * p = a;
}

//ָ��Ŀռ��С 
//4���ֽ�(32λ) 8���ֽ�(64λ) 
void test2()
{
	//����ԭ��������ʲô��ָ��ֻ��Ҫ4���ֽڣ�32λ����ŵ�ַ��ž͹�
	printf("sizeof int * = %d\n", sizeof(int *));
	printf("sizeof char * = %d\n", sizeof(char *));
	printf("sizeof double * = %d\n", sizeof(double *));
	printf("sizeof long * = %d\n", sizeof(long *));
	printf("sizeof short * = %d\n", sizeof(short *));
	//�����������޸� debug x86
}


void test3()
{
	int a = 10;
	int* p;
	p = &a;
	printf("%d", a);
	printf("p=%d,&p=%d", p, &p);

}

int main()
{
	test1();
	test2();
	test3();
	system("pause");
	return EXIT_SUCCESS;
}
