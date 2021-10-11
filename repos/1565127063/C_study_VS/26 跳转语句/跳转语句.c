#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS

//break
//1.switch句中，终止某个case并跳出switch结构。
//2.循环语句中，跳出当前内循环语句，执行后面代码
//3.嵌套循环中，跳出最近的内循环语句，执行后面代码
void test1()
{
	//i控制的行数
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)	//j控制的列数
		{
			if (j == 5)
			{
				break;
			}
			printf("*");
		}
		printf("\n");
	}
}
//2.continue 终止本次循环，并执行下一次循环
void test2()
{
	//过滤偶数
	for (int i = 0; i < 100; i++)
	{
		if (i % 2 == 0)
		{
			continue;
			//break； 不同 只执行一次循环
		}
		printf("%d\r\n", i);
	}

}
//go to 不建议使用
void test3()
{
	printf("hello1\n");
	printf("hello2\n");

	goto FLAG;

	printf("hello3\n");
	printf("hello4\n");
	printf("hello5\n");
FLAG:
	printf("hello6\n");
	printf("hello7\n");
}

int main()
{
	test1();
	test2();
	test3();
	system("pause");
	return EXIT_SUCCESS;
}
