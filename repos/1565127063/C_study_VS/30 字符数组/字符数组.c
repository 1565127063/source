#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)	//�����
#pragma warning(disable:6031)	//ȥ����

//�ַ����鶨���ʼ��
void test1()
{
	char arr[50];
	//arr[strlen(arr) - 1] = '\0';
	printf("%d\n", sizeof(arr)); //5  charһ���ֽ� 1 * 5
	
	//char arr1[] = { 'H','e','l','l','o' };	//%s �������
	char arr1[] = { 'H','e','l','l','o','1','\0'};	
	for (int i = 0; i < 6; i++)
	{
		printf("%c",arr1[i]);
	}
	printf("\n");
	printf("%s\n",arr1);	//%s ��ʼ�� \0����

	char arr2[] = "hello2"; 
	printf("%s\n", arr2);	//%s�������� ���ֶ�����ʽ���
}

//�ַ���ͳ��
void test2()
{
	char str1[32] = "hello world";
	// strlen(str)  ͳ���ַ������Ⱥ���  ������\0
	printf("%d\n",strlen(str1));	//ʵ���ַ�������11
	printf("%d\n",sizeof(str1));	//�ַ��������32

	char str2[] = "hello world";
	printf("%d\n", strlen(str2));	//11
	printf("%d\n", sizeof(str2));	//12 ���� \0 

	char str3[] = "hello\0world"; 
	printf("%d\n", strlen(str3));	//5 ����\0����
	printf("%d\n", sizeof(str3));	//12 ��������\0

	// '\0'������ò�Ҫ�������֣��п��ܼ��������������պ���һ��ת���ַ�
	// '\ddd' 8 ����ת���ַ���  d ��Χ 0~7
	// '\xhh' 16 ����ת���ַ��� h ��Χ 0~9�� a~f�� A~F 2 λ 16 ����
	// \012 �൱�� \n

	/* '//'��2 '\\'��1 1��1 \123��1 abc��3 \xac��1 hehe��4 \0 */
	char str4[] = "//\\1\123abc\xachehe";
	printf("%d\n", strlen(str4));	//13
	printf("%d\n", sizeof(str4));	//14

	char arr[] = "hello word!";
	// strlen(arr) 
	printf("%d\n", strlen(arr));//11

}

//�ַ���ͳ��
void test3()
{
	//int buf[16] = ""; �ȼ���
	char buf[16] = { 0 };
	scanf("%s",buf);	//scanf�����ո�ʱ�����
	printf("%s\n",buf);	//hello world ʵ��hello 
}
//�ַ�������
void test4()
{
	char buf1[16] = { 0 };
	//gets(buf1);	//���Ƽ�ʹ�� ���������Խ������
	fgets(buf1,sizeof(buf1),stdin);	//stdin ��׼�������豸-���� 
	//���15+\0
	printf("%s\n", buf1);
}
//�ַ������
void test5()
{
	char buf2[16] = "hello world2";
	//printf("%s\n", buf2);
	//puts(buf2); //�Դ�������� 
	fputs(buf2,stdout);	//��׼���豸���-��Ļ ��������
	printf("\n");
}
int main()
{
	test1();
	test2();
	test3();
	test4();
	test5();
	system("pause");
	return EXIT_SUCCESS;
}
