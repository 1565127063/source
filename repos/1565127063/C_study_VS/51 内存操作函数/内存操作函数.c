#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)	
#pragma warning(disable:6031)
#define _CRT_SECURE_NO_WARNINGS


//memset �ڴ����� (��������ڴ�)
void test1()
{
	char buf[32] = "hello world";
	printf("buf = %s\n", buf);

	memset(buf, 'a', 32);
	printf("buf = %s\n", buf);//ȫ�����a 

	//��Ҫ��;������ڴ�
	memset(buf, 0, 32);
	printf("buf = %s\n", buf);
}


//��ӡ�ַ���
void printArray(char* arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%c", arr[i]);
	}
	printf("###\n");
}

//memcpy �ڴ濽��(���鸳ֵ)
void test2()
{
	char dst[64] = { 0 };
	char src[64] = "hello\0 world";
	strcpy(dst, src);	//����\0��������
	printArray(dst, sizeof(dst));
	memset(dst, 0, sizeof(dst));	//����ַ���

	//memset(Ŀ��,Դ������)
	memcpy(dst, src,sizeof(dst));	//���Ը���ȫ�����ֽ�
	printArray(dst, sizeof(dst));

	//��;����������и�ֵ
	int arr[5] = { 1,2,3,4,5 };
	int arr2[5];
	memcpy(arr2, arr, sizeof(arr));
	for (int i = 0; i < 5; i++)
	{
		printf("arr[%d] = %d\n", i+1, arr2[i]);
	}
}

//memmove
void test3()
{
	//�м��������ӵ���������ʼ����  �ڶ���������
	int arr[5] = { 10,20,30,40,50 };

	//ͨ���ڴ濽��ʵ�� û���ڴ��ص�ʱ������
	//memcpy(arr + 2, arr + 1, 3 * sizeof(int));	//���ڷ��� �п��ܺ�Ԥ�ڲ���

	memmove(arr + 2, arr + 1, 3 * sizeof(int));		//Ч�ʵ� ��ȫ

	for (int i = 0; i < 5; i++)
	{
		printf("%d\n", arr[i]);
	}
}

//memcmp �ڴ�Ƚ�
void test4()
{
	static char buf1[32] = "hello\0wofrld";
	static char buf2[32] = "hello\0aaa";

	if (strcmp(buf1,buf2) == 0)	//����
	{
		printf("strcmp: buf1 = buf2\n");
	}
	else
	{
		printf("strcmp: buf1 != buf2\n");
	}
	//һ����˵  strcmp�㹻��
	if (memcmp(buf1, buf2, sizeof(buf1)) == 0)
	{
		printf("memcmp: buf1 = buf2\n");
	}
	else
	{
		printf("memcmp: buf1 != buf2\n");
	}
}

//malloc   ���ڴ�Ķ�̬�洢��(����)�з���һ�鳤��Ϊsize�ֽڵ���������
//������ڴ�ռ� ���������ڣ�������������ű�ϵͳ�ͷ�
//ͨ������Ա�ֶ��ͷţ� ���ú��� free()
void test5()
{
	int* p = NULL;
	p = malloc(sizeof(int));
	//mallocҪ�ж�������ڴ��Ƿ�ɹ�
	if (NULL == p)
	{
		printf("����ʧ��\n");
		return;
	}
	*p = 1000;	//��������� ����������� 
	printf("*p = %d\n", *p);

	//����ڴ�
	memset(p, 0, 4);
	printf("*p = %d\n", *p);

	//�ͷ��ڴ�
	free(p);

}
//����Ԫ��
void setArr(int* arr,int len)
{
	printf("��������Ԫ�ظ�����ֵ\n");
	for (int i = 0; i < len; i++)
	{
		scanf("%d", &arr[i]);
		//scanf("%d", arr+i); //�ȼ���
	}
}
//��ӡԪ��
void prArr(int * arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//ʵ�ּ��װ汾 ��̬����
void test6()
{
	int num = 0;
	printf("�����������Ԫ�ظ���\n");
	scanf("%d", &num);

	int* arr = malloc(sizeof(int) * num);	//����

	if (arr == NULL)
	{
		printf("����ʧ��\n");
		return;
	}
	//����ڴ�
	memset(arr, 0, sizeof(int) * num);

	//����Ԫ��
	setArr(arr, num);

	//��ӡ����
	prArr(arr, num);

	//�ͷ�����
	free(arr);
}

//1.��Ҫ���ؾֲ������ĵ�ַ
int fun1()
{
	int num = 10;	//ջ�Ϸ����  {}���ͷ���
	return &num;
}
void test7()
{
	int* p = fun1();
	printf("*p = %d\n", *p);//
	printf("*p = %d\n", *p);	//�ڶ���ʹ�þͻ���� �ڴ�ռ䲻����
	//�ܽ᣺�������Ҫ���ڴ��Ѿ��ͷţ�����ڴ����ڷǷ�����
}

//2.���Է��ؾ�̬�����ĵ�ַ
int fun2()
{
	static int num = 10;	//��̬�����ᱣ��
	return &num;
}
void test8()
{
	int* p = fun2();
	printf("*p = %d\n", *p);
	printf("*p = %d\n", *p);
	//�ܽ᣺�������Ҫ���ڴ��Ѿ��ͷţ�����ڴ����ڷǷ�����
}

///3.��Ҫ�����Ѿ��ͷŵĶ����ռ�
test9()
{
	//ָ����ջ�ϣ�ָ��������ڶ���
	int * p = malloc(sizeof(int));
	printf("p = %d\n", p);

	*p = 1000;

	free(p);
	printf("p = %d\n", p);

	//*p = 2000;	//error �Ѿ��ͷŵ��޷�����
}

//4.��Ҫ�ͷ�Ұָ��
test10()
{
	int* p = malloc(sizeof(int));

	//free(p);
	//free(p);	//��ʱp����Ұָ�룬�޷��ͷ�
	if (p != NULL)
	{
		free(p);
		p = NULL;
	}

	free(p);//��ָ�����free
}

void allocatSpace(int* pp)
{
	//**p = 1000��
	//printf("%d\n", **p);
}
//ͬ��ָ�������ڴ�ʧ��
test11()
{
	int* p = NULL;
	//allocatSpace(p);	
	//*p = 1000;	//ֵ�����޷��޸�

	allocatSpace(p);
	//printf("%d\n", *p);
}

//����������� 1.���ú�������ֵ
int * allocatSpace2()
{
	int* pp = malloc(sizeof(int));
	return pp;
}
void test12()
{
	int* p = NULL;
	p = allocatSpace2();
	*p = 1000;	
	printf("%d\n", *p);
}

//����������� 2.���ø߼�ָ��
void allocatSpace3(int **pp)
{
	*pp = malloc(sizeof(int));
}
void freeSpcae(int* pp)
{
	if (pp != NULL)
	{
		free(pp);
		pp = NULL;
	}
}
void test13()
{
	int* p = NULL;
	allocatSpace3(&p);
	*p = 2000;
	printf("%d\n", *p);

	freeSpcae(p);
}

int main()
{
	//test1();
	//test2();
	test5();
	test6();
	test7();
	test8();
	system("pause");
	return EXIT_SUCCESS;
}