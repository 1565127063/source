#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)	
#pragma warning(disable:6031)
#define _CRT_SECURE_NO_WARNINGS

// 1. strcpy() 
// char* strcpy(char* dest, const char* src);
//	src所指向的字符串复制到dest所指向的空间中， '\0'也会拷贝过去
	//	dest：目的字符串首地址   src：源字符首地址
void test1()
{
	char buf[32] = { 0 };	//char buf[32];
	//给字符数组赋值时需要使用到strcpy() 
	strcpy(buf, "hello world!");// 即使没有初始化\0也会加入进去
	printf("%s\n", buf);

	strcpy(buf, "hello \0world!");// 遇到\0就停止，字符串函数统一性质
	printf("%s\n", buf);

	char buf2[10] = { 0 };
	//strcpy(buf2, "hello world!");//error 原字符串比目标长会崩溃
	//printf("%s\n", buf2);
}

//2. strncpy()
//char *strncpy(char *dest, const char *src, size_t n);
//把src指向字符串的前n个字符复制到dest所指向的空间中， 
//是否拷贝结束符看指定的长度是否包含'\0'。
void test2()
{
	char buf[32] = { 0 };
	strncpy(buf, "hello world", 8);
	printf("%s\n", buf);	//hello wo

	char buf2[32] = { 0 };
	strncpy(buf2, "hello\0 world", 8);//遇到\0就停止，字符串函数统一性质
	printf("%s\n", buf2);	//hello  

}

//3. strcat
//char *strcat(char *dest, const char *src);
//将src字符串连接到dest的尾部， ‘\0’也会追加过去
	//dest：目的字符串首地址   src：源字符首地址
void test3()
{
	char buf1[32] = "hello ";	//拼接从hello后的\0开始拼
	char buf2[32] = "world! ";	//到world！ 后的\0结束
	strcat(buf1, buf2);	//只修改buf1
	printf("buf1 = %s\n", buf1);	//hello world
	printf("%s\n", buf2);			//hello world
}

//4. strncat 
//char* strncat(char* dest, const char* src, size_t n);
//很少用 拼接字符串2前n个元素
void test4()
{
	char buf1[32] = "hello ";
	char buf2[32] = "world!";
	strncat(buf1, buf2,3);	//只修改buf1
	printf("%s\n", buf1);	//hello world
	printf("%s\n", buf2);	//world
}

//5.strcmp()    compare比较
//int strcmp(const char *s1, const char *s2);
//功能：比较 s1 和 s2 的大小， 比较的是字符 ASCII 码大小。
	//s1：字符串1首地址  s2：字符串2首地址
	//相等0   大于>0  小于<0
