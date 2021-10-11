#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)	
#pragma warning(disable:6031)
#define _CRT_SECURE_NO_WARNINGS
#include <time.h>

struct Hero
{
	char name[64];	//名字
	int atk;	//攻击力
	int def;	//防御力
};

//fprintf的使用 按格式写文件
void test1()
{
	struct Hero heroArray[5] =
	{
		{"刘备",1000,1000},
		{"关羽",1800,800},
		{"曹操",1400,900},
		{"吕布",2000,900},
		{"张飞",1600,1300}
	};

	FILE * f_write = fopen("test.txt", "w");
	if (NULL == f_write)
	{
		printf("文件打开失败\n");
		return;
	}
	int len = sizeof(heroArray) / sizeof(struct Hero);
	for (int  i = 0; i < len; i++)
	{
		fprintf(f_write, "[姓名]%s [攻击力]%d [防御力]%d\n", heroArray[i].name, heroArray[i].atk, heroArray[i].def);
		
	}

	fclose(f_write);
}
void test2()
{
	struct Hero arrHero[5] =
	{
		{"111",111,11},
		{"222",222,22},
		{"333",444,44},
		{"444",333,33},
		{"555",444,55},
	};

	FILE* f_write = fopen("1.txt", "w");
	if (f_write == NULL)
	{
		printf("打开失败\n");
		return;
	}
	for (int i = 0; i < sizeof(arrHero) / sizeof(struct Hero); i++)
	{
		fprintf(f_write, "[名字]%s %d %d\n", arrHero[i].name, arrHero[i].atk, arrHero[i].def);
	}
	fclose(f_write);
}

//fscanf 按格式读文件
void test3()
{
	FILE* f_read = fopen("test.txt", "r");
	if (f_read == NULL)
	{
		printf("打开失败\n");
		return;
	}
	struct Hero heroArray[5];
	//清空数组
	memset(heroArray, 0, sizeof(heroArray));
	int	i = 0;
	while (!feof(f_read))	//没有读取到文件尾执行循环 
	{
		fscanf(f_read, "[姓名]%s [攻击力]%d [防御力]%d\n",heroArray[i].name,heroArray[i].atk,heroArray[i].def);
		i++;
	}
	int len = sizeof(heroArray) / sizeof(struct Hero);
	for (int  i = 0; i < len; i++)
	{
		printf("name = %s atk =%d def= %d\n", heroArray[i].name, heroArray[i].atk, heroArray[i].def);
	}
	//关闭文件
	fclose(f_read);
}

//fwrite 按块写文件
void test4()
{
	FILE* f_write = fopen("test4.txt", "w");
	if (f_write == NULL)
	{
		printf("打开失败\n");
		return;
	}

	struct Hero heroArray[5] =
	{
		{"刘备",1000,1000},
		{"关羽",1800,800},
		{"曹操",1400,900},
		{"吕布",2000,900},
		{"张飞",1600,1300}
	};

	int len = sizeof(heroArray) / sizeof(struct Hero);
	for (int i = 0; i < len; i++)
	{
		//按块读写文件
		//参数1 数据的地址  参数2 快的大小 参数3块的个数  参数4  文件指针
		fwrite(&heroArray[i], sizeof(struct Hero),1,f_write);
		//记事本打开无法解析结构体 
	}
	fclose(f_write);
}

//fread 按块读文件
void test5()
{
	FILE* f_read = fopen("test4.txt", "r");
	if (f_read == NULL)
	{
		printf("打开失败\n");
		return;
	}
	struct Hero heroArray[5];	//判断读取到哪里了 
	
	memset(heroArray, 0, sizeof(heroArray));//清空数组
	int len = sizeof(heroArray) / sizeof(struct Hero);
#if 0
	for (int i = 0; i < len; i++)
	{
		//参数1 数据的地址  参数2 快的大小 参数3块的个数  参数4  文件指针
		fread(&heroArray[i], sizeof(struct Hero), 1, f_read);
	}
#else
	//只需要放入数组的首地址
	fread(heroArray, sizeof(struct Hero), 5, f_read);
#endif

	for (int i = 0; i < len; i++)
	{
		printf("name = %s atk =%d def= %d\n", heroArray[i].name, heroArray[i].atk, heroArray[i].def);
	}
	//关闭文件
}

//冒泡排序
void bubbleSort(int arr[], int len)
{
	for (int  i = 0; i < len; i++)
	{
		for (int j = 0; j < len-i-1; j++)
		{
			//升序
			if (arr[j] > arr[j+1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

//文件版排序 100个随机数 进行排序
#define NUM 100
void test6()
{
	srand((unsigned int)time(NULL));
	FILE* f_write = fopen("随机数.txt", "w");
	if (f_write == NULL)
	{
		printf("打开失败\n");
		return;
	}
	for (int i = 0; i < NUM; i++)
	{
		fprintf(f_write, "%d\n", rand() % 1000 + 1);//1~1000
	}
	fclose(f_write);
}
void test7()
{
	FILE* fp1 = fopen("随机数.txt", "r");
	FILE* fp2 = fopen("排序后.txt", "w");
	if (fp1 == NULL && fp2 == NULL)
	{
		printf("打开失败\n");
		return;
	}

	//准备数组存放100个随机数
	int arr[NUM] = {0};
	for (int i = 0; i < NUM; i++)
	{
		fscanf(fp1, "%d\n", &arr[i]);
	}
	//给数组排序
	bubbleSort(arr, NUM);
	//将排序后的数组写入到fp2的文件中
	for (int i = 0; i < NUM; i++)
	{
		fprintf(fp2, "%d\n", arr[i]);
	}
	fclose(fp1);
	fclose(fp2);
}

//文件的随机读写 fseek() 文件指针 位移数 从哪里移动
void test8()
{
	FILE* fp1 = fopen("test8.txt", "w+");
	if (fp1 == NULL)
	{
		printf("打开失败\n");
		return;
	}
	//按行写文件
	fputs("hello world", fp1);
#if 0
	fclose(fp1);
	//关闭后重新打开
	fp1 = fopen("test8.txt", "r");
#else
	//将文件的光标置首  记住SEEK_
	#if 0
	fseek(fp1, 0, SEEK_SET);	//0是偏移量 起始位置
	#endif // 0
	fseek(fp1,-11,SEEK_END);	//从结尾处偏移到开头 -11
	//或者使用rewind()函数
	//rewind(fp1); 
	//fseek(fp1,0,SEEK_END);
	//fseek(fp1, -5, SEEK_CUR);  //当前位置移动  
#endif
	char buf[1024] = { 0 };
	fgets(buf, sizeof(buf), fp1);
	printf("%s\n", buf);
}

//ftell 获取文件流（文件光标）的读写位置
void test9()
{
	FILE* fp = fopen("test8.txt", "r");
	if (fp == NULL)
	{
		printf("打开失败\n");
		return;
	}
	//移动光标到文件尾
	fseek(fp, 0, SEEK_END);

	long len = ftell(fp);
	printf("%ld\n", len);	//文件大小  11字节

	//将文件的数据读取出来，并放入一个堆区数组

	char * p = malloc(len + 1);	// 申请堆区空间 预留/0
	memset(p, 0, len + 1);//清空内存
	rewind(fp);	//将光标置首

	//参数1 数据的地址  参数2 快的大小 参数3块的个数  参数4  文件指针
	fread(p, len, 1, fp); //按快读数据
	printf("%s\n", p);

	if (p != NULL)
	{
		free(p);
		p = NULL;
	}
	fclose(fp);
}

int main()
{
	test9();
	system("pause");
	return EXIT_SUCCESS;
}
