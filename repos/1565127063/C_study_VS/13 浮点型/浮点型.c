#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS

//�����ͳ�������Ҫ�ڸ����ͳ����м�ӿո�
//���ſ���ʡ�ԡ� ����û��С���㣨�磬 2E5�� ��ָ�����֣��磬19.28�������ǲ���ͬʱʡ�����ߡ�
void test1() 
{
	printf("1.56E+12\n");
	printf("2.87e-3\n");
	printf("sizeof 3.14=%d\n", sizeof(3.14));  //Ĭ��С����double 8
	printf("sizeof 3.14 f =%d\n", sizeof(3.14f)); //���+f���float 4
}
//�����ͱ��� 
void test2() {
	float a = 3.1415f;
	printf("a= %f\n", a); //%f ����6λС��
	printf("a= %.2f\n", a); //%.2f ����2λС��
	printf("sizeof a=%d\n", sizeof(a));

	double b = 3.1415;
	printf("b= %lf\n", b); //%lf double�εı�ʾ
	printf("b= %.3lf\n", b); //%.3lf double ���������룩
	printf("sizeof b=%d\n", sizeof(b));

	float PI = 3.1415926358;
	printf("PI= %.10f\n", PI);
	double PI2 = 3.1415926358;
	printf("PI2 = %.10f\n", PI2);

	//��ѧ������
	float f1 = 3e2;		//3*10^2
	printf("f1 = %.10f\n", f1);
	float f2 = 3e-2;	//3*10^(-2��
	printf("f1 = %f\n", f2);
}


int main() {

	test1();
	test2();
	system("pause");
	return EXIT_SUCCESS;
}