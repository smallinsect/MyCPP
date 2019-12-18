
#include <stdio.h>
#include <stdlib.h>

#include <limits.h>
#include <iostream>
using namespace std;

int myadd(int a, int b) {
	return a + b;
}
int mysub(int a, int b) {
	return a - b;
}
int mymul(int a, int b) {
	return a * b;
}
int mydiv(int a, int b) {
	return a / b;
}

#define getname(x) #x


void myswap(void* v1, void* v2, size_t size) {
	char* ch1 = (char*)v1;
	char* ch2 = (char*)v2;
	while (size--) {
		char temp = *ch1;
		*ch1 = *ch2;
		*ch2 = temp;
		ch1++;
		ch2++;
	}
}

int mymax(int a[3][4]) {
	cout << sizeof(a) << endl;
	return 0;
}
int mymaxA(int *a[4]) {
	cout << sizeof(a) << endl;
	return 0;
}

int main(int argc, char *argv[]) {

	//int(*p[4])(int a, int b) = { myadd, mysub, mymul, mydiv};
	//for (int i = 0; i < 4; ++i) {
	//	printf("%d\n", p[i](100, 20));
	//}

	//printf("%s\n", getname(main));

	//char **a;
	//printf("%d\n", sizeof(a));

	//int *p = (int*)malloc(10*sizeof(int));

	//int *newp = (int*)realloc(p, 20*sizeof(int));

	//int a = 10, b = 20;
	//cout << a << " " << b << endl;
	//myswap(&a, &b, sizeof(int));
	//cout << a << " " << b << endl;

	//const char* str1 = "hello";
	//const char* str2 = "worl";
	//cout << str1 << " " << str2 << endl;
	//myswap(&str1, &str2, sizeof(char*));
	//cout << str1 << " " << str2 << endl;

	//int a[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 2};
	////mymax(a);
	////mymaxA(NULL);
	//printf("%d\n", **a);
	//printf("%p\n", *a+1);
	//printf("%p\n", a+1);
	//printf("%p\n", &a + 1);

	int a = 10;
	int b = 20;

	//const int *p = &a;//常量指针 指向常量的指针 数据只读，地址可移动，可以看别人的信息
	int const *p = &a;//常量指针 指针是常量

	//int * const p = &a;//指针常量 指针是常量 数据可读可写
	//const int* const p;//常量指针常量 数据 数据只读，不可写，只限定看自己数据
	//int const* const p;

	//*p = 20;
	//p = &b;

	system("pause");
	return 0;
}
