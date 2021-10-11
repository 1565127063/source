#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)	
#pragma warning(disable:6031)
#define _CRT_SECURE_NO_WARNINGS
#include <time.h>

struct Hero
{
	char name[64];	//����
	int atk;	//������
	int def;	//������
};

//fprintf��ʹ�� ����ʽд�ļ�
void test1()
{
	struct Hero heroArray[5] =
	{
		{"����",1000,1000},
		{"����",1800,800},
		{"�ܲ�",1400,900},
		{"����",2000,900},
		{"�ŷ�",1600,1300}
	};

	FILE * f_write = fopen("test.txt", "w");
	if (NULL == f_write)
	{
		printf("�ļ���ʧ��\n");
		return;
	}
	int len = sizeof(heroArray) / sizeof(struct Hero);
	for (int  i = 0; i < len; i++)
	{
		fprintf(f_write, "[����]%s [������]%d [������]%d\n", heroArray[i].name, heroArray[i].atk, heroArray[i].def);
		
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
		printf("��ʧ��\n");
		return;
	}
	for (int i = 0; i < sizeof(arrHero) / sizeof(struct Hero); i++)
	{
		fprintf(f_write, "[����]%s %d %d\n", arrHero[i].name, arrHero[i].atk, arrHero[i].def);
	}
	fclose(f_write);
}

//fscanf ����ʽ���ļ�
void test3()
{
	FILE* f_read = fopen("test.txt", "r");
	if (f_read == NULL)
	{
		printf("��ʧ��\n");
		return;
	}
	struct Hero heroArray[5];
	//�������
	memset(heroArray, 0, sizeof(heroArray));
	int	i = 0;
	while (!feof(f_read))	//û�ж�ȡ���ļ�βִ��ѭ�� 
	{
		fscanf(f_read, "[����]%s [������]%d [������]%d\n",heroArray[i].name,heroArray[i].atk,heroArray[i].def);
		i++;
	}
	int len = sizeof(heroArray) / sizeof(struct Hero);
	for (int  i = 0; i < len; i++)
	{
		printf("name = %s atk =%d def= %d\n", heroArray[i].name, heroArray[i].atk, heroArray[i].def);
	}
	//�ر��ļ�
	fclose(f_read);
}

//fwrite ����д�ļ�
void test4()
{
	FILE* f_write = fopen("test4.txt", "w");
	if (f_write == NULL)
	{
		printf("��ʧ��\n");
		return;
	}

	struct Hero heroArray[5] =
	{
		{"����",1000,1000},
		{"����",1800,800},
		{"�ܲ�",1400,900},
		{"����",2000,900},
		{"�ŷ�",1600,1300}
	};

	int len = sizeof(heroArray) / sizeof(struct Hero);
	for (int i = 0; i < len; i++)
	{
		//�����д�ļ�
		//����1 ���ݵĵ�ַ  ����2 ��Ĵ�С ����3��ĸ���  ����4  �ļ�ָ��
		fwrite(&heroArray[i], sizeof(struct Hero),1,f_write);
		//���±����޷������ṹ�� 
	}
	fclose(f_write);
}

//fread ������ļ�
void test5()
{
	FILE* f_read = fopen("test4.txt", "r");
	if (f_read == NULL)
	{
		printf("��ʧ��\n");
		return;
	}
	struct Hero heroArray[5];	//�ж϶�ȡ�������� 
	
	memset(heroArray, 0, sizeof(heroArray));//�������
	int len = sizeof(heroArray) / sizeof(struct Hero);
#if 0
	for (int i = 0; i < len; i++)
	{
		//����1 ���ݵĵ�ַ  ����2 ��Ĵ�С ����3��ĸ���  ����4  �ļ�ָ��
		fread(&heroArray[i], sizeof(struct Hero), 1, f_read);
	}
#else
	//ֻ��Ҫ����������׵�ַ
	fread(heroArray, sizeof(struct Hero), 5, f_read);
#endif

	for (int i = 0; i < len; i++)
	{
		printf("name = %s atk =%d def= %d\n", heroArray[i].name, heroArray[i].atk, heroArray[i].def);
	}
	//�ر��ļ�
}

//ð������
void bubbleSort(int arr[], int len)
{
	for (int  i = 0; i < len; i++)
	{
		for (int j = 0; j < len-i-1; j++)
		{
			//����
			if (arr[j] > arr[j+1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

//�ļ������� 100������� ��������
#define NUM 100
void test6()
{
	srand((unsigned int)time(NULL));
	FILE* f_write = fopen("�����.txt", "w");
	if (f_write == NULL)
	{
		printf("��ʧ��\n");
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
	FILE* fp1 = fopen("�����.txt", "r");
	FILE* fp2 = fopen("�����.txt", "w");
	if (fp1 == NULL && fp2 == NULL)
	{
		printf("��ʧ��\n");
		return;
	}

	//׼��������100�������
	int arr[NUM] = {0};
	for (int i = 0; i < NUM; i++)
	{
		fscanf(fp1, "%d\n", &arr[i]);
	}
	//����������
	bubbleSort(arr, NUM);
	//������������д�뵽fp2���ļ���
	for (int i = 0; i < NUM; i++)
	{
		fprintf(fp2, "%d\n", arr[i]);
	}
	fclose(fp1);
	fclose(fp2);
}

//�ļ��������д fseek() �ļ�ָ�� λ���� �������ƶ�
void test8()
{
	FILE* fp1 = fopen("test8.txt", "w+");
	if (fp1 == NULL)
	{
		printf("��ʧ��\n");
		return;
	}
	//����д�ļ�
	fputs("hello world", fp1);
#if 0
	fclose(fp1);
	//�رպ����´�
	fp1 = fopen("test8.txt", "r");
#else
	//���ļ��Ĺ������  ��סSEEK_
	#if 0
	fseek(fp1, 0, SEEK_SET);	//0��ƫ���� ��ʼλ��
	#endif // 0
	fseek(fp1,-11,SEEK_END);	//�ӽ�β��ƫ�Ƶ���ͷ -11
	//����ʹ��rewind()����
	//rewind(fp1); 
	//fseek(fp1,0,SEEK_END);
	//fseek(fp1, -5, SEEK_CUR);  //��ǰλ���ƶ�  
#endif
	char buf[1024] = { 0 };
	fgets(buf, sizeof(buf), fp1);
	printf("%s\n", buf);
}

//ftell ��ȡ�ļ������ļ���꣩�Ķ�дλ��
void test9()
{
	FILE* fp = fopen("test8.txt", "r");
	if (fp == NULL)
	{
		printf("��ʧ��\n");
		return;
	}
	//�ƶ���굽�ļ�β
	fseek(fp, 0, SEEK_END);

	long len = ftell(fp);
	printf("%ld\n", len);	//�ļ���С  11�ֽ�

	//���ļ������ݶ�ȡ������������һ����������

	char * p = malloc(len + 1);	// ��������ռ� Ԥ��/0
	memset(p, 0, len + 1);//����ڴ�
	rewind(fp);	//���������

	//����1 ���ݵĵ�ַ  ����2 ��Ĵ�С ����3��ĸ���  ����4  �ļ�ָ��
	fread(p, len, 1, fp); //���������
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
