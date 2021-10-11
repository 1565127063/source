#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include<string.h>

#define DAY 7
void test1() {
	//常量在运行期间不可以修改的值
	//1.数值常量 100 200 3.14 1.1
	//2.字符常量  'a' 'b' '\n'
	//3.字符串常量	"hello!" "abc"
	//4.符号常量（宏常量）
		printf("一周的天数有%d天\n", DAY); 
			//DAY = 14;	常量无法更改
	//5.const修饰的变量
		const int month = 12;
		//month = 24;	const修饰后无法修改
		printf("一年一共有%d月\n",month);
}

int main() {
	
	test1();

	system("pause");
	return EXIT_SUCCESS;
}