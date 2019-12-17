
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

int main(int argc, char *argv[]) {

	//int(*p[4])(int a, int b) = { myadd, mysub, mymul, mydiv};
	//for (int i = 0; i < 4; ++i) {
	//	printf("%d\n", p[i](100, 20));
	//}

	printf("%s\n", getname(main));

	char **a;
	printf("%d\n", sizeof(a));

	system("pause");
	return 0;
}