void test5()
{
	char buf1[] = "hello";
	printf("buf1  = %s\n", buf1);

	printf("请输入一个字符串\n");
	char buf2[32] = { 0 };
	fgets(buf2, sizeof(buf2), stdin);

	//将buf2  \n改成\0
	buf2[strlen(buf2) - 1] = '\0';

	if (strcmp(buf1,buf2) == 0)	//常用
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

//6.strncmp()    compare比较
//int strcmp(const char *s1, const char *s2);
//功能：比较 s1 和 s2 前n个字符的大小， 比较的是字符 ASCII 码大小。
//	s1：字符串1首地址  s2：字符串2首地址	n：指定比较字符串的数量
//	相等0   大于>0  小于<0
void test6()
{
	//char buf1[] = "hello";
	//printf("buf1  = %s\n", buf1);

	//printf("请输入一个字符串\n");
	//char buf2[32] = { 0 };
	//fgets(buf2, sizeof(buf2), stdin);

	////将buf2  \n改成\0
	//buf2[strlen(buf2) - 1] = '\0';

	//if (strncmp(buf1, buf2,5) == 0)	//常用
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

	printf("请输入一个季节: spring  summer antumn winter\n");
	char buf[32] = { 0 };
	fgets(buf, sizeof(buf), stdin);
	//将buf2  \n改成\0
	buf[strlen(buf) - 1] = '\0';
	if (strncmp(buf,"spring",6) == 0)
	{
		printf("春天\n");
	}
	else if (strncmp(buf, "summer", 6) == 0)
	{
		printf("夏天\n");
	}
	else if (strncmp(buf, "antumn", 6) == 0)
	{
		printf("秋天\n");
	}
	else if (strncmp(buf, "winter", 6) == 0)
	{
		printf("冬天\n");
	}
	else
	{
		printf("不在输入范围\n");
	}
}

//7.sprintf() 格式化字符串
//int sprintf(char *str , const char *format, ...);
//功能：根据参数format字符串来转换并格式化数据，然后将结果输出到str指定的空间中， 
//直到出现字符串结束符 '\0' 为止。
void test7()
{
	int year = 2021;
	int month = 02;
	int day = 9;

	char buf[32] = { 0 };
	sprintf(buf, "%d年%d月%d日", year, month, day);	//类似printf语法

	//strcpy(buf, "2021年2月9日"); //等价于
	printf("buf = %s\n", buf);
}

//8 sscanf()  字符串拆分
//int sscanf(const char *str, const char *format, ...);
//从str指定的字符串读取数据，并根据参数format字符串来转换并格式化数据。
void test8()
{
	static char msg[128] = "phone:15868000000:20210209;充值话费";
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
//功能：在字符串s中查找字母c出现的位置
void test9()
{
	static char buf[32] = "heeebeb20@qq.com";
	char * ret = strchr(buf, '@');
	if (ret == NULL)
	{
		printf("没有找到@符号\n");
	}
	else
	{
		printf("找到了@符号,位置： %d\n",ret-buf);
	}
}

//strstr()
//char *strstr(const char *haystack, const char *needle);
//功能：在字符串haystack中查找字符串needle出现的位置
void test10()
{
	char* str = "abcdefghijk";
	char* ret = strstr(str, "de");
	if (ret == NULL)
	{
		printf("没有找到@符号\n");
	}
	else
	{
		printf("找到了@符号,位置： %d\n", ret - str);//3 从0开始
	}
}

//屏蔽禁语
//上单 你是SB SB SB
//上单 你是** ** **
void test11()
{
	char buf[1024] = { 0 };
	fgets(buf, sizeof(buf), stdin);
	//buf \n 变成 \0
	buf[strlen(buf) - 1] = '\0';
	char* p = buf;	//创建临时指针遍历字符串

	while (1)
	{
		//上单 你是sb sb sb
		char* ret = strstr(p, "sb");	//直接修改临时的字符串指针来做处理
		if (ret != NULL)
		{
			//找到了禁语的情况
			strncpy(ret, "**", 2);	//利用字符串拷贝来替换掉屏蔽词
			p = ret + 2;	//找到后再偏移两位
		}
		else
		{
			break;
		}
	}
	printf("%s\n", buf);
}

//test11 优化
void test12()
{
	char buf[1024] = { 0 };
	fgets(buf, sizeof(buf), stdin);
	//buf \n 变成 \0
	buf[strlen(buf) - 1] = '\0';
	char* p = buf;	//创建临时指针遍历字符串

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
//来将字符串分割成一个个片段,连续出现多个时只替换第一个为\0
void test13()
{
	static char buf[1024] = "张三:李四:王五:哈哈:呵呵";
	//数组中每个内容都是指针
	char* names[64] = { 0 };
	//分割哪个数组，分割依据是什么
	//char* name1 = strtok(buf, ":"); //第一次分割
	//printf("%s\n", name1);
	//name1 = strtok(NULL, ":"); //从第二次分割开始  参数1用NULL
	//printf("%s\n", name1);

	int i = 0;	//数组下标
	names[i] = strtok(buf, ":");
	//当分割不为第一次时 就进入循环
	while (names[i] != NULL)
	{
		i++;
		//分割后的值存入数组中
		names[i] = strtok(NULL, ":");
	}
	//数组遍历打印
	i = 0;
	while (names[i] != NULL)
	{
		printf("%s\n", names[i++]);
	}
}

//test13优化
void test14()
{
	static char buf[1024] = "张三:李四:王五:哈哈:呵呵";
	char* names[64] = { buf,NULL };

	int i = 0;
	//直接判断分割的结果是否有值
	//i=0 buf 分割出第一个names[0]  之后i=1  null names[1]....

	while ((names[i++] = strtok(names[i],":")) != NULL) 
	{
		//i++; //i++可以写到上面条件中
	}

	//数组遍历打印
	i = 0;
	while (names[i] != NULL)
	{
		printf("%s\n", names[i++]);
	}
}

//多种分割标识
void test15()
{
	char buf[1024] = "haha?hehe:lalla###xixi**!!aa";
	char* words[64] = { buf,NULL };
	int i = 0;
	while ((words[i++] = strtok(words[i],"?#:*!")) != NULL){}

	//数组遍历打印
	i = 0;
	while (words[i] != NULL)
	{
		printf("%s\n", words[i++]);
	}
}

//atoi() 字符串转换为数字
//	int atoi(const char *nptr);
//atoi()会扫描nptr字符串，跳过前面的空格字符，直到遇到数字或正负号才开始做转换

//atof()：把一个小数形式的字符串转化为一个浮点数。
//atol()：将一个字符串转化为 long 类型
void test16()
{
	int num = 0;
	char buf[] = "321abc123";
	num = atoi(buf);
	printf("num = %d\n", num);	//321

	//sscanf也可以做到   格式化信息 第一个匹配失败 就结束匹配
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


