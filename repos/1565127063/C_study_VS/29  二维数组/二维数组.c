#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS

//���巽ʽ1 ����˵���� ������[�������ʽ 1][�������ʽ 2]
void test1()
{
	int arr[2][3];
	arr[0][0] = 0;
	arr[0][1] = 1;
	arr[0][2] = 2;
	arr[1][0] = 3;
	arr[1][1] = 4;
	arr[1][2] = 5;
	for (int  i = 0; i < 2; i++)
	{
		for (int  j = 0; j < 3; j++)
		{
			printf("%d ",arr[i][j]);
		}
		printf("\n");	//����λ�úܹؼ� ����i
	}
}

//��ʽ2 �Ƽ�ʹ��2
void test2()
{
	int arr2[2][3] =
	{
	{1, 2, 3},
	{2, 3, 4}	//���һ�� ������ʡ��
	};

	//���巽ʽ3
	int arr3[2][3] = { 1, 2, 3, 4, 5 ,6 };

	//���巽ʽ4
	int arr4[][3] = { 1, 2, 3, 4, 5 ,6, 7 };//ֻ��ʡ������ ����������ʡ��

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d ", arr4[i][j]);	// �Զ�����7 0 0
		}
		printf("\n");
	}
}

//�ɲ鿴��Ϣ
void test3()
{
	int arr2[2][3] =
	{
	{1, 2, 3},
	{2, 3, 4}	//���һ�� ������ʡ��
	};
	//sizeof(arr) ͳ������������ַ���С
	printf("%d\n",sizeof(arr2));	//24 
	printf("%d\n", sizeof(arr2[0]));	//��ά����һ�е��ַ���С
	printf("%d\n", sizeof(arr2[0][0]));	//��ά�����һ�����ַ���С

	//ͳ�ƶ�ά����� ���� ����
	printf("��ά��������� = %d\n", sizeof(arr2) / sizeof(arr2[0])); //����
	printf("��ά��������� = %d\n", sizeof(arr2[0]) / sizeof(arr2[0][0])); //����

	//��ӡ�׵�ַ
	printf("��ά������׵�ַ%d\n",&arr2);			//18086416
	printf("��ά����ĵ�һ���׵�ַ%d\n", &arr2[0]); //18086416
	printf("��ά����ĵ�һ���׵�ַ%d\n", &arr2[1]); //18086428
	printf("��ά����ĵ�һ��Ԫ���׵�ַ%d\n", &arr2[0][0]); //18086416
	printf("��ά����ĵ�һ��Ԫ���׵�ַ%d\n", &arr2[0][1]); //18086420
	//��ά���鱾��Ҳ��һά����
}

//��������
void test4()
{
	int source[3][3] =
	{
		{100,70,100},
		{90,80,94},
		{94,86,93}
	};

	char name[3][10] = { "����", "����", "����"};

	//��ӡÿ���˵��ܳɼ�
	int row = sizeof(source) / sizeof(source[0]);
	int col = sizeof(source[0]) / sizeof(source[0][0]);
	for (int  i = 0; i < row; i++)
	{
		int sum = 0;
		for (int  j = 0; j < col; j++)
		{
			sum += source[i][j];
			//printf("%d\n",sum);
		}
		//printf("��%d��ͬѧ�ܷ�Ϊ%d ƽ����Ϊ%d\n",i+1,sum,sum / col);
		printf("%sͬѧ�ܷ�Ϊ%d ƽ����Ϊ%d\n", name[i], sum, sum / col);
	}
}

int main()
{

	test4();

	system("pause");
	return EXIT_SUCCESS;
}