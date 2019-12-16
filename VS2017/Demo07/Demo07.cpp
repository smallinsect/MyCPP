
#include <stdio.h>
#include <stdlib.h>

#include <limits.h>

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

int main(int argc, char *argv[]) {

	int(*p[4])(int a, int b) = { myadd, mysub, mymul, mydiv};
	for (int i = 0; i < 4; ++i) {
		printf("%d\n", p[i](100, 20));
	}

	system("pause");
	return 0;
}
