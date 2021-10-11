#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)	
#pragma warning(disable:6031)
#define _CRT_SECURE_NO_WARNINGS

// 1. strcpy() 
// char* strcpy(char* dest, const char* src);
//	src��ָ����ַ������Ƶ�dest��ָ��Ŀռ��У� '\0'Ҳ�´����ȥ
	//	dest��Ŀ���ַ����׵�ַ   src��Դ�ַ��׵�ַ
void test1()
{
	char buf[32] = { 0 };	//char buf[32];
	//���ַ����鸳ֵʱ��Ҫʹ�õ�strcpy() 
	strcpy(buf, "hello world!");// ��ʹû�г�ʼ��\0Ҳ������ȥ
	printf("%s\n", buf);

	strcpy(buf, "hello \0world!");// ����\0��ֹͣ���ַ�������ͳһ����
	printf("%s\n", buf);

	char buf2[10] = { 0 };
	//strcpy(buf2, "hello world!");//error ԭ�ַ�����Ŀ�곤�����
	//printf("%s\n", buf2);
}

//2. strncpy()
//char *strncpy(char *dest, const char *src, size_t n);
//��srcָ���ַ�����ǰn���ַ����Ƶ�dest��ָ��Ŀռ��У� 
//�Ƿ񿽱���������ָ���ĳ����Ƿ����'\0'��
void test2()
{
	char buf[32] = { 0 };
	strncpy(buf, "hello world", 8);
	printf("%s\n", buf);	//hello wo

	char buf2[32] = { 0 };
	strncpy(buf2, "hello\0 world", 8);//����\0��ֹͣ���ַ�������ͳһ����
	printf("%s\n", buf2);	//hello  

}

//3. strcat
//char *strcat(char *dest, const char *src);
//��src�ַ������ӵ�dest��β���� ��\0��Ҳ��׷�ӹ�ȥ
	//dest��Ŀ���ַ����׵�ַ   src��Դ�ַ��׵�ַ
void test3()
{
	char buf1[32] = "hello ";	//ƴ�Ӵ�hello���\0��ʼƴ
	char buf2[32] = "world! ";	//��world�� ���\0����
	strcat(buf1, buf2);	//ֻ�޸�buf1
	printf("buf1 = %s\n", buf1);	//hello world
	printf("%s\n", buf2);			//hello world
}

//4. strncat 
//char* strncat(char* dest, const char* src, size_t n);
//������ ƴ���ַ���2ǰn��Ԫ��
void test4()
{
	char buf1[32] = "hello ";
	char buf2[32] = "world!";
	strncat(buf1, buf2,3);	//ֻ�޸�buf1
	printf("%s\n", buf1);	//hello world
	printf("%s\n", buf2);	//world
}

//5.strcmp()    compare�Ƚ�
//int strcmp(const char *s1, const char *s2);
//���ܣ��Ƚ� s1 �� s2 �Ĵ�С�� �Ƚϵ����ַ� ASCII ���С��
	//s1���ַ���1�׵�ַ  s2���ַ���2�׵�ַ
	//���0   ����>0  С��<0
void test5()
{
	char buf1[] = "hello";
	printf("buf1  = %s\n", buf1);

	printf("������һ���ַ���\n");
	char buf2[32] = { 0 };
	fgets(buf2, sizeof(buf2), stdin);

	//��buf2  \n�ĳ�\0
	buf2[strlen(buf2) - 1] = '\0';

	if (strcmp(buf1,buf2) == 0)	//����
	{
		printf("buf1 = buf2\n");
	}
	else if (strcmp(buf1, buf2) > 0)//strcmp(buf1, buf2) == 1
	{
		printf("buf1 > buf2\n");
	}
	else if(strcmp(buf1, buf2) < 0)	//strcmp(buf1, buf2) == -1
	{
		printf("buf1 < buf2\n");
	}
}

