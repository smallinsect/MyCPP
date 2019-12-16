#include <stdio.h>
#include <stdlib.h>

#include <limits.h>


void run(const char *p[5]) {//数组 没有赋本机制
	printf("run=%d\n", sizeof(p));
	puts("*************二级指针访问******************");
	for (const char **i = p; i < p + 5; ++i) {
		puts(*i);
	}
	puts("*************二级指针访问******************");
}

int main(int argc, char *argv[]) {

	const char *str[5] = {"小昆虫1", "小昆虫2", "小昆虫3", "小昆虫4", "小昆虫5"};

	puts("*************数组访问******************");
	for (int i = 0; i < 5; ++i) {
		puts(str[i]);
	}
	puts("*************数组访问******************");
	puts("");
	puts("*************指针加下标访问******************");
	for (int i = 0; i < 5; ++i) {
		puts(*(str + i));
	}
	puts("*************指针加下标访问******************");
	puts("");
	puts("*************二级指针访问******************");
	for (const char **i = str; i < str + 5; ++i) {
		puts(*i);
	}
	puts("*************二级指针访问******************");

	printf("main=%d\n", sizeof(str));
	run(str);

	system("pause");
	return 0;
}