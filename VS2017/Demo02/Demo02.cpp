#include <stdio.h>
#include <stdlib.h>

#include <limits.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

#include <windows.h>


int main(int argc, char *argv[]) {
	//#不可以出现在变量命名中
	//$可以出现在变量命名中
	//int #abc1234 = 3;
	//int $hello = 1;

	//变量命名区分大小写
	int abc = 5;
	int ABC = 6;

	//不能用C语言关键字作为变量名

	int scanf = 10;
	printf("%d\n", scanf);

	puts("hello world");

	printf("sizeof char     = %d\n", sizeof(char));
	printf("sizeof short    = %d\n", sizeof(short));
	printf("sizeof int      = %d\n", sizeof(int));
	printf("sizeof float    = %d\n", sizeof(float));
	printf("sizeof double   = %d\n", sizeof(double));
	printf("sizeof long     = %d\n", sizeof(long));
	printf("sizeof long long= %d\n", sizeof(long long));

	int *arr = (int*)malloc(100000000*sizeof(int));

	printf("%X\n", 0xf & 1);

	//char *str1 = "hello";//"hello"属于字符常量，存储在只读栈区。
	//char str2[] = "hello";//属于栈区

	printf("%s\n", strchr("hello wolrd", 'w'));

	char str[] = "hello wolrd";
	printf("%s\n", strstr(str, "wo"));

	system("pause");
	return 0;
}