//6.strncmp()    compare�Ƚ�
//int strcmp(const char *s1, const char *s2);
//���ܣ��Ƚ� s1 �� s2 ǰn���ַ��Ĵ�С�� �Ƚϵ����ַ� ASCII ���С��
//	s1���ַ���1�׵�ַ  s2���ַ���2�׵�ַ	n��ָ���Ƚ��ַ���������
//	���0   ����>0  С��<0
void test6()
{
	//char buf1[] = "hello";
	//printf("buf1  = %s\n", buf1);

	//printf("������һ���ַ���\n");
	//char buf2[32] = { 0 };
	//fgets(buf2, sizeof(buf2), stdin);

	////��buf2  \n�ĳ�\0
	//buf2[strlen(buf2) - 1] = '\0';

	//if (strncmp(buf1, buf2,5) == 0)	//����
	//{
	//	printf("buf1 = buf2\n");
	//}
	//else if (strncmp(buf1, buf2,5) > 0)//strcmp(buf1, buf2) == 1
	//{
	//	printf("buf1 > buf2\n");
	//}
	//else if (strncmp(buf1, buf2,5) < 0)	//strcmp(buf1, buf2) == -1
	//{
	//	printf("buf1 < buf2\n");
	//}

	printf("������һ������: spring  summer antumn winter\n");
	char buf[32] = { 0 };
	fgets(buf, sizeof(buf), stdin);
	//��buf2  \n�ĳ�\0
	buf[strlen(buf) - 1] = '\0';
	if (strncmp(buf,"spring",6) == 0)
	{
		printf("����\n");
	}
	else if (strncmp(buf, "summer", 6) == 0)
	{
		printf("����\n");
	}
	else if (strncmp(buf, "antumn", 6) == 0)
	{
		printf("����\n");
	}
	else if (strncmp(buf, "winter", 6) == 0)
	{
		printf("����\n");
	}
	else
	{
		printf("�������뷶Χ\n");
	}
}

//7.sprintf() ��ʽ���ַ���
//int sprintf(char *str , const char *format, ...);
//���ܣ����ݲ���format�ַ�����ת������ʽ�����ݣ�Ȼ�󽫽�������strָ���Ŀռ��У� 
//ֱ�������ַ��������� '\0' Ϊֹ��
void test7()
{
	int year = 2021;
	int month = 02;
	int day = 9;

	char buf[32] = { 0 };
	sprintf(buf, "%d��%d��%d��", year, month, day);	//����printf�﷨

	//strcpy(buf, "2021��2��9��"); //�ȼ���
	printf("buf = %s\n", buf);
}

//8 sscanf()  �ַ������
//int sscanf(const char *str, const char *format, ...);
//��strָ�����ַ�����ȡ���ݣ������ݲ���format�ַ�����ת������ʽ�����ݡ�
void test8()
{
	static char msg[128] = "phone:15868000000:20210209;��ֵ����";
	long long phoneNum = 0;
	int year = 2021;
	int month = 2;
	int day = 9;
	char text[64] = { 0 };

	sscanf(msg, "phone:%lld;%d%d%d;%s", &phoneNum, &year, &month, &day, text);
	printf("%lld\n", phoneNum);
	printf("%d\n", year);
	printf("%d\n", month);
	printf("%d\n", day);
	printf("%s\n", text);
}

//strchr()   
//char *strchr(const char *s, int c);
//���ܣ����ַ���s�в�����ĸc���ֵ�λ��
void test9()
{
	static char buf[32] = "heeebeb20@qq.com";
	char * ret = strchr(buf, '@');
	if (ret == NULL)
	{
		printf("û���ҵ�@����\n");
	}
	else
	{
		printf("�ҵ���@����,λ�ã� %d\n",ret-buf);
	}
}

//strstr()
//char *strstr(const char *haystack, const char *needle);
//���ܣ����ַ���haystack�в����ַ���needle���ֵ�λ��
void test10()
{
	char* str = "abcdefghijk";
	char* ret = strstr(str, "de");
	if (ret == NULL)
	{
		printf("û���ҵ�@����\n");
	}
	else
	{
		printf("�ҵ���@����,λ�ã� %d\n", ret - str);//3 ��0��ʼ
	}
}

