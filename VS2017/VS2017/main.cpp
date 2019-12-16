#include <stdio.h>
#include <stdlib.h>

#include <limits.h>

int main(int argc, char *argv[]) {
	//puts("hello world");

	//int $hello = 1;

	//printf按照%d,%f解析，不是该类型，都不能解析。
	printf("%d\n", 10.3);
	printf("%lf\n", 10);

	//与数据长度有关系
	//unsigned short sh = 65535;//65535
	unsigned short sh = 65535+1;//0 数据溢出
	printf("%d\n", sh);

	short num = -1;
	printf("%d\n", num);
	printf("%u\n", num);
	system("pause");
	return 0;
}