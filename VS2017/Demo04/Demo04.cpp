
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#include <process.h>
#include <Windows.h>


//声明可以多个 定义只有一个
//int a;//声明
//int a;//声明
//int b = 10;//全局变量 赋值就是定义
//int b = 10;//重复定义
#define N 10
const int num = 10;

int main(int argc, char *argv[]) {

	void *p1 = malloc(10);
	void *p2 = malloc(20);

	printf("栈：&p1=%p\n", &p1);
	printf("栈：&p2=%p\n", &p2);
	printf("堆： p1=%p\n", p1);
	printf("堆： p2=%p\n", p2);

	int *pint1 = (int*)malloc(sizeof(int));
	int *pint2 = (int*)malloc(sizeof(int));

	printf("栈：&pint1=%p\n", &pint1);
	printf("栈：&pint2=%p\n", &pint2);
	printf("堆： pint1=%p\n", pint1);
	printf("堆： pint2=%p\n", pint2);

	//int data[N];
	//int data[num];
	//int *pnum = &num;
	//const int *pcnum = &num;
	//int *pnum = (int*)pcnum;
	//*pnum = 100;//低版本编译器 可以运行 ， VS2017 抛异常
	//printf("num=%d\n", num);

	//printf("%d\n", a);
	int inuma = 4;
	printf("%d,%d\n", inuma, ++inuma);
	system("pause");
	return 0;
}