//���ν���
//�ϵ� ����SB SB SB
//�ϵ� ����** ** **
void test11()
{
	char buf[1024] = { 0 };
	fgets(buf, sizeof(buf), stdin);
	//buf \n ��� \0
	buf[strlen(buf) - 1] = '\0';
	char* p = buf;	//������ʱָ������ַ���

	while (1)
	{
		//�ϵ� ����sb sb sb
		char* ret = strstr(p, "sb");	//ֱ���޸���ʱ���ַ���ָ����������
		if (ret != NULL)
		{
			//�ҵ��˽�������
			strncpy(ret, "**", 2);	//�����ַ����������滻�����δ�
			p = ret + 2;	//�ҵ�����ƫ����λ
		}
		else
		{
			break;
		}
	}
	printf("%s\n", buf);
}

//test11 �Ż�
void test12()
{
	char buf[1024] = { 0 };
	fgets(buf, sizeof(buf), stdin);
	//buf \n ��� \0
	buf[strlen(buf) - 1] = '\0';
	char* p = buf;	//������ʱָ������ַ���

	char* ret = NULL;
	while (ret = strstr(p,"sb"))
	{
		strncpy(ret, "**", 2);
		p = ret + 2;
	}
	printf("%s\n", buf);
}

// strtok()
//char *strtok(char *str, const char *delim);
//�����ַ����ָ��һ����Ƭ��,�������ֶ��ʱֻ�滻��һ��Ϊ\0
void test13()
{
	static char buf[1024] = "����:����:����:����:�Ǻ�";
	//������ÿ�����ݶ���ָ��
	char* names[64] = { 0 };
	//�ָ��ĸ����飬�ָ�������ʲô
	//char* name1 = strtok(buf, ":"); //��һ�ηָ�
	//printf("%s\n", name1);
	//name1 = strtok(NULL, ":"); //�ӵڶ��ηָʼ  ����1��NULL
	//printf("%s\n", name1);

	int i = 0;	//�����±�
	names[i] = strtok(buf, ":");
	//���ָΪ��һ��ʱ �ͽ���ѭ��
	while (names[i] != NULL)
	{
		i++;
		//�ָ���ֵ����������
		names[i] = strtok(NULL, ":");
	}
	//���������ӡ
	i = 0;
	while (names[i] != NULL)
	{
		printf("%s\n", names[i++]);
	}
}

//test13�Ż�
void test14()
{
	static char buf[1024] = "����:����:����:����:�Ǻ�";
	char* names[64] = { buf,NULL };

	int i = 0;
	//ֱ���жϷָ�Ľ���Ƿ���ֵ
	//i=0 buf �ָ����һ��names[0]  ֮��i=1  null names[1]....

	while ((names[i++] = strtok(names[i],":")) != NULL) 
	{
		//i++; //i++����д������������
	}

	//���������ӡ
	i = 0;
	while (names[i] != NULL)
	{
		printf("%s\n", names[i++]);
	}
}

//���ַָ��ʶ
void test15()
{
	char buf[1024] = "haha?hehe:lalla###xixi**!!aa";
	char* words[64] = { buf,NULL };
	int i = 0;
	while ((words[i++] = strtok(words[i],"?#:*!")) != NULL){}

	//���������ӡ
	i = 0;
	while (words[i] != NULL)
	{
		printf("%s\n", words[i++]);
	}
}

//atoi() �ַ���ת��Ϊ����
//	int atoi(const char *nptr);
//atoi()��ɨ��nptr�ַ���������ǰ��Ŀո��ַ���ֱ���������ֻ������Ųſ�ʼ��ת��

//atof()����һ��С����ʽ���ַ���ת��Ϊһ����������
//atol()����һ���ַ���ת��Ϊ long ����
void test16()
{
	int num = 0;
	char buf[] = "321abc123";
	num = atoi(buf);
	printf("num = %d\n", num);	//321

	//sscanfҲ��������   ��ʽ����Ϣ ��һ��ƥ��ʧ�� �ͽ���ƥ��
	sscanf("abc1234", "%*[a-z]%d", &num);
	printf("num = %d\n", num);	//1234

	int a = 0, b = 0;
	sscanf("1234 5678", "%d %d", &a, &b);
	printf("a= %d\n", a);
	printf("b= %d\n", b);
}

int main()
{
	test16();

	system("pause");
	return EXIT_SUCCESS;
}


