
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#include <process.h>
#include <Windows.h>


//�������Զ�� ����ֻ��һ��
//int a;//����
//int a;//����
//int b = 10;//ȫ�ֱ��� ��ֵ���Ƕ���
//int b = 10;//�ظ�����
#define N 10
const int num = 10;

int main(int argc, char *argv[]) {

	void *p1 = malloc(10);
	void *p2 = malloc(20);

	printf("ջ��&p1=%p\n", &p1);
	printf("ջ��&p2=%p\n", &p2);
	printf("�ѣ� p1=%p\n", p1);
	printf("�ѣ� p2=%p\n", p2);

	int *pint1 = (int*)malloc(sizeof(int));
	int *pint2 = (int*)malloc(sizeof(int));

	printf("ջ��&pint1=%p\n", &pint1);
	printf("ջ��&pint2=%p\n", &pint2);
	printf("�ѣ� pint1=%p\n", pint1);
	printf("�ѣ� pint2=%p\n", pint2);

	//int data[N];
	//int data[num];
	//int *pnum = &num;
	//const int *pcnum = &num;
	//int *pnum = (int*)pcnum;
	//*pnum = 100;//�Ͱ汾������ �������� �� VS2017 ���쳣
	//printf("num=%d\n", num);

	//printf("%d\n", a);
	int inuma = 4;
	printf("%d,%d\n", inuma, ++inuma);
	system("pause");
	return 0;
}