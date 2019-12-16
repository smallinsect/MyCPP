#include <stdio.h>
#include <stdlib.h>

#include <limits.h>


void run(const char *p[5]) {//���� û�и�������
	printf("run=%d\n", sizeof(p));
	puts("*************����ָ�����******************");
	for (const char **i = p; i < p + 5; ++i) {
		puts(*i);
	}
	puts("*************����ָ�����******************");
}

int main(int argc, char *argv[]) {

	const char *str[5] = {"С����1", "С����2", "С����3", "С����4", "С����5"};

	puts("*************�������******************");
	for (int i = 0; i < 5; ++i) {
		puts(str[i]);
	}
	puts("*************�������******************");
	puts("");
	puts("*************ָ����±����******************");
	for (int i = 0; i < 5; ++i) {
		puts(*(str + i));
	}
	puts("*************ָ����±����******************");
	puts("");
	puts("*************����ָ�����******************");
	for (const char **i = str; i < str + 5; ++i) {
		puts(*i);
	}
	puts("*************����ָ�����******************");

	printf("main=%d\n", sizeof(str));
	run(str);

	system("pause");
	return 0;
}