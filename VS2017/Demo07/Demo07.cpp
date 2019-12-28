
#include <stdio.h>
#include <stdlib.h>

#include <windows.h>

#include <limits.h>
#include <iostream>
#include <afx.h>
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

class A {
public:
	//A() = delete;
	A(const A& a);
	A& operator=(const A& a) {
		return *this;
	}
private:
	//A();
public:
	//virtual void funA() {}
	static int a;
};

int A::a = 10;

class B {
public:
	virtual void funB() {}
};

class C {
public:
	virtual void funC() {}
};

class D : public A, public B, public C {
public:
	//virtual void funA() {}
	virtual void funB() {}
	virtual void funC() {}
};

class E : public D, public B {
public:
};

class F {
public:
	F() {
		cout << "F()" << endl;
	}
	~F() {
		cout << "~F()" << endl;
	}
};

int main(int argc, char *argv[]) 
{

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

	//int a = 10;
	//int b = 20;

	//const int *p = &a;//常量指针 指向常量的指针 数据只读，地址可移动，可以看别人的信息
	//int const *p = &a;//常量指针 指针是常量

	//int * const p = &a;//指针常量 指针是常量 数据可读可写
	//const int* const p;//常量指针常量 数据 数据只读，不可写，只限定看自己数据
	//int const* const p;

	//*p = 20;
	//p = &b;

	//int *p = (int*)malloc(40*sizeof(int));
	////数组指针
	//int(*pp)[10] = (int(*)[10])p;
	//printf("%d\n", sizeof(pp));
	////指针数组
	//int *pp1[10];
	//printf("%d\n", sizeof(pp1));

	//获取文件大小
	//获取文件内容行数

	//char str[100] = "for /l %i in (1,1,5) do calc";
	//const char *p = "for /l %i in (1,1,5) do calc";

	//cout << sizeof(A) << endl;
	//cout << sizeof(B) << endl;
	//cout << sizeof(C) << endl;
	//cout << sizeof(D) << endl;
	//cout << sizeof(E) << endl;

	//F *a = new F();
	//free(a);
	//a = (F*)malloc(sizeof(F));
	//delete a;

	//cout << sizeof(long double) << endl;

	//wchar_t ch = '我';//汉字字符
	//const wchar_t *pch = L"呵呵呵呵";
	//setlocale(LC_ALL, "zh-CN");//设定中文
	//wprintf(L"%lc", ch);
	//wprintf(L"%ls", pch);
	//putwchar(ch);
	//_putws(pch);

	//FILE *fp;

	//stdin->_Placeholder;

	//A a;
	//cout << A::a << endl;
	//D::a = 11;
	//cout << A::a << endl;


	//三目运算符 两个操作符类型要一样
	//cout << (true ? 1 : "1") << endl;

	//unsigned int const size = 100;
	//char str1[size];

	//A* a = new A();

	//CFile file(TEXT("C:\\1.txt"), CFile::modeRead);


	system("pause");
	return 0;
